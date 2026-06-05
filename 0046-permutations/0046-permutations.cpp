class Solution {
public:
   void permutations(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,vector<int>visitors){
      if(visitors.size()==temp.size()){
        ans.push_back(temp);
        return;
      }
    
      for(int i=0;i<visitors.size();i++){
        if(visitors[i]==0){
            visitors[i]=1;
            temp.push_back(arr[i]);
            permutations(arr,ans,temp,visitors);
            visitors[i]=0;
            temp.pop_back();
        }
      }
   }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int>temp;
       vector<int>visitors(nums.size(),0);
      permutations(nums,ans,temp,visitors);
      return ans;
    }
};