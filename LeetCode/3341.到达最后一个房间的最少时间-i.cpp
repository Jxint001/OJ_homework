#include <bits/stdc++.h>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=3341 lang=cpp
 *
 * [3341] 到达最后一个房间的最少时间 I
 */

// @lc code=start
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int> > dis(n, vector<int>(m, INT_MAX));
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        auto in = [m, n](int a, int b) -> bool {
            return 0 <= a && a < n && 0 <= b && b < m;
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<>> pq;
        pq.emplace(make_tuple(0, 0, 0));
        dis[0][0] = 0;

        while (!pq.empty()) {
            auto [x, y, curd] = pq.top();  pq.pop();
            if (curd > dis[x][y])  continue;
            if (x == n - 1 && y == m - 1)  return curd;

            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0], ny = y + d[i][1];
                if (!in(nx, ny))  continue;

                int candidate = max(dis[x][y], moveTime[nx][ny]) + 1;
                if (dis[nx][ny] > candidate) {
                    dis[nx][ny] = candidate;
                    pq.emplace(make_tuple(nx, ny, candidate));
                }
            }
            
        }

        return dis[n - 1][m - 1];
    }
};
// @lc code=end
