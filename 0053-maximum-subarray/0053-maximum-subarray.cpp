class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int FinalMax = nums[0];
        int n= nums.size();
        //now we are going to check the final sum will be how much 
        for(int i = 1; i< nums; i++){
            currentMax = max(nums[i], currentMax + nums[i]);

            // now we are need to check the cuurentMax will be greater or less than the FinalSum
            if(currentMax > FinalMax){
                FinalMax = currentMax;
            }
        }

        return FinalMax;
    }
};