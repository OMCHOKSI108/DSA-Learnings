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