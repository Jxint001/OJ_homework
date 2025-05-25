#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2918 lang=cpp
 *
 * [2918] 数组的最小相等和
 */

// @lc code=start
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int c1 = 0, c2 = 0;
        long long s1 = 0, s2 = 0;
        for (int i : nums1) {
            s1 += i;
            if (!i)  ++s1, ++c1;
        }
        for (int i : nums2) {
            s2 += i;
            if (!i)  ++s2, ++c2;
        }

        if (s1 == s2)  return s1;
        if ((s1 < s2 && !c1) || (s2 < s1 && !c2))  return -1;

        return max(s1, s2);
        
    }
};
// @lc code=end
