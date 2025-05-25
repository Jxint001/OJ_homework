#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
// 太复杂了
// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         long long ans = 0;
//         for (auto& p : dominoes) {
//             if (p[0] > p[1])  swap(p[0], p[1]);
//         }
//         sort(dominoes.begin(), dominoes.end(), [](const vector<int>& a, const vector<int>& b) {
//             return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
//         });
//         int n = dominoes.size();
//         for (int i = 0; i < n;) {
//             int j = i;
//             while (j + 1 < n && dominoes[j][0] == dominoes[j+1][0] && dominoes[j][1] == dominoes[j+1][1]) {
//                 ++j;
//             }
//             long long cnt = j - i + 1;
//             ans += cnt * (cnt - 1) >> 1;
//             i = j + 1;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        int cnt[10][10] = {};
        for (auto& q : dominoes) {
            int a = min(q[0], q[1]);
            int b = a == q[0] ? q[1] : q[0];
            ans += cnt[a][b];
            ++cnt[a][b];
        }
        return ans;
    }
};
// @lc code=end

