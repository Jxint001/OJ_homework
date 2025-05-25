#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2612 lang=cpp
 *
 * [2612] 最少翻转操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> ban{banned.begin(), banned.end()};
        set<int> indices[2];
        // 建图
        for (int i = 0; i < n; i++) {
            if (i != p && ban.find(i) == ban.end()) {
                indices[i & 1].insert(i);
            }
        }
        indices[0].insert(n); // 哨兵，下面无需判断 it != st.end()
        indices[1].insert(n);

        vector<int> ans(n, -1);
        ans[p] = 0; // 起点
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            // indices[mn % 2] 中的从 mn 到 mx 的所有下标都可以从 i 翻转到
            int mn = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            auto& st = indices[mn & 1];
            for (auto it = st.lower_bound(mn); *it <= mx; it = st.erase(it)) {
                ans[*it] = ans[i] + 1; // 移动一步
                q.push(*it);
            }
        }
        return ans;
    }
};
// @lc code=end

