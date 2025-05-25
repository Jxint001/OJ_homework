#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1550 lang=cpp
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int l = 0, r = 0, n = arr.size();
        bool ok = false;
        for (; r - l <= 2 && r < n;) {
            if (r - l == 2 && arr[r] & 1) {
                ok = true;  break;
            }
            if (arr[r] & 1) {
                ++r;
            } else {
                if (l == r) ++l, ++r;
                else ++r, l = r;
            }
        }

        return ok;
    }
};
// @lc code=end

