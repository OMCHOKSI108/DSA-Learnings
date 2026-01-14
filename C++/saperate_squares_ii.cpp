#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type; // +1 add, -1 remove
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        double totalArea = unionArea(squares, high);

        while (high - low > 1e-5) {
            double mid = (low + high) / 2.0;
            double below = unionArea(squares, mid);

            if (below * 2 >= totalArea)
                high = mid;
            else
                low = mid;
        }

        return low;
    }

private:
    double unionArea(vector<vector<int>>& squares, double cutY) {
        vector<Event> events;

        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            double h = min(max(cutY - y, 0.0), l);
            if (h <= 0) continue;

            events.push_back({y, x, x + l, +1});
            events.push_back({y + h, x, x + l, -1});
        }

        if (events.empty()) return 0.0;

        sort(events.begin(), events.end());

        multiset<pair<double,double>> active;
        double prevY = events[0].y;
        double area = 0.0;

        for (auto &e : events) {
            double currY = e.y;
            double height = currY - prevY;

            if (height > 0 && !active.empty())
                area += height * mergedXLength(active);

            if (e.type == 1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            prevY = currY;
        }

        return area;
    }

    double mergedXLength(const multiset<pair<double,double>>& intervals) {
        double total = 0.0;
        double curL = -1e18, curR = -1e18;

        for (auto &p : intervals) {
            if (p.first > curR) {
                total += curR - curL;
                curL = p.first;
                curR = p.second;
            } else {
                curR = max(curR, p.second);
            }
        }

        total += curR - curL;
        return total;
    }
};
