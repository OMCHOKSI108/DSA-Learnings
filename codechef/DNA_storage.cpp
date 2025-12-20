// 00 -> "A"
// 01 -> "T"
// 10 -> "C"
// 11 -> "G"

int main(){

    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;

        String s;
        cin>s;

        cout<<DNA(s,N);
    }
    return 0;
}

char Compare_out(string s2){
    if(s2=="00") return 'A';
    if(s2=="01") return 'T';
    if(s2=="10") return 'C';
    if(s2=="11") return 'G';
}

string DNA(String s,int N){
    string res="";
    for(int i=0;i<n;i+=2){
        string temp = s.substr(i,2);
        res+=Compare_out(temp);
    }
    return res;
}


// KHATARNAAK VERSION 

/*

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        char mp[4] = {'A','T','C','G'};

        for(int i = 0; i < n; i += 2){
            int v = (s[i]-'0')*2 + (s[i+1]-'0');
            cout << mp[v];
        }
        cout << '\n';
    }
}


*/