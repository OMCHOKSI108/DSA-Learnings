import os
import datetime
import random
import subprocess
import requests

# ---------------- CONFIG ---------------- #

TOPICS = ['arrays', 'strings', 'stack', 'queue', 'binary search', 'recursion', 'dp', 'trees']
LANGUAGES = ['cpp', 'py', 'java']

# ---------------- CORE TEMPLATES ---------------- #
# These are GUARANTEED fallbacks – every one is real code.

FALLBACKS = {
    "strings": {
        "py": '''def reverse_string(s):
    return s[::-1]

if __name__ == "__main__":
    s = "hello"
    print("Reversed:", reverse_string(s))'''
    },

    "queue": {
        "cpp": '''#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}'''
    },

    "trees": {
        "java": '''class Node {
    int val;
    Node left, right;
    Node(int v){ val=v; }
}

public class BinaryTree {
    static void inorder(Node root){
        if(root==null) return;
        inorder(root.left);
        System.out.print(root.val+" ");
        inorder(root.right);
    }

    public static void main(String[] args){
        Node root=new Node(1);
        root.left=new Node(2);
        root.right=new Node(3);
        inorder(root);
    }
}'''
    },

    "arrays": {
        "py": '''def find_max(arr):
    mx = arr[0]
    for x in arr:
        mx = max(mx, x)
    return mx

if __name__ == "__main__":
    arr = [1,5,2,9,3]
    print("Max:", find_max(arr))'''
    },

    "stack": {
        "cpp": '''#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['||c=='{') st.push(c);
        else{
            if(st.empty()) return false;
            char t=st.top(); st.pop();
            if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))
                return false;
        }
    }
    return st.empty();
}

int main(){
    cout<<(isValid("()[]{}")?"Valid":"Invalid");
    return 0;
}'''
    }
}

# ---------------- HELPERS ---------------- #

def get_ext(lang):
    return {"cpp":"cpp","py":"py","java":"java"}[lang]

def filename(topic, lang, date):
    t = topic.replace(" ", "_")
    return f"{t}_{lang}_{date}.{get_ext(lang)}"

def is_valid(code):
    if not code: return False
    if len(code.strip()) < 120: return False
    if code.strip().startswith("// Default"): return False
    return True

# ---------------- AI ---------------- #

def generate_ai(topic, lang, key):
    prompt = f"""
Generate COMPLETE runnable {lang} code for DSA topic: {topic}

Rules:
- Full working program
- No TODO, no placeholders
- Must include main()
"""
    try:
        r = requests.post(
            "https://api.groq.com/openai/v1/chat/completions",
            headers={
                "Authorization": f"Bearer {key}",
                "Content-Type": "application/json"
            },
            json={
                "model": "mixtral-8x7b-32768",
                "messages": [{"role":"user","content":prompt}],
                "max_tokens": 1000,
                "temperature": 0.3
            },
            timeout=25
        )
        r.raise_for_status()
        return r.json()["choices"][0]["message"]["content"]
    except Exception as e:
        print("AI generation failed:", e)
        return None

# ---------------- CODE RESOLUTION ---------------- #

def get_code(topic, lang):
    api_key = os.environ.get("GROQ_API_KEY")

    # 1️⃣ Try AI
    code = None
    if api_key:
        code = generate_ai(topic, lang, api_key)
        if is_valid(code):
            return code

    # 2️⃣ Try fallback
    code = FALLBACKS.get(topic, {}).get(lang)
    if is_valid(code):
        return code

    # 3️⃣ Last-resort generator
    return f"""
// Auto-generated fallback for {topic} in {lang}
#include <bits/stdc++.h>
using namespace std;

int main() {{
    cout << "DSA topic: {topic}" << endl;
    cout << "Language: {lang}" << endl;
    return 0;
}}
"""

# ---------------- MAIN ---------------- #

def main():
    today = datetime.date.today().strftime("%Y-%m-%d")
    folder = f"codestudio/{today}"
    os.makedirs(folder, exist_ok=True)

    subprocess.run(["git","config","user.name","github-actions[bot]"],check=True)
    subprocess.run(["git","config","user.email","github-actions[bot]@users.noreply.github.com"],check=True)

    topics = random.sample(TOPICS, 3)
    files = []

    for topic in topics:
        lang = random.choice(LANGUAGES)
        code = get_code(topic, lang)

        fname = filename(topic, lang, today)
        path = os.path.join(folder, fname)

        with open(path,"w",encoding="utf-8") as f:
            f.write(code)

        files.append(path)

    # README
    readme = "README.md"
    log = f"\n## {today}\n" + "\n".join(f"- {os.path.basename(f)}" for f in files)

    if os.path.exists(readme):
        with open(readme,"a") as f: f.write(log)
    else:
        with open(readme,"w") as f: f.write("# DSA Auto Commit Log\n"+log)

    subprocess.run(["git","add",folder],check=True)
    subprocess.run(["git","add",readme],check=True)
    subprocess.run(["git","commit","-m",f"Add 3 DSA solutions for {today}"],check=True)

if __name__=="__main__":
    main()
