#include<iostream>
using namespace std;

class Solution{
    public:
    int missing_with_odd(int arr){
        int size=arr.size();

        int cnt=0;
        int arr_cnt={};

        for(int i=0;i<size;i++){
            arr_cnt[arr[i]]++;
        }

        for(int i=1;i<=size;i++){
            if(arr_cnt[i]%2!=0){
                cnt=i;
                break;
            }
        }
        return cnt;
        

    }



};




int main(){

    Solution s1;
    int arr = {1,2,3,2,3,1,3};
    cout<<s1.missing_with_odd(arr)<<endl;
    return 0;
}