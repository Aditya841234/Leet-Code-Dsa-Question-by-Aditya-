class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
      int cl = 1;
      int pl = 0;
      int result = 0;

      for(int i =1; i<nums.size(); i++){
        if(nums[i] > nums[i-1]){
            cl += 1;
        }
        else{
            pl = cl;
            cl =1;
        }
        result = math.max(reult,math.max(cl/2,math.min(cl,pl)));
      }  
     
     return result >= k;
    }
};