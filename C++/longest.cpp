#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}

/*
Example:
Input: ["flower", "flow", "flight"]
Output: "fl"

Explanation:
- "flower", "flow", and "flight" all start with "fl".
- The function checks each string and reduces the prefix until all strings start with it.
- "fl" is the longest common prefix among all strings.
*/


// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     string longestCommonPrefix(const vector<string>& strs) {
//         if (strs.empty()) return "";

//         // find minimum length among strings
//         size_t minlen = strs[0].size();
//         for (const auto &s : strs) if (s.size() < minlen) minlen = s.size();

//         string prefix;
//         for (size_t i = 0; i < minlen; ++i) {
//             char c = strs[0][i];
//             for (size_t j = 1; j < strs.size(); ++j) {
//                 if (strs[j][i] != c) return prefix; // mismatch -> return current prefix
//             }
//             prefix.push_back(c); // all strings had this char
//         }
//         return prefix;
//     }
// };

// int main() {
//     Solution sol;
//     vector<string> strs = {"flower", "flow", "flight"};
//     cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs) << endl;
//     return 0;
// }