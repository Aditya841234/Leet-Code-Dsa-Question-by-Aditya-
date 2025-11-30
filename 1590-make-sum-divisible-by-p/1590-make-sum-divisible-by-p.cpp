#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll n = nums.size(), sm = 0;

        for(auto x : nums) sm += x;

        ll rem = sm % p;
        if(rem == 0) return 0;
        ll pref = 0, ans = n;
        unordered_map<ll,ll> mp; // pref , ind
        mp[0] = -1;

        for( int i = 0; i<n; i++){
            pref = (pref + nums[i]) %p;
            if(mp.count ((pref - rem + p)%p) > 0){
               ans = min(ans, i - mp[(pref - rem + p)%p]) ;
            }
            mp[pref] = i;
        }
        if(ans == n) return -1;
        return ans;
    }
};