#include<iostream>
using namespace std;

class Solution{
public:
    int kth_largest(int &nums,int k){

        priority_queue<int> pq;
        for(int i: nums) pq.push(i);
        while(k-->0){
            pq.pop();
        }

        return pq.top();
    }

};




int main(){

    Solution sol;
int nums[] = {3, 2, 1, 5, 6, 4};
int k = 2;
cout << "Kth largest element: " << sol.kth_largest(nums, k) << endl;
return 0;
    return 0;
}
