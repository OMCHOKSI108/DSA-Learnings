#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [](int a, int b) {
            
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);
            
            // First sort by number of 1s
            if (bitsA == bitsB)
                return a < b;      // If equal bits → smaller number first
            
            return bitsA < bitsB;  // Otherwise → fewer 1s first
        });
        
        return arr;
    }
};
