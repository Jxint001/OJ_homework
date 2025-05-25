#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3342 lang=cpp
 *
 * [3342] 到达最后一个房间的最少时间 II
 */

// @lc code=start
class Solution {
    static constexpr int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int> > dis(n, vector<int>(m, INT_MAX));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<>> pq;
        pq.emplace(0, 0, 0);
        dis[0][0] = 0;

        while (true) {
            auto [curd, x, y] = pq.top();  pq.pop();
            if (x == n - 1 && y == m - 1)  return curd;
            if (curd > dis[x][y])  continue;

            int delta = ((x + y) & 1) + 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0], ny = y + d[i][1];
                if (0 > nx || nx >= n || 0 > ny || ny >= m)  continue;

                int candidate = max(curd, moveTime[nx][ny]) + delta;
                if (dis[nx][ny] > candidate) {
                    dis[nx][ny] = candidate;
                    pq.emplace(candidate, nx, ny);
                }
            }
            
        }

        return dis[n - 1][m - 1];
    }
};
// @lc code=end
