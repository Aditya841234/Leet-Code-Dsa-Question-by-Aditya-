class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        // Cyclic sort
        int i = 0;
        while(i < n) {
            if(nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }
        
        // Find numbers not at correct positions
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};