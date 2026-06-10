class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
       // we have alternative method to solve the problem like using stl from the sorting and reversing

       reverse(nums.begin(),nums.end()-k);

        // ereversing the element whoes are greater than the n-k element 

        reverse(nums.begin()+(n-k),nums.end());

        //reversing the all array for the answer 

        reverse(nums.begin(),nums.end());
    }
};