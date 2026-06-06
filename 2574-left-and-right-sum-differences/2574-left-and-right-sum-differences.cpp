class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       for(int i=0;i<nums.size();i++){
        int left_start=0,right_start=nums.size()-1,left_sum=0,right_sum=0;
        while(left_start<i){
            left_sum +=nums[left_start];
            left_start++;
        }
        while(right_start>i){
            right_sum += nums[right_start];
            right_start--;
        }
        ans[i]=abs(left_sum-right_sum);

       }
       return ans;
    }
};