#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos1 = -1, pos2 = -1, n = nums.size();
        if (nums[0] == 1)  pos1 = 0;
        if (nums[0] == 2)  pos2 = 0;
        for (int cur = 1; cur < n; ++cur) {
            if (pos1 == -1 && nums[cur] == 1)  pos1 = cur;
            if (pos2 == -1 && nums[cur] == 2)  pos2 = cur;
            if (nums[cur] < nums[cur-1]) {
                if (nums[cur - 1] - nums[cur] == 2) {
                    // nums[cur - 1] = 2, nums[cur] = 0
                    int cp1 = pos1, cp2 = pos2;
                    if (cp1 == -1) {
                        swap(nums[cur], nums[pos2]);
                        pos2 = nums[pos2 + 1] == 2 ? pos2 + 1 : cur;
                    } else {
                        nums[pos1] = 0;  nums[pos2] = 1;  nums[cur] = 2;
                        pos2 = nums[pos2 + 1] == 2 ? pos2 + 1 : cur;
                        pos1 = nums[pos1 + 1] == 1 ? pos1 + 1 : cp2;
                    }
                } else {
                    if (nums[cur] == 1) {
                        swap(nums[cur], nums[pos2]);
                        //if (pos1 == -1)  
                        if (pos1 > pos2)  pos1 = pos2;
                        pos2 = nums[pos2 + 1] == 2 ? pos2 + 1 : cur;
                        
                    } else {
                        swap(nums[cur], nums[pos1]);
                        pos1 = nums[pos1 + 1] == 1 ? pos1 + 1 : cur;
                    }
                }
            }
        }
    }
};
// @lc code=end

