class Solution {
public:

    void combination(vector<int>& arr,vector<vector<int>>& ans,vector<int>&tempArr ,int index , int n, int target){
     

      if(target==0){
        ans.push_back(tempArr);
        return;
      }
   
   
      if(index >= n || target<0) return;
     //if we are not selected the element
       
     
        combination(arr,ans,tempArr,index+1,n,target);
        //when we are tacking the element as our need than we have to insert in the temp arr
 
         tempArr.push_back(arr[index]);
         combination(arr,ans,tempArr,index,n,target-arr[index]);
         tempArr.pop_back();
    
    }




    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>>ans;
      vector<int>tempArr;
      int n = candidates.size();
      combination(candidates,ans,tempArr,0,n,target);
      return ans;
    }
};