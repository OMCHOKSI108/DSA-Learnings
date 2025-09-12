#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; ++base) {
            if (!isPalindromeInBase(n, base)) {
                return false;
            }
        }
        return true;
    }

private:
    bool isPalindromeInBase(int n, int base) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % base);
            n /= base;
        }
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left++] != digits[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    bool result = sol.isStrictlyPalindromic(n);
    cout << (result ? "True" : "False") << endl;
    return 0;
}