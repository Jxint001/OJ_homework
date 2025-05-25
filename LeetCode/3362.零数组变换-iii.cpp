#include<bits/stdc++.h>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=3362 lang=cpp
 *
 * [3362] 零数组变换 III
 */

// @lc code=start
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<int>  pq;  // 维护左端点 <= i 的右端点的最大堆
        int j = 0, cur = 0, n = nums.size();
        vector<int> diff(n + 5, 0);  // 只维护 -1 （区间右端点）， +1 是随着 cur 变大维护的
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            for (; j < queries.size() && queries[j][0] <= i; ++j) {
                pq.push(queries[j][1]);
            }
            for (; cur < nums[i] && !pq.empty() && pq.top() >= i; ++cur) {
                --diff[pq.top() + 1];
                pq.pop();
            }
            if (cur < nums[i])  return -1;
        }
        return pq.size();
    }
};
// @lc code=end

