#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            cout << "The input list is empty. Returning empty string.\n";
            return "";
        }

        // Start with the first string as our initial prefix
        string prefix = strs[0];
        cout << "Starting with prefix: '" << prefix << "'\n\n";

        // Compare this prefix with all other strings in the array
        for (int i = 1; i < strs.size(); i++) {
            cout << "Comparing with string #" << i << ": '" << strs[i] << "'\n";
            
            // Keep shortening the prefix until it matches the beginning of the current string
            while (strs[i].find(prefix) != 0) {
                cout << "  '" << prefix << "' is NOT a prefix of '" << strs[i] << "'\n";
                
                // Shorten the prefix by removing the last character
                prefix = prefix.substr(0, prefix.size() - 1);
                cout << "  Trying new prefix: '" << prefix << "'\n";
                
                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) {
                    cout << "Prefix became empty. No common prefix found.\n";
                    return "";
                }
            }
            cout << "  ✓ '" << prefix << "' is a valid prefix of '" << strs[i] << "'\n\n";
        }

        cout << "Final common prefix found!\n";
        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    
    cout << "Finding longest common prefix for: ";
    for (string s : strs) cout << "'" << s << "' ";
    cout << "\n\n";
    
    string result = sol.longestCommonPrefix(strs);
    cout << "\nLongest Common Prefix: '" << result << "'" << endl;
    
    return 0;
}