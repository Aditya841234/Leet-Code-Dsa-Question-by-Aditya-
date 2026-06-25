class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int x : nums) {
            // Update 'ones' with bits that are in x but not in 'twos'
            ones = (ones ^ x) & ~twos;
            
            // Update 'twos' with bits that are in x but now also in 'ones'
            twos = (twos ^ x) & ~ones;
        }
        
        return ones;
    }
};