class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int opr = 0;
         for(int num : nums){
            opr = (opr+(num%k))%k
         }
         return opr;
          }
};