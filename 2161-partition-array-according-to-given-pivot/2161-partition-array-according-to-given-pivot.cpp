class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       
      int countleft = 0,pivotcount = 0,greator =0;
     //finding count of the number
      for(int i =0;i<nums.size();i++){
        if(nums[i]<pivot){
            countleft++;
        }
        else if(nums[i]==pivot){
            pivotcount++;
        }
        else{
            greator++;
        }
      }
     //now i am going to store answer in another vector
      vector<int>ans(nums.size(),0);
       int l=0,e=countleft,g=countleft+pivotcount;
       for(int j=0;j<nums.size();j++){
         if(nums[j]<pivot){
            ans[l]=nums[j];
            l++;
         }
         else if(nums[j]==pivot){
            ans[e]=nums[j];
            e++;
         }
         else{
            ans[g]=nums[j];
            g++;
         }
       }
      return ans;
    }
};