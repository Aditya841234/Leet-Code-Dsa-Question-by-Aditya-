class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        int n = nums.size();
        int distinctCount = 1;
        int thirdMax = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                distinctCount++;
                if (distinctCount == 3) {
                    return nums[i];
                }
            }
        }
        
        // If we have less than 3 distinct numbers, return the maximum
        return nums[0];
    }
};