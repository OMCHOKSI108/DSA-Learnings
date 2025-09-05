#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < friends.size(); j++) {
                if (order[i] == friends[j]) {
                    ans.push_back(friends[j]);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> order = {1, 2, 3, 4};
    vector<int> friends = {3, 1, 4, 5};
    Solution sol;
    vector<int> result = sol.recoverOrder(order, friends);

    cout << "Recovered Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}