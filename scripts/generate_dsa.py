import os
import datetime
import random
import subprocess
import requests

# ---------------- CONFIG ---------------- #

TOPICS = ['arrays', 'strings', 'stack', 'queue', 'binary search', 'recursion', 'dp', 'trees']
LANGUAGES = ['cpp', 'py', 'java']

# Fallback templates (must be REAL code, never placeholders)
TEMPLATES = {
    'arrays': {
        'cpp': '''#include <bits/stdc++.h>
using namespace std;

// Find maximum element in an array
int findMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int x : arr) mx = max(mx, x);
    return mx;
}

int main() {
    vector<int> arr = {1, 5, 2, 9, 3};
    cout << "Max element: " << findMax(arr) << endl;
    return 0;
}''',

        'py': '''def find_max(arr):
    mx = arr[0]
    for x in arr:
        mx = max(mx, x)
    return mx

if __name__ == "__main__":
    arr = [1, 5, 2, 9, 3]
    print("Max element:", find_max(arr))''',

        'java': '''public class ArrayMax {
    static int findMax(int[] arr) {
        int mx = arr[0];
        for (int x : arr) mx = Math.max(mx, x);
        return mx;
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 2, 9, 3};
        System.out.println("Max element: " + findMax(arr));
    }
}'''
    },

    'stack': {
        'cpp': '''#include <bits/stdc++.h>
using namespace std;

// Valid Parentheses
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c=='('||c=='['||c=='{') st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if ((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string s="()[]{}";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}''',

        'py': '''def is_valid(s):
    st=[]
    mp={')':'(',']':'[','}':'{'}
    for c in s:
        if c in mp:
            if not st or st.pop()!=mp[c]:
                return False
        else:
            st.append(c)
    return not st

if __name__=="__main__":
    s="()[]{}"
    print("Valid" if is_valid(s) else "Invalid")''',

        'java': '''import java.util.*;

public class ValidParentheses {
    static boolean isValid(String s) {
        Stack<Character> st=new Stack<>();
        for(char c:s.toCharArray()){
            if(c=='('||c=='['||c=='{') st.push(c);
            else{
                if(st.isEmpty()) return false;
                char t=st.pop();
                if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))
                    return false;
            }
        }
        return st.isEmpty();
    }

    public static void main(String[] args){
        System.out.println(isValid("()[]{}") ? "Valid" : "Invalid");
    }
}'''
    }
}

# ---------------- HELPERS ---------------- #

def get_file_extension(lang):
    return {'cpp': 'cpp', 'py': 'py', 'java': 'java'}[lang]

def build_filename(topic, lang, date_str):
    safe_topic = topic.lower().replace(" ", "_")
    ext = get_file_extension(lang)
    return f"{safe_topic}_{lang}_{date_str}.{ext}"

def is_valid_code(code: str) -> bool:
    if not code:
        return False
    if len(code.strip()) < 200:
        return False
    bad = ["// Default", "# Default"]
    return not any(code.strip().startswith(b) for b in bad)

# ---------------- AI GENERATION ---------------- #

def generate_code_with_ai(topic, lang, api_key):
    prompt = f"""
Generate a COMPLETE and RUNNABLE {lang} program for a DSA problem on topic: {topic}

Rules:
- Full working code only
- No placeholders
- No TODO
- Must include:
  - problem description in comments
  - main function
  - example input & output
  - time complexity comment
"""
    try:
        r = requests.post(
            "https://api.groq.com/openai/v1/chat/completions",
            headers={
                "Authorization": f"Bearer {api_key}",
                "Content-Type": "application/json"
            },
            json={
                "model": "mixtral-8x7b-32768",
                "messages": [{"role": "user", "content": prompt}],
                "max_tokens": 1200,
                "temperature": 0.4
            },
            timeout=30
        )
        r.raise_for_status()
        return r.json()["choices"][0]["message"]["content"]
    except Exception as e:
        print("AI generation failed:", e)
        return None

def get_code(topic, lang):
    api_key = os.environ.get("GROQ_API_KEY")

    code = None
    if api_key:
        code = generate_code_with_ai(topic, lang, api_key)

    if not code or not is_valid_code(code):
        code = TEMPLATES.get(topic, {}).get(lang)

    if not code or not is_valid_code(code):
        raise RuntimeError(f"❌ Failed to generate valid code for {topic} in {lang}")

    return code

# ---------------- MAIN ---------------- #

def main():
    today = datetime.date.today().strftime("%Y-%m-%d")
    folder = f"codestudio/{today}"
    os.makedirs(folder, exist_ok=True)

    # Git identity
    subprocess.run(['git','config','user.name','github-actions[bot]'], check=True)
    subprocess.run(['git','config','user.email','github-actions[bot]@users.noreply.github.com'], check=True)

    # Pick 3 UNIQUE topics
    topics_today = random.sample(TOPICS, 3)

    generated_files = []

    for topic in topics_today:
        lang = random.choice(LANGUAGES)
        code = get_code(topic, lang)

        filename = build_filename(topic, lang, today)
        path = os.path.join(folder, filename)

        with open(path, "w", encoding="utf-8") as f:
            f.write(code)

        generated_files.append(path)

    # Update README log
    readme = "README.md"
    log = f"\n## {today}\n"
    for f in generated_files:
        log += f"- {os.path.basename(f)}\n"

    if os.path.exists(readme):
        with open(readme, "a", encoding="utf-8") as f:
            f.write(log)
    else:
        with open(readme, "w", encoding="utf-8") as f:
            f.write("# DSA Auto Commit Log\n" + log)

    # One clean commit
    subprocess.run(['git','add',folder], check=True)
    subprocess.run(['git','add',readme], check=True)
    subprocess.run(
        ['git','commit','-m',f'Add 3 DSA solutions for {today}'],
        check=True
    )

if __name__ == "__main__":
    main()
