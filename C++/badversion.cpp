#include<iostream>
using namespace std;

int firstbadversion(int n){
    int l = 0;
    int r = n;

    while(l<=h){
        int mid = l + (h-l)/2;
        if(isBadversion(mid)) h = mid-1;
        else 
            h = mid+1;
    }

    return mid;
    
}

bool isBadversion(int n){
    if(n>2){
        return true;
    }
    return false
}

int main(){
    int nums[] = [1,2,3,4,5];
    cout<<firstbadversion(4);
    

    return 0;
}