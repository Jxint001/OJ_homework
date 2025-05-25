#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 *
 * [3335] 字符串转换后的长度 I
 */

// @lc code=start
class Solution {
    const int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<vector<long long> > dp(26, vector<long long>(2, 0));
        for (auto& w : s)  ++dp[w - 'a'][0];

        for (int turn = 1; turn <= t; ++turn) {
            int idx = turn & 1;
            dp[0][idx] = dp[25][idx ^ 1];
            dp[1][idx] = (dp[25][idx ^ 1] + dp[0][idx ^ 1]) % MOD;
            for (int i = 2; i < 26; ++i) {
                dp[i][idx] = dp[i - 1][idx ^ 1];
            }
        }

        long long ans = 0;
        for (int i = 0, idx = t & 1; i < 26; ++i) {
            ans += dp[i][idx];
        }
        return ans % MOD;
    }
};
// @lc code=end

