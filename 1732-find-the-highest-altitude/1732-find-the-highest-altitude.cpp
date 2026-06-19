class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int ans=0;
      int n=gain.size();
      for(int i=1;i<n;i++){
        gain[i]=gain[i-1]+gain[i];
      }  
      for(int i=0;i<n;i++){
        if(gain[i]>=ans){
            ans=gain[i];
        }
      }

      return ans;
    }
};