#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3024 lang=cpp
 *
 * [3024] 三角形类型
 */

// @lc code=start
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2])  return "none";
        
        if (nums[0] == nums[1]) {
            if (nums[1] == nums[2])  return "equilateral";
            else  return "isosceles";
        } else if (nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
};
// @lc code=end

