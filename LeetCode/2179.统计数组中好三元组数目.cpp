#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2179 lang=cpp
 *
 * [2179] 统计数组中好三元组数目
 */

// @lc code=start
class Solution {
public:
    class SegmentTree {
    private:
        vector<long long> tree;
        int n;

    public:
        SegmentTree(int size) {
            n = 1;
            while (n < size) {
                n <<= 1;
            }
            tree.resize(2 * n, 0);  // 建成2的幂次大小好算叶子节点
        }
        void update(int pos, int val) {
            pos += n; // 转换为叶子节点的位置
            tree[pos] += val;
            for (pos >>= 1; pos >= 1; pos >>= 1) {  // 从下到上O(logn)
                tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
            }
        }
        long long query(int l, int r) {
            l += n;
            r += n;
            long long ans = 0;
            while (l <= r) {
                if (l % 2 == 1) {
                    ans += tree[l];
                    l++;
                }
                if (r % 2 == 0) {
                    ans += tree[r];
                    r--;
                }
                // 向上一层
                l >>= 1;
                r >>= 1;
            }
            return ans;
        }
    };
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> perm(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            perm[nums1[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            nums1[i] = perm[nums2[i]];
        }
        // 对新的 nums1 进行操作

        long long ans = 0;
        SegmentTree tr(n);
        tr.update(nums1[0], 1);
        for (int i = 1; i < n - 1; ++i) {
            long long less = tr.query(0, nums1[i] - 1);
            ans += less * (n - 1 - nums1[i] - i + less);
            tr.update(nums1[i], 1);
        }
        return ans;
    }
};
// @lc code=end

