#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution {
    const int MOD = 1e9 + 7;
public:
    int numTilings(int n) {
        // f[i] = f[i - 1] + f[i - 2] + 2 * (sum_{j = 0}^{i - 3} f[j]) = 2 * f[i - 1] + f[i - 3]
        vector<long long> f(n + 5, 0);
        f[1] = 1, f[2] = 2, f[3] = 5;
        for (int i = 4; i <= n; ++i) {
            f[i] = (2 * f[i - 1] + f[i - 3]) % MOD;
        }
        return f[n];
    }
};
// @lc code=end

