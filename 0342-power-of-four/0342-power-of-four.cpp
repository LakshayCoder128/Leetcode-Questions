class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if n is a power of 2
        if (n <= 0 || (n & (n - 1)) != 0) {
            return false;
        }
        
        // Check if the number of trailing 0s is even
        return (n & 0x55555555) == n;
    }
};
