class Solution {
public:
    void Permutation(vector<int>& arr,vector<vector<int>>&ans,int index){
        if(index==arr.size()){
            ans.push_back(arr);
            return;
        }


        vector<bool>uses(21,0);
        for(int i= index;i<arr.size();i++){
            if(uses[arr[i]+10]==0){
                swap(arr[index],arr[i]);
                Permutation(arr,ans,index+1);
                swap(arr[index],arr[i]);
                uses[arr[i]+10]=1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        Permutation(nums,ans,0);
        return ans;
    }
};