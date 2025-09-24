#include <iostream>

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                num1 += i;
            } else {
                num2 += i;
            }
        }
        return num2 - num1;
    }
};

int main() {
    Solution sol;
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    cout << sol.differenceOfSums(n, m) << endl;
    return 0;
}