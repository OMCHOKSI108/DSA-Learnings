#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    bool containNearBy(vector<int>& nums, int k){
        unordered_set<int> set;

        for(int i = 0; i < nums.size(); ++i){
            if(i > k){
                set.erase(nums[i - k - 1]);
            }

            if(set.count(nums[i])){
                return true;
            }

            set.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    Solution sol;

    // Test case 1: Contains duplicate within distance k
    vector<int> nums1 = {99, 99};
    cout << "Test 1: " << sol.containNearBy(nums1, 2) << endl;

    // Test case 2: No duplicate within distance k
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Test 2: " << sol.containNearBy(nums2, 3) << endl;

    // Test case 3: Duplicate but outside distance k
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    cout << "Test 3: " << sol.containNearBy(nums3, 2) << endl;

    return 0;
}


// Detailed iteration trace for nums1 = [1,2,3,1,2,3] , k = 2

// Iteration i = 0:
//   - i > k? (0 > 2) = false, so no erase
//   - set.count(1)? No, set is empty
//   - set.insert(1) → set = {1}
//
// Iteration i = 1:
//   - i > k? (1 > 2) = false, so no erase
//   - set.count(2)? No, 2 not in set
//   - set.insert(2) → set = {1, 2}
//
// Iteration i = 2:
//   - i > k? (2 > 2) = false, so no erase
//   - set.count(3)? No, 3 not in set
//   - set.insert(3) → set = {1, 2, 3}
//
// Iteration i = 3:
//   - i > k? (3 > 2) = true, erase nums[0] = 1 → set = {2, 3}
//   - set.count(1)? No, 1 not in set
//   - set.insert(1) → set = {2, 3, 1}
//
// Iteration i = 4:
//   - i > k? (4 > 2) = true, erase nums[1] = 2 → set = {3, 1}
//   - set.count(2)? No, 2 not in set
//   - set.insert(2) → set = {3, 1, 2}
//
// Iteration i = 5:
//   - i > k? (5 > 2) = true, erase nums[2] = 3 → set = {1, 2}
//   - set.count(3)? No, 3 not in set
//   - set.insert(3) → set = {1, 2, 3}
//
// Return false (no duplicates found within distance k)
