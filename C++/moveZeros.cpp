#include<iostream>
using namespace std;


class Solution{
publiv:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;  
        for(int i=0;i<nums.size();i++){
            if (nums[i]!=0){
               
                swap(nums[i],nums[j]);
            
                j++;  
            }
        }
    }
};

};





int main(){
    vector<int> arr = {1,0,1,1,2};
    cout<<moveZeroes(arr);

    return 0;
}