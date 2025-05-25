#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (const int& i : nums) {
            if ((i / 10 != 0 && i / 100 == 0) || (i / 1000 != 0 && i / 10000 == 0) || (i / 100000 != 0 && i / 1000000 == 0)) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

