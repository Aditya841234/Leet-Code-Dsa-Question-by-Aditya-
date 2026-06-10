class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int>tempArr(n);
        // tacking number who that will be first of the array 
        for(int j=n-k;j<n;j++){
           tempArr[j-(n-k)]=nums[j];
        }

        // tacking the reaming on the end of the array 
        for(int i =0;i<n-k;i++){
            tempArr[k+i]=nums[i];
        }

        //copy the all the element from the tempArr to actual array
        for(int i=0;i<n;i++){
            nums[i] = tempArr[i];
        }
        
    }
};