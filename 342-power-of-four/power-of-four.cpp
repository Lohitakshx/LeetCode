class Solution {
public:
    bool loki(int n) {
        if (n == 1) return true;                  // base case
        if (n <= 0 || n % 4 != 0) return false;   // stop if not divisible by 4
        return loki(n / 4);                       // recurse properly
    }

    bool isPowerOfFour(int n) {
        return loki(n);
    }
};
