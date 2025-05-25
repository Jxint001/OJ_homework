#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 *
 * [2094] 找出 3 位偶数
 */

// @lc code=start
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());

        vector<int> nums;
        vector<bool> used(1000, 0);
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0)  continue;
            for (int j = 0; j < n; ++j) {
                if (j == i)  continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j)  continue;
                    if (digits[k] & 1)  continue;
                    int candidate = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (!used[candidate]) {
                        used[candidate] = true;
                        nums.push_back(candidate);
                    }
                }
            }
        }
        return nums;
    }
};
// @lc code=end

