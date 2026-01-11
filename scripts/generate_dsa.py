import os
import datetime
import random
import subprocess
import requests

# ================= CONFIG ================= #

TOPICS = ['arrays', 'strings', 'stack', 'queue', 'binary_search', 'recursion', 'dp', 'trees']
LANGUAGES = ['cpp', 'py', 'java']

# ================= SAFE FALLBACK CODE ================= #
# These are REAL, RUNNABLE programs.

SAFE_FALLBACK = {
    "arrays": {
        "py": """def find_max(arr):
    m = arr[0]
    for x in arr:
        m = max(m, x)
    return m

if __name__ == "__main__":
    arr = [1, 4, 2, 9, 3]
    print("Max:", find_max(arr))"""
    },

    "strings": {
        "py": """def reverse_string(s):
    return s[::-1]

if __name__ == "__main__":
    s = "hello"
    print("Reversed:", reverse_string(s))"""
    },

    "stack": {
        "cpp": """#include <bits/stdc++.h>
using namespace std;

bool valid(string s){
    stack<char> st;
    for(char c: s){
        if(c=='('||c=='['||c=='{') st.push(c);
        else{
            if(st.empty()) return false;
            char t = st.top(); st.pop();
            if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))
                return false;
        }
    }
    return st.empty();
}

int main(){
    cout << (valid("()[]{}") ? "Valid" : "Invalid");
    return 0;
}"""
    },

    "queue": {
        "cpp": """#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10); q.push(20); q.push(30);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}"""
    },

    "trees": {
        "java": """class Node{
    int v;
    Node l, r;
    Node(int v){ this.v=v; }
}

public class BinaryTree{
    static void inorder(Node n){
        if(n==null) return;
        inorder(n.l);
        System.out.print(n.v + " ");
        inorder(n.r);
    }

    public static void main(String[] args){
        Node root = new Node(1);
        root.l = new Node(2);
        root.r = new Node(3);
        inorder(root);
    }
}"""
    },

    "binary_search": {
        "cpp": """#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int x){
    int l=0,r=a.size()-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==x) return m;
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(){
    vector<int>a={1,3,5,7,9};
    cout<<binarySearch(a,7);
    return 0;
}"""
    }
}

# ================= HELPERS ================= #

def get_ext(lang):
    return {"cpp": "cpp", "py": "py", "java": "java"}[lang]

def build_filename(topic, lang, date):
    return f"{topic}_{lang}_{date}.{get_ext(lang)}"

def is_valid(code):
    if not code:
        return False
    if len(code.strip()) < 100:
        return False
    return True

# ================= AI ================= #

def generate_with_ai(topic, lang, api_key):
    prompt = f"""
Generate a COMPLETE runnable {lang} program for DSA topic: {topic}.
Rules:
- Full code only
- Must include main
- No TODO
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
                "max_tokens": 900,
                "temperature": 0.3
            },
            timeout=20
        )
        r.raise_for_status()
        return r.json()["choices"][0]["message"]["content"]
    except Exception as e:
        print("AI failed:", e)
        return None

# ================= CORE ================= #

def get_code(topic, lang):
    api_key = os.environ.get("GROQ_API_KEY")

    # 1. Try AI
    if api_key:
        ai_code = generate_with_ai(topic, lang, api_key)
        if is_valid(ai_code):
            return ai_code

    # 2. Try safe fallback
    fallback = SAFE_FALLBACK.get(topic, {}).get(lang)
    if is_valid(fallback):
        return fallback

    # 3. Guaranteed last-resort generator
    return f"""// Auto fallback code
#include <bits/stdc++.h>
using namespace std;

int main(){{
    cout << "Topic: {topic}" << endl;
    cout << "Language: {lang}" << endl;
    return 0;
}}"""

# ================= MAIN ================= #

def main():
    today = datetime.date.today().strftime("%Y-%m-%d")
    folder = f"codestudio/{today}"
    os.makedirs(folder, exist_ok=True)

    # Git identity
    subprocess.run(["git", "config", "user.name", "github-actions[bot]"], check=True)
    subprocess.run(["git", "config", "user.email", "github-actions[bot]@users.noreply.github.com"], check=True)

    topics = random.sample(TOPICS, 3)
    files = []

    for topic in topics:
        lang = random.choice(LANGUAGES)
        code = get_code(topic, lang)

        fname = build_filename(topic, lang, today)
        path = os.path.join(folder, fname)

        with open(path, "w", encoding="utf-8") as f:
            f.write(code)

        files.append(path)

    # README update
    readme = "README.md"
    log = f"\n## {today}\n" + "\n".join(f"- {os.path.basename(f)}" for f in files)

    if os.path.exists(readme):
        with open(readme, "a", encoding="utf-8") as f:
            f.write(log)
    else:
        with open(readme, "w", encoding="utf-8") as f:
            f.write("# DSA Auto Commit Log\n" + log)

    # One clean commit
    subprocess.run(["git", "add", folder], check=True)
    subprocess.run(["git", "add", readme], check=True)
    subprocess.run(["git", "commit", "-m", f"Add 3 DSA solutions for {today}"], check=True)

if __name__ == "__main__":
    main()
