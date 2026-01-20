class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
      
      int n=arr.size();
      int Wi = 0;
      
      for(int i=0;i<k;i++){
          Wi+=arr[i];
      }
      
      int maxSum = Wi;
      
      
      for(int i=k;i<n;i++){
          Wi+=arr[i];
          Wi-=arr[i-k];
          maxSum = max(Wi,maxSum);
          
          
      }
      
      return maxSum;
    }
};
