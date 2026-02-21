class Solution {
public:
    int countPrimeSetBits(int left, int right) {
      int res=0;

    unordered_set<int> us = {2,3,5,7,11,13,17,19};
      for(int i=left;i<=right;i++){
            int pop = __builtin_popcount(i);
            
            if(us.count(pop)){
                res++;
            }
            pop=0;
      }

      return res;  
    }
};
