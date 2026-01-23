#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int ans = 0;
 
    while (n--) {
        vector<int> nums(3);
        int sum = 0;
 
        for (int i = 0; i < 3; i++) {
            cin >> nums[i];
            sum += nums[i];
        }
 
        if (sum >= 2) {
            ans++;
        }
    }
 
    cout << ans;
    return 0;
}
