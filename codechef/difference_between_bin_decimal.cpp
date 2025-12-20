#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;cnt=0;

        cin>>n>>s;

        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]) cnt++;
            
        }

        cout<<cnt<<endl;
    }

    return 0;
}
