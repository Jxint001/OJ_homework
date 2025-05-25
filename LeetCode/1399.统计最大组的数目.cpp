#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> cnt;
        int mg = 0;
        for (int num = 1; num <= n; ++num) {
            int group = num % 10 + (num / 10) % 10 + (num / 100) % 10 + (num / 1000) % 10 + (num / 10000) % 10;
            ++cnt[group];
            if (cnt[group] > mg)  mg = cnt[group];
        }

        int ans = 0;
        for (auto& p : cnt) {
            if (p.second == mg)  ++ans;
        }
        return ans;
    }
};
// @lc code=end

