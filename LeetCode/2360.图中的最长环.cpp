#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2360 lang=cpp
 *
 * [2360] 图中的最长环
 */

// @lc code=start
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1, t = 1;  // 从 t = 1 时刻开始
        vector<int> visTime(n + 5, 0);

        for (int i = 0; i < n; ++i) {
            int node = i, startTime = t;
            for (; node != -1 && !visTime[node]; node = edges[node]) {visTime[node] = t++; }
            if (node != -1 && startTime <= visTime[node]) {
                ans = max(ans, t - visTime[node]);
            }
        }
        return ans;
    }
};
// @lc code=end

