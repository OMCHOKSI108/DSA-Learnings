/**
 * @class Solution
 * @brief Provides functionality to reverse the bits of a 32-bit unsigned integer.
 */

/**
 * @function reverseBits
 * @brief Reverses all 32 bits of a given unsigned integer.
 * 
 * @param n The 32-bit unsigned integer whose bits are to be reversed.
 * @return uint32_t The integer with all bits reversed.
 * 
 * @details
 * Algorithm explanation:
 * - Initializes result to 0 to store the reversed bits
 * - Iterates 32 times (once for each bit in a 32-bit integer)
 * - In each iteration:
 *   1. Left shifts result by 1 bit to make space for the next bit
 *   2. Extracts the least significant bit of n using (n & 1)
 *   3. Combines the extracted bit with result using bitwise OR
 *   4. Right shifts n by 1 bit to process the next bit
 * - Returns the reversed 32-bit integer
 * 
 * Example: 
 * Input: 43261596 (binary: 00000010100101000001111010011100)
 * Output: 964176192 (binary: 00111001011110000010100101000010)
 * 
 * Time Complexity: O(1) - always 32 iterations
 * Space Complexity: O(1) - only uses constant extra space
 */
#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }

        return result;
    }
};
int main() {
    Solution sol;
    uint32_t num = 43261596;
    uint32_t reversed = sol.reverseBits(num);
    cout << "Original: " << num << std::endl;
    cout << "Reversed: " << reversed << std::endl;
    return 0;
}

