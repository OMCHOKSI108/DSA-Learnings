#include <iostream>
#include <stack>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> str;
         string res;

         for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                res+=s[i];
            }
            else{
                
                if(res.length()>0)
                str.push(res);
                res="";
            }
            
         }

         if(res.length()>0){
            str.push(res);
            res="";
         }
         while(!str.empty()){
            res+=str.top()+" ";
            str.pop();
         }
         res=res.substr(0,res.length()-1);

         return res;  
    }
};



int main() {
    string input;
    cout << "input : ";
    getline(cin, input);
    Solution sol;
    string output = sol.reverseWords(input);
    cout << "output : " << output << endl;
    return 0;
}