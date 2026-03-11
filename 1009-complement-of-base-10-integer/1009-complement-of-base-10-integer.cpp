class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;          // complement of 0 is 1
        
        int mask = 0;
        int temp = n;
        while (temp > 0) {
            mask = (mask << 1) | 1;    // build mask of all 1's with same length
            temp >>= 1;
        }
        return n ^ mask;                // XOR gives the complement
    }
};