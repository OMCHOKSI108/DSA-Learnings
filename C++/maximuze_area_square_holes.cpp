#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort removed bars
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Function to find maximum continuous gap
        auto maxSpan = [](vector<int>& bars) {
            int res = 1, streak = 1;

            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1)
                    streak++;      // consecutive bars
                else
                    streak = 1;    // reset streak

                res = max(res, streak);
            }
            return ++res; // gap size = removed bars + 1
        };

        // Maximum possible square side
        int side = min(maxSpan(hBars), maxSpan(vBars));

        // Area of square hole
        return side * side;
    }
};

int main() {
    Solution sol;

    // Grid size
    int n = 5, m = 5;

    // Removed horizontal and vertical bars
    vector<int> hBars = {2, 3};
    vector<int> vBars = {1, 2};

    // Compute result
    int result = sol.maximizeSquareHoleArea(n, m, hBars, vBars);

    // Output result
    cout << "Maximum square hole area: " << result << endl;

    return 0;
}
