class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i =0; i<n;i++){


            int increase = 1;
            int j = i+1;

            while( j < n && nums[j] > nums[j-1]){
                increase++;
                j++;
            }

            int decrease = 1;
            j = i+1;

            while(j < n && nums[j] < nums[j-1]){
                decrease++;
                j++;
            }

           result = max({result,increase,decrease});
        }
      
      return result;
    }
};