class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize left array---just use 1 array
        vector<int> left(n, 1);
        
        // Fill left array
        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        // Compute the final output using a right running product
        vector<int> output(n);
        int right = 1;
        for(int i = n - 1; i >= 0; i--){
            output[i] = left[i] * right;
            right *= nums[i];
        }
        
        return output;
    }
};
