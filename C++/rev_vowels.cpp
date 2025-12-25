#include<iostream>
using namespace std;

class Solution{

public:
string reversevowels(string s){
    unordered_set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};

    int i=0;
    int r = s.size() - 1;

    while(l<r){
        if(!vow.count(s[l])){
            l++;
            continue;
        }

        if(!vow.count(s[r])){
            r--;
            continue;
        }

        char t = s[l];
        s[r] = s[l];
        s[r] = temp;
        l++;
        r--;
    }

    return s;
}


};


int main(){


    Solution sol;
string test = "hello";
cout << "Original: " << test << endl;
cout << "Reversed vowels: " << sol.reversevowels(test) << endl;
return 0;
}
