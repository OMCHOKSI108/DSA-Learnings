#include <bits/stdc++.h>
using namespace std;

char Match(char m1,char m2){
     if(m1!=m2) return 'B';
     else return 'G';
}

int main() {
    int T;
    cin>>T;
    string s={};
    
    while(T--){
        
         string real = {};
    cin>>real;
    string pred = {};
    cin>>pred;
    for(int i=0;i<real.size();i++){
        s+=Match(real[i],pred[i]);
    }
    cout<<s<<endl;
    s={};
        
    }
    
    return 0;
   
    
    
}
 