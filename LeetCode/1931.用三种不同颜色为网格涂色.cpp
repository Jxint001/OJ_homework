#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1931 lang=cpp
 *
 * [1931] 用三种不同颜色为网格涂色
 */

// @lc code=start
class Solution {
    const int MOD = 1e9 + 7;
public:
    int colorTheGrid(int m, int n) {
        vector<int> pow3(m + 5);
        pow3[0] = 1;
        for (int i = 1; i <= m; ++i) {
            pow3[i] = pow3[i-1] * 3;
        }

        vector<int> valid;
        for (int color = 0; color < pow3[m]; ++color) {
            bool ok = true;
            // 检查这种着色是否符合同列相邻颜色不一样的要求
            for (int i = 1; i < m; ++i) {
                if (color / pow3[i] % 3 == color / pow3[i-1] % 3) {
                    ok = false;  break;
                }
            }
            if (ok)  valid.push_back(color);
        }

        // 收集当前列着色是 color 的时候，左右的列可以选择的着色
        int all = valid.size();
        vector<vector<int> > nxt(all + 5);
        for (int i = 0; i < all; ++i) {
            for (int j = 0; j < all; ++j) {
                bool ok = true;
                for (int k = 0; k < m; ++k) {
                    if (valid[i] / pow3[k] % 3 == valid[j] / pow3[k] % 3) {
                        ok = false;  break;
                    }
                }
                if (ok)  nxt[i].push_back(j);
            }
        }

        // 开始按列递推，只和前一列有关系
        // f[i][j]:= 递推到当前，m * (i-1) 的网格，第 i 列填的是 valid[j] 时的方案数
        vector<vector<int> > f(n + 5, vector<int> (all, 0));
        for (int& i : f[0])  i = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < all; ++j) {
                for (int k : nxt[j]) {
                    f[i][j] = (f[i][j] + f[i-1][k]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j < all; ++j) {
            ans += f[n-1][j];
        }
        return ans % MOD;
    }
};
// @lc code=end

