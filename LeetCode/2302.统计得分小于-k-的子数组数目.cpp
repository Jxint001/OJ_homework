#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0, ans = 0;

        for (int right = 0, left = 0; right < n; ++right) {
            sum += nums[right];
            while (left > 0 && (right - left +  1) * sum <= k) {
                --left;
                sum += nums[left];
            }
            while (left <= right && (right - left +  1) * sum >= k) {
                sum -= nums[left];
                ++left;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end

