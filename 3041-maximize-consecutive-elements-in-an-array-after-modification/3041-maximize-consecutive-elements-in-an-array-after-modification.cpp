class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
       sort(nums.begin(), nums.end());

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> dp(maxi + 2, 0);

        int ans = 0;

        for (int x : nums) {

            // Store previous DP values
            int same = dp[x];
            int previous = dp[x - 1];

            // Option 1: Keep x unchanged
            dp[x] = max(dp[x], previous + 1);

            // Option 2: Increase x by 1
            dp[x + 1] = max(dp[x + 1], same + 1);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans; 
    }
};