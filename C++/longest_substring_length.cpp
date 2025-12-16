/*


3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

//1. window sliding approach

#include<iostream>
using namespace std;

class Solution {
public:
    int LongestSubstringLength(string s){
         int left = 0;
         int max_length = 0;

         unordered_set<char> charSet;

         for(int right=0;right<s.length();right++){
            while(charSet.find(s[right])!=charSet.end()){
                charSet.erase(s[left]);
                left++;

            }

            charSet.insert(s[right]);
            max_length = max(max_length,right-left+1);
         }

         return max_length;
    }

};

int main(){

    Solution s1;

    string s = "abcabcbca";
    cout<<"Longest Substring Length : "<<s1.LongestSubstringLength(s);
    return 0;
}


/*Explanantion :

---

## What the function is solving

Given a string `s`, find the **length of the longest contiguous substring** that has **no repeated characters**.

Example:

```
s = "abcabcbb"
Answer = 3   // "abc"
```

---

## High-level idea (Sliding Window)

We maintain a **window** `[left … r]` such that:

* The window always contains **unique characters**
* `r` expands the window to the right
* `left` shrinks the window when a duplicate appears

The window moves forward in **O(n)** time.

---

## Code walkthrough

### 1. Variables

```cpp
int left = 0;
int maxLength = 0;
unordered_set<char> charSet;
```

* `left` → start index of the sliding window
* `maxLength` → stores the best answer so far
* `charSet` → keeps track of characters **currently inside the window**

---

### 2. Right pointer loop

```cpp
for (int r = 0; r < s.length(); r++) {
```

* `r` is the **right pointer**
* It expands the window one character at a time

---

### 3. Handle duplicates

```cpp
while (charSet.find(s[r]) != charSet.end()) {
    charSet.erase(s[left]);
    left++;
}
```

**What this means:**

* If `s[r]` is already inside the window:

  * We have a **duplicate**
* So we **shrink the window from the left** until the duplicate is removed

This guarantees:

> The window always contains unique characters

Example:

```
s = "abba"
window before conflict: "ab"
r points to second 'b'
```

We remove:

```
remove 'a' → window "b"
remove 'b' → window ""
```

Now we can safely add the new `'b'`.

---

### 4. Add current character

```cpp
charSet.insert(s[r]);
```

* Adds the new character to the window
* Window now has **all unique characters**

---

### 5. Update max length

```cpp
maxLength = max(maxLength, r - left + 1);
```

* Current window length = `r - left + 1`
* Compare it with previous best
* Store the maximum

---

### 6. Return result

```cpp
return maxLength;
```

---

## Step-by-step example

### Input:

```
s = "abcabcbb"
```

| r | s[r] | Window | maxLength |
| - | ---- | ------ | --------- |
| 0 | a    | "a"    | 1         |
| 1 | b    | "ab"   | 2         |
| 2 | c    | "abc"  | 3         |
| 3 | a    | "bca"  | 3         |
| 4 | b    | "cab"  | 3         |
| 5 | c    | "abc"  | 3         |
| 6 | b    | "cb"   | 3         |
| 7 | b    | "b"    | 3         |

Final answer = **3**

---

## Why this solution is efficient

* Each character is **inserted and removed at most once**
* Time Complexity: **O(n)**
* Space Complexity: **O(min(n, charset))**

---

## Key intuition

* Use **two pointers** to represent a valid substring
* Use a **set** to enforce uniqueness
* Expand when valid, shrink when invalid

---


*/