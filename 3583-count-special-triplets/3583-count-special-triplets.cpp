class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        long long count = 0;
        
        // frequency map for elements on the right side of current j
        unordered_map<int, int> rightFreq;
        for (int num : nums) {
            rightFreq[num]++;
        }
        
        // frequency map for elements on the left side of current j
        unordered_map<int, int> leftFreq;
        
        // For each j as the middle element
        for (int j = 0; j < n; j++) {
            // Remove current element from right frequency (as it's now the middle)
            rightFreq[nums[j]]--;
            
            // If we have at least one element on left and one on right
            if (j > 0 && j < n - 1) {
                int target = 2 * nums[j];
                
                // Count triplets: leftCount * rightCount
                long long leftCount = leftFreq[target];
                long long rightCount = rightFreq[target];
                
                count = (count + leftCount * rightCount) % MOD;
            }
            
            // Add current element to left frequency
            leftFreq[nums[j]]++;
        }
        
        return count;
    }
};