#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2900 lang=cpp
 *
 * [2900] 最长相邻不相等子序列 I
 */

// @lc code=start
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n + 5, 0), pre(n + 5, -1);
        int end = 0, maxval = 1;
        
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > maxval) {
                        end = i;  pre[i] = j;
                    }
                }
            }
        }

        vector<string> path;
        path.push_back(words[end]);
        for (int cur = pre[end]; cur != -1; cur = pre[cur]) {
            path.push_back(words[cur]);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
// @lc code=end

