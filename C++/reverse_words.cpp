#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> str;
        string word, res;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                word += s[i];
            }
            else
            { 
                if (!word.empty())
                {
                    reverse(word.begin(), word.end());
                    str.push(word);
                }
                word = "";
            } 
        }
        if (!word.empty())
        {
            reverse(word.begin(), word.end());
            str.push(word);
        }
        while (!str.empty())
        {
            res += str.top();
            str.pop();
            if (!str.empty())
                res += " ";
        }
        return res;
    }
};

int main()
{
    string input;
    cout << "input : ";
    getline(cin, input);
    Solution sol;
    string output = sol.reverseWords(input);
    cout << "output : " << output << endl;
    return 0;
}

