#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int cnt = 0;
        for (int i = 1; i < s.size(); i++) {
            cnt += abs(int(s[i - 1]) - int(s[i]));
        }
        return cnt;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Solution sol;
    int score = sol.scoreOfString(s);
    cout << "Score of string: " << score << endl;
    return 0;
}