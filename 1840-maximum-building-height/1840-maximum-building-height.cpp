class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
         
        //this is the actual restriction array that store restriction of height of the building 
        vector<vector<int>>arr;
        arr.push_back({1,0});
        for(auto &x:restrictions){
            arr.push_back(x);
        }  

        //now we have the all restriction height of the building 

        arr.push_back({n,INT_MAX});
        sort(arr.begin(),arr.end());
        int m = arr.size();// this the actualll array size that we have 

        // this is the find the difference fo the height 
        for(int i=1;i<m;i++){
            int d = arr[i][0]-arr[i-1][0];
            arr[i][1]=min(arr[i][1],arr[i-1][1]+d);
        }

       for(int i=m-2;i>=0;i--){
         int d = arr[i+1][0]-arr[i][0];
          arr[i][1]=min(arr[i][1],arr[i+1][1]+d);
       }
     
       int ans = 0;
       for(int i =1;i<m;i++){
        int d = arr[i][0]-arr[i-1][0];
        ans = max(ans, (arr[i][1]+arr[i-1][1]+d)/2);
       }
      return ans;

    }
};