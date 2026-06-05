class Solution {
public:
    void Subset(vector<int>& arr,int index,int n,vector<vector<int>>& ans,vector<int>&temp){
        //termination condition 
        if(index==n){
            ans.push_back(temp);
            return;
        }

        
        //no 
        Subset(arr,index+1,n,ans,temp);
     //yes
        temp.push_back(arr[index]);
       Subset(arr,index+1,n,ans,temp);
       temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>temp;
        Subset(nums,0,nums.size(),ans,temp);
        return ans;
    }
};