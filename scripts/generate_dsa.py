import os
import datetime
import random
import subprocess
import requests

# List of DSA topics to rotate
TOPICS = ['arrays', 'strings', 'stack', 'queue', 'binary search', 'recursion', 'DP', 'trees']
LANGUAGES = ['cpp', 'py', 'java']

# Predefined templates for fallback
TEMPLATES = {
    'arrays': {
        'cpp': '''#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum element in an array
// Solution: Iterate through the array and keep track of max
int findMax(vector<int>& arr) {
    if (arr.empty()) return -1;
    int max_val = arr[0];
    for (int num : arr) {
        if (num > max_val) max_val = num;
    }
    return max_val;
}

int main() {
    vector<int> arr = {1, 3, 2, 5, 4};
    cout << "Max: " << findMax(arr) << endl;
    return 0;
}''',
        'py': '''# Problem: Find the maximum element in an array
# Solution: Use built-in max function
def find_max(arr):
    if not arr:
        return -1
    return max(arr)

if __name__ == "__main__":
    arr = [1, 3, 2, 5, 4]
    print(f"Max: {find_max(arr)}")''',
        'java': '''// Problem: Find the maximum element in an array
// Solution: Iterate through the array
public class ArrayMax {
    public static int findMax(int[] arr) {
        if (arr.length == 0) return -1;
        int max = arr[0];
        for (int num : arr) {
            if (num > max) max = num;
        }

        return max;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 5, 4};
        System.out.println("Max: " + findMax(arr));
    }
}'''
    },
    'strings': {
        'cpp': '''#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse a string
// Solution: Use two pointers
string reverseString(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main() {
    string s = "hello";
    cout << "Reversed: " << reverseString(s) << endl;
    return 0;
}''',
        'py': '''# Problem: Reverse a string
# Solution: Use slicing
def reverse_string(s):
    return s[::-1]

if __name__ == "__main__":
    s = "hello"
    print(f"Reversed: {reverse_string(s)}")''',
        'java': '''// Problem: Reverse a string
// Solution: Use StringBuilder
public class StringReverse {
    public static String reverseString(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) {
        String s = "hello";
        System.out.println("Reversed: " + reverseString(s));
    }
}'''
    },
    'stack': {
        'cpp': '''#include <bits/stdc++.h>
using namespace std;

// Problem: Valid parentheses
// Solution: Use stack
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "()[]{}";
    cout << "Valid: " << (isValid(s) ? "Yes" : "No") << endl;
    return 0;
}''',
        'py': '''# Problem: Valid parentheses
# Solution: Use stack
def is_valid(s):
    stack = []
    mapping = {')': '(', ']': '[', '}': '{'}
    for char in s:
        if char in mapping:
            top = stack.pop() if stack else '#'
            if mapping[char] != top:
                return False
        else:
            stack.append(char)
    return not stack

if __name__ == "__main__":
    s = "()[]{}"
    print(f"Valid: {is_valid(s)}")''',
        'java': '''// Problem: Valid parentheses
// Solution: Use stack
import java.util.Stack;

public class ValidParentheses {
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                char top = stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        String s = "()[]{}";
        System.out.println("Valid: " + isValid(s));
    }
}'''
    },
    # Add more templates for other topics as needed
}

def get_file_extension(lang):
    return {'cpp': 'cpp', 'py': 'py', 'java': 'java'}[lang]

def generate_random_code(lang):
    """Generate a simple random code snippet that varies daily"""
    rand_num = random.randint(1, 100)
    if lang == 'cpp':
        return f'''#include <iostream>
using namespace std;

int main() {{
    cout << "Random number: {rand_num}" << endl;
    for (int i = 0; i < {rand_num % 10}; i++) {{
        cout << "Iteration " << i << endl;
    }}
    return 0;
}}'''
    elif lang == 'py':
        return f'''# Random code
import random

def random_function():
    num = {rand_num}
    print(f"Random number: {{num}}")
    for i in range(num % 10):
        print(f"Iteration {{i}}")

if __name__ == "__main__":
    random_function()'''
    elif lang == 'java':
        return f'''// Random code
public class RandomCode {{
    public static void main(String[] args) {{
        int num = {rand_num};
        System.out.println("Random number: " + num);
        for (int i = 0; i < num % 10; i++) {{
            System.out.println("Iteration " + i);
        }}
    }}
}}'''

def generate_code_with_ai(topic, lang, api_key):
    """Generate code using Groq API"""
    prompt = f"""Write a complete, working {lang} code for a DSA problem related to {topic}.
Include:
1. Problem statement as a comment at the top
2. Complete code with proper syntax
3. Example usage in main function
4. Comments explaining the solution

Make sure the code is correct and runnable."""

    try:
        response = requests.post(
            'https://api.groq.com/openai/v1/chat/completions',
            headers={
                'Authorization': f'Bearer {api_key}',
                'Content-Type': 'application/json'
            },
            json={
                'model': 'llama3-8b-8192',
                'messages': [{'role': 'user', 'content': prompt}],
                'max_tokens': 1000,
                'temperature': 0.7
            },
            timeout=30
        )
        response.raise_for_status()
        return response.json()['choices'][0]['message']['content'].strip()
    except Exception as e:
        print(f"AI generation failed: {e}")
        return None

def get_code(topic, lang):
    """Get code either from AI or fallback to template"""
    api_key = os.environ.get('GROQ_API_KEY')
    if api_key:
        code = generate_code_with_ai(topic, lang, api_key)
        if code:
            return code
    # Fallback to template
    return TEMPLATES.get(topic, {}).get(lang, f'// Default {lang} code for {topic}')

def main():
    # Get today's date
    today = datetime.date.today()
    date_str = today.strftime('%Y-%m-%d')
    folder = f'codestudio/{date_str}'
    
    # Create directory
    os.makedirs(folder, exist_ok=True)
    
    # Add .gitkeep to make directory committable
    with open(f'{folder}/.gitkeep', 'w') as f:
        f.write('')
    
    # Configure git
    subprocess.run(['git', 'config', 'user.name', 'github-actions[bot]'], check=True)
    subprocess.run(['git', 'config', 'user.email', 'github-actions[bot]@users.noreply.github.com'], check=True)
    
    # Commit 1: Create directory
    subprocess.run(['git', 'add', folder], check=True)
    subprocess.run(['git', 'commit', '-m', f'Create directory for {date_str}'], check=True)
    
    # Select 3 random topics (may have duplicates, but that's fine)
    selected_topics = random.choices(TOPICS, k=3)
    
    # Generate 3 DSA solutions
    for i, topic in enumerate(selected_topics, 1):
        lang = random.choice(LANGUAGES)
        code = get_code(topic, lang)
        ext = get_file_extension(lang)
        filename = f'{folder}/dsa_{i}_{topic.replace(" ", "_")}.{ext}'
        
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(code)
        
        # Commit each DSA solution
        subprocess.run(['git', 'add', filename], check=True)
        subprocess.run(['git', 'commit', '-m', f'Add DSA solution {i}: {topic} in {lang.upper()}'], check=True)
    
    # Generate random codes for each language
    random_codes = {}
    for lang in LANGUAGES:
        code = generate_random_code(lang)
        ext = get_file_extension(lang)
        filename = f'{folder}/random_{lang}.{ext}'
        random_codes[lang] = filename
        
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(code)
    
    # Update README with today's log
    readme_path = 'README.md'
    log_entry = f'\n## {date_str}\n- Generated 3 DSA problems: {", ".join(selected_topics)}\n- Added random codes in C++, Python, Java\n'
    
    if os.path.exists(readme_path):
        with open(readme_path, 'a', encoding='utf-8') as f:
            f.write(log_entry)
    else:
        with open(readme_path, 'w', encoding='utf-8') as f:
            f.write(f'# DSA Auto Commit Log\n{log_entry}')
    
    # Commit 4: Add random codes and update README
    for filename in random_codes.values():
        subprocess.run(['git', 'add', filename], check=True)
    subprocess.run(['git', 'add', readme_path], check=True)
    subprocess.run(['git', 'commit', '-m', f'Add random codes and update log for {date_str}'], check=True)

if __name__ == '__main__':
    main()