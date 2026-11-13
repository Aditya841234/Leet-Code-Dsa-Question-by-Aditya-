class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        int LOG = 18;

        vector<int> nxt(n, n);
        vector<int> st;

        // Step 1: Find Next Greater Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) {
                nxt[i] = st.back();
            }

            st.push_back(i);
        }

        // Step 2: Build Binary Lifting Tables
        vector<vector<int>> up(LOG, vector<int>(n, n));

        vector<vector<long long>> sum(
            LOG, vector<long long>(n, 0)
        );

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; j++) {

            for (int i = 0; i < n; i++) {

                int mid = up[j - 1][i];

                if (mid < n) {

                    up[j][i] = up[j - 1][mid];

                    sum[j][i] = sum[j - 1][i]
                              + sum[j - 1][mid];
                }
                else {
                    up[j][i] = n;
                    sum[j][i] = sum[j - 1][i];
                }
            }
        }

        // Step 3: Prefix Sum
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Step 4: Calculate Sum of Prefix Maximums
        auto getMaxSum = [&](int l, int r) {

            long long res = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {

                if (up[j][cur] <= r) {

                    res += sum[j][cur];

                    cur = up[j][cur];
                }
            }

            res += 1LL * nums[cur] * (r - cur + 1);

            return res;
        };

        // Step 5: Binary Search for Every Starting Index
        long long ans = 0;

        for (int l = 0; l < n; l++) {

            int low = l;
            int high = n - 1;
            int best = l - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                long long required =
                    getMaxSum(l, mid) -
                    (pref[mid + 1] - pref[l]);

                if (required <= k) {

                    best = mid;
                    low = mid + 1;
                }
                else {

                    high = mid - 1;
                }
            }

            ans += best - l + 1;
        }

        return ans;
    }
};