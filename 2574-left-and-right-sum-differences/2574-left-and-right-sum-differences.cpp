class Solution {
public:
    void Sum_Difference(vector<int>& arr,int index,int n,int left_sum,int total_sum,vector<int>&ans,int right_sum){
       if(index==n){
          return;
       }
        
        right_sum=total_sum-left_sum-arr[index];
        ans[index]=abs(left_sum-right_sum);
        Sum_Difference(arr,index+1,n,left_sum+arr[index],total_sum,ans,right_sum);
    }
    vector<int> leftRightDifference(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       int total_sum=0;
       for(int i=0;i<nums.size();i++){
        total_sum += nums[i];
       }
       Sum_Difference(nums,0,nums.size(),0,total_sum,ans,0);
       return ans;
    }
};