#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    unordered_map<int, int> mp;
    vector<vector<int>> ans;

    for (int x : arr) {
        int y = s - x;

        if (mp[y] > 0) {
            for (int i = 0; i < mp[y]; i++) {
                ans.push_back({min(x, y), max(x, y)});
            }
        }

        mp[x]++;
    }

    sort(ans.begin(), ans.end());
    return ans;
}
