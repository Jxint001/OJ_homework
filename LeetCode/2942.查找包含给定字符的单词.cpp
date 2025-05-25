#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2942 lang=cpp
 *
 * [2942] 查找包含给定字符的单词
 */

// @lc code=start
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> num;
        int idx = 0;
        for (const string& w : words) {
            for (const char& ch : w) {
                if (ch == x) {
                    num.push_back(idx);
                    break;
                }
            }
            ++idx;
        }
        return num;
    }
};
// @lc code=end

