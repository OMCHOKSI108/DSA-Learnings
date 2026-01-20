#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());  


    bool ok1 = true;
    bool ok2 = true; 

    for(int i = 0; i < n; i++) {
        int parity = v[i].second % 2;

        if(parity != (i % 2)) ok1 = false;
        if(parity != ((i + 1) % 2)) ok2 = false;
    }

    if(ok1 || ok2) return "YES";
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
    return 0;
}
