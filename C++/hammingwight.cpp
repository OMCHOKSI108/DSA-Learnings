class Solution {
public:
    int hammingWeight(int n) {
        int c = 0;
        while (n > 0) {
            c += n % 2;
            n /= 2;
        }
        return c;
    }
};
int main() {
    Solution solution;
    int result = solution.hammingWeight(11);
    std::cout << "Hamming Weight: " << result << std::endl;
    return 0;
}