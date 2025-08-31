class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int start=0; last=nums.size()-1,mid;
        mid=start+(last-start)/2
        while(start<end){
            if(nums[mid]==original){
                original=2*original;
            }
            else if(nums[mid]<original){
                start++;
            }
            else
            end--;
        }
        return original;
    }
};