#include<iostream>
using namespace std;

string reverseString(string s){
    string res={};
    i = s.size() - 1;
    while(i>0){
        while(i>=0 && s[i]==' ') i--;
        if(i<0) break;

        int j=i;
        while(j>=0 && s[i]==' ') j--;

        if(!res.empty()) res += ' ';
        res += s.substr(j + 1, i - j);

        i=j-1;
    }
    return res;
}

int main(){
    string str;
    str = "S is my crush ";
    cout<<reverseString(str);
    return 0;
}