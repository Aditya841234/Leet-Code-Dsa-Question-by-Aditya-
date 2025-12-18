class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans;
       int first = 0,second = 0;
       int n1 = nums1.size();
       int n2 = nums2.size();
       bool Flag = false;
       while(first < n1){
         for(int second = 0; second < n2-1; second++){
            if(nums1[first]==nums2[second] && nums2[second+1]>nums1[first]){
                ans.push_back(nums2[second+1]);
                Flag = true;
            }
          }
         if(Flag == false){
            ans.push_back(-1);
         } 
         else{
            Flag = false;
         } 
         
         first++;

        } 

      return ans;
    }
};