class Solution {
public:
   
    void combination(vector<int>& arr,int index,int n,vector<int>&tempArr,vector<vector<int>>& ans,int target){
        

        if(target == 0){
            ans.push_back(tempArr);
            return;
        }
        
        for(int i = index;i<n;i++){

             if(i > index && arr[i]==arr[i-1]) continue;

             if(arr[i] > target) break;
            //for removal of duplicate 
            //  combination(arr,index+1,n,tempArr,ans,target);

            //this logic for tacking the element in the ans array 
              tempArr.push_back(arr[i]);
              combination(arr,i+1,n,tempArr,ans,target-arr[i]);
               tempArr.pop_back();
        }
      
        
    }
  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      vector<vector<int>> ans;
      vector<int> tempArr;
      int n = candidates.size();

      combination(candidates,0,n,tempArr,ans,target);
       
      

       return ans;
    }
};