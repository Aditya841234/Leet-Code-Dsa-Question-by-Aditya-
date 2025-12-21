class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
       if(n<0) return;
       int posZero = 0;
       for(int i =0;i<n;i++){
        if(nums[i] != 0){
            swap(nums[posZero],nums[i]);
            posZero++;
        }
       } 
    }
};