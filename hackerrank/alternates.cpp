class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                ans.push_back(arr[i]);
            }
            
            else if(i%2==0){
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
        
    }
};
