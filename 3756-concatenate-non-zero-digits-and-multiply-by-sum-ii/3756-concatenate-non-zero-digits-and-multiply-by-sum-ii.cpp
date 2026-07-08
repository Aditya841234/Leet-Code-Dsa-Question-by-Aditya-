class Solution {
public:
  static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
          vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        vector<long long> pref(k + 1, 0);
        vector<long long> digitPref(k + 1, 0);

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 1; i <= k; i++) {
            pref[i] = (pref[i - 1] * 10 + digit[i - 1]) % MOD;
            digitPref[i] = digitPref[i - 1] + digit[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (pref[R + 1] -
                 pref[L] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = digitPref[R + 1] - digitPref[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};