#include <climits>
#include <cstdio>
#include <deque>
//#include <iostream>
int a, b, n, dif[105], grid[1005][1005];
int rowmax[1005][1005], rowmin[1005][1005], max[1005][1005], min[1005][1005];

int main() {
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            scanf("%d", &grid[i][j]);
    for (int i = 0; i < a; ++i) {  //row
        std::deque<int> dq; //decrease
        for (int j = 0; j < b; ++j) {
            if (!dq.empty() && dq.front() <= j - n) {dq.pop_front(); }
            while (!dq.empty() && grid[i][dq.back()] <= grid[i][j]) {dq.pop_back(); }
            dq.push_back(j);
            if (j >= n - 1) {rowmax[i][j - n + 1] = grid[i][dq.front()]; }
        }
    }
    for (int i = 0; i < a; ++i) {  //row
        std::deque<int> dq; //increase
        for (int j = 0; j < b; ++j) {
            if (!dq.empty() && dq.front() <= j - n) {dq.pop_front(); }
            while (!dq.empty() && grid[i][dq.back()] >= grid[i][j]) {dq.pop_back(); }
            dq.push_back(j);
            if (j >= n - 1) {rowmin[i][j - n + 1] = grid[i][dq.front()]; }
        }
    }
    for (int j = 0; j <= b - n; ++j) {
        std::deque<int> dq;  //decrease
        for (int i = 0; i < a; ++i) {
            if (!dq.empty() && dq.front() <= i - n) {dq.pop_front(); }
            while (!dq.empty() && rowmax[dq.back()][j] <= rowmax[i][j]) {dq.pop_back(); }
            dq.push_back(i);
            if (i >= n - 1) {max[i - n + 1][j] = rowmax[dq.front()][j]; }
        }
    }
    for (int j = 0; j <= b - n; ++j) {
        std::deque<int> dq;  //increase
        for (int i = 0; i < a; ++i) {
            if (!dq.empty() && dq.front() <= i - n) {dq.pop_front(); }
            while (!dq.empty() && rowmin[dq.back()][j] >= rowmin[i][j]) {dq.pop_back(); }
            dq.push_back(i);
            if (i >= n - 1) {min[i - n + 1][j] = rowmin[dq.front()][j]; }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= a - n; ++i) {
        for (int j = 0; j <= b - n; ++j) {
            //std::cout << max[i][j] << " " << min[i][j] << std::endl;
            if (max[i][j] - min[i][j] < ans) {ans = max[i][j] - min[i][j]; }
        }
    }
    printf("%d\n", ans);
    return 0;
}