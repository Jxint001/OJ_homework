#include <bits/stdc++.h>
#include <climits>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2901 lang=cpp
 *
 * [2901] 最长相邻不相等子序列 II
 */

// @lc code=start
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto valid = [](string& a, string& b) -> bool {
            int sa = a.length(), sb = b.length();
            if (sa != sb)  return false;
            int cnt = 0;
            for (int i = 0; i < sa; ++i) {
                if (a[i] != b[i]) {
                    ++cnt;
                    if (cnt > 1)  return false;
                }
            }
            if (!cnt)  return false;
            return true;
        };

        int n = words.size(), end = 0;
        vector<int> pre(n + 5, -1);
        vector<int> dp(n + 5, 0);  // 第 i 位之前（含 i ）最长的子序列长度 =: dp[i]
        int maxval = 1;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && valid(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                    if (dp[i] > maxval) {
                        maxval = dp[i];  end = i;
                    }
                }
            }
        }
        
        vector<string> path;
        path.push_back(words[end]);
        for (int cur = end; pre[cur] != -1; cur = pre[cur]) {
            path.push_back(words[pre[cur]]);
        }
        reverse(path.begin(), path.end());
        return path;
    }

};
// @lc code=end

