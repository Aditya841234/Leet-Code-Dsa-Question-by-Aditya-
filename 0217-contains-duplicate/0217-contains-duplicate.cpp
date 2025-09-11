class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int last= nums.size();
        sort(nums.begin(),nums.end());
        int x = nums[0];
        sort(nums.begin(),nums.end());
        for(int i = 1; i < last; i++){
            if(nums[i]==x){
                return true;
            }
            else
              x = nums[i];
        }
       return false;
    }
};