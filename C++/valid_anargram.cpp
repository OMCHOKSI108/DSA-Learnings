class Solution {
public:
    bool isAnagram(string &s1, string &s2) {
    
    if (s1.length() != s2.length()) 
        return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    
    return (s1 == s2);
} 
};

int main() {
    Solution sol;
    string s1 = "listen";
    string s2 = "silent";
    
    if (sol.isAnagram(s1, s2)) {
        cout << "Anagram" << endl;
    } else {
        cout << "Not an anagram" << endl;
    }
    
    return 0;
}