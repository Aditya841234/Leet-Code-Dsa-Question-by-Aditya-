class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Consider two cases:
        // 1. Product of three largest numbers
        // 2. Product of two smallest (most negative) and the largest number
        // This handles cases like [-100, -2, -1, 2, 3, 4]
        
        long long option1 = (long long)nums[n-1] * nums[n-2] * nums[n-3];
        long long option2 = (long long)nums[0] * nums[1] * nums[n-1];
        
        return max(option1, option2);
    }
};