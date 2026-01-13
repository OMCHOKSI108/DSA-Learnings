#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0.0;

        for (auto &square : squares) {
            double x = square[0]; // unused but kept as-is
            double y = square[1];
            double l = square[2];

            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double result_y = 0.0;
        while (high - low > 1e-5) {
            double mid_y = low + (high - low) / 2;
            result_y = mid_y;

            if (check(squares, mid_y, total)) {
                // bottom area >= upper area
                high = mid_y;
            } else {
                low = mid_y;
            }
        }
        return result_y;
    }

    bool check(vector<vector<int>>& squares, double mid_y, double total) {
        double botArea = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];

            if (mid_y <= y) {
                // fully above the line
                continue;
            } 
            else if (mid_y >= y + l) {
                // fully below the line
                botArea += l * l;
            } 
            else {
                // partially cut by the line
                botArea += (mid_y - y) * l;
            }
        }

        return botArea >= total / 2.0;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<vector<int>> squares(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> squares[i][0] >> squares[i][1] >> squares[i][2];
    }

    double answer = sol.separateSquares(squares);
    cout << fixed << setprecision(5) << answer << endl;

    return 0;
}
