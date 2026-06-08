class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       
       vector<int>small;
       vector<int>equal;
       vector<int>greator;

       for( int el : nums){
          if(el<pivot){
            small.push_back(el);
          }
          else if(el==pivot){
            equal.push_back(el);
          }
          else{
            greator.push_back(el);
          }
       }

       vector<int>ans;

       for(int s:small){
         ans.push_back(s);
       }
       for(int e:equal){
         ans.push_back(e);
       }
        for(int g:greator){
         ans.push_back(g);
       }

       return ans;
    }
};