using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            n = f(n);
        }
        return n == 1;
    }
    
    int f(int n) {
        int s = 0;
        while (n > 0) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }
};
int main() {
    Solution sol;
    int n = 19;
    cout << (sol.isHappy(n) ? "true" : "false") << endl;
    return 0;
}