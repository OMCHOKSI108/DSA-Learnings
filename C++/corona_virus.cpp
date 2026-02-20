#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int mn = n;
    int mx = 0;
    int l = 0;                                                                                                                                                                                                                

    for (int i = 0; i < n; ++i) {
        if (i > 0 && x[i] - x[i - 1] > 2) {
            l = i;
        }
        
        
        if (i == n - 1 || x[i + 1] - x[i] > 2) {
            int cur = i - l + 1;
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
    }



    cout << mn << " " << mx << endl;
}





int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
