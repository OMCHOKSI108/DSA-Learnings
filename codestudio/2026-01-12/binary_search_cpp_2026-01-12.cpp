#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int x){
    int l=0,r=a.size()-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==x) return m;
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(){
    vector<int>a={1,3,5,7,9};
    cout<<binarySearch(a,7);
    return 0;
}