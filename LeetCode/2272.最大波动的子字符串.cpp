#include <bits/stdc++.h>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode.cn id=2272 lang=cpp
 *
 * [2272] 最大波动的子字符串
 */

// @lc code=start
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        int f0[26][26] = {}, f1[26][26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)  f1[i][j] = INT_MIN;
        }

        for (char ch : s) {
            ch -= 'a';
            
            for (int i = 0; i < 26; i++) {
                if (i == ch) {
                    continue;
                }
                
                f0[ch][i] = max(f0[ch][i], 0) + 1;
                f1[ch][i]++;
                
                f1[i][ch] = f0[i][ch] = max(f0[i][ch], 0) - 1;
                ans = max(ans, max(f1[ch][i], f1[i][ch]));
            }
        }
        return ans;
    }
};
// @lc code=end

