class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
       int n = nums.size();

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(
                vals.begin(), vals.end(), nums[i]
            ) - vals.begin();
        }

        // Build suffix array using doubling
        vector<int> sa(n), temp(n);

        iota(sa.begin(), sa.end(), 0);

        for (int len = 1; len < n; len *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + len < n) ? rank[a + len] : -1;
                int rb = (b + len < n) ? rank[b + len] : -1;

                return ra < rb;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                bool different =
                    rank[a] != rank[b] ||
                    (a + len < n ? rank[a + len] : -1) !=
                    (b + len < n ? rank[b + len] : -1);

                temp[b] = temp[a] + different;
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // Kasai's algorithm: calculate LCP
        // lcp[i] = LCP(sa[i], sa[i - 1])
        vector<int> lcp(n, 0);

        int k = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) {
                k = 0;
                continue;
            }

            int j = sa[p - 1];

            while (i + k < n && j + k < n &&
                   nums[i + k] == nums[j + k]) {
                k++;
            }

            lcp[p] = k;

            if (k > 0)
                k--;
        }

        // Find the minimum unique subarray length
        int ans = n;

        for (int p = 0; p < n; p++) {

            int common = 0;

            if (p > 0)
                common = max(common, lcp[p]);

            if (p + 1 < n)
                common = max(common, lcp[p + 1]);

            int required = common + 1;

            if (required <= n - sa[p]) {
                ans = min(ans, required);
            }
        }

        return ans; 
    }
};