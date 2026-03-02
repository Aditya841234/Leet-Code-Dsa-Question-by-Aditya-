class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        ans = nums;
        for(int i = 0; i<size;i++){
            ans.push_back(nums[i]);
        }

        return ans;
    }
};