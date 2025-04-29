#include <climits>
#include <cstdio>
#include <queue>
//#include <iostream>

struct State{
    int x, y, pushdir, steps; // 都是描述箱子的
};
int m, n, tx, ty, sx, sy, bx, by;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char g[105][105];
int visitbox[105][105];
const int maxn = 4e4 + 4;

inline bool in(int x, int y) {
    if (x >= m || x < 0 || y >= n || y < 0)  return false;
    return true;
}

bool reachable(int a, int b, int nbx, int nby,int px, int py) {
    //std::cout << "in reach" << std::endl;
    if (px == a && py == b)  return true;
    int qx[maxn], qy[maxn], head = 0, tail = 0;
    qx[tail] = px, qy[tail] = py, ++tail;
    bool visit[105][105];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)  visit[i][j] = 0;

    visit[px][py] = true;
    while (head < tail) {
        int x = qx[head], y = qy[head];  ++head;
        if (x == a && y == b)  return true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!in(nx, ny) || g[nx][ny] == '#' || (nx == nbx && ny == nby))  continue;
            if (!visit[nx][ny]) {
                visit[nx][ny] = true;
                qx[tail] = nx, qy[tail] = ny, ++tail;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &g[i][j]);
            switch (g[i][j]) {
                case 'T': tx = i; ty = j;  break;
                case 'B': bx = i; by = j;  break;
                case 'S': sx = i; sy = j;  break;
                default: break;
            }
        }
    }
    std::queue<State> q;
    // 初始化，最开始能往哪里推
    for (int i = 0; i < 4; ++i) {
        int needpx = bx - dir[i][0], needpy = by - dir[i][1], nx = bx + dir[i][0], ny = by + dir[i][1];
        if (!in(needpx, needpy) || g[needpx][needpy] == '#')  continue;
        if (reachable(needpx, needpy, bx, by, sx, sy)) {
            if (nx == tx && ny == ty) {
                printf("1\n");
                return 0;
            }
            visitbox[bx][by] |= 1 << i;
            q.push({nx, ny, i, 1});
        }
    }

    while (!q.empty()) {
        State cur = q.front();  q.pop();
        int p_x = cur.x - dir[cur.pushdir][0], p_y = cur.y - dir[cur.pushdir][1];
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1], needpx = cur.x - dir[i][0], needpy = cur.y - dir[i][1];
            if (!in(nx, ny) || !in(needpx, needpy))  continue;
            if (g[nx][ny] == '#' || g[needpx][needpy] == '#')  continue;
            if (!reachable(needpx, needpy, cur.x, cur.y, p_x, p_y))  continue;

            if (visitbox[nx][ny] & 1 << i)  continue;
            if (nx == tx && ny == ty) {
                printf("%d\n", cur.steps + 1);
                return 0;
            }
            visitbox[nx][ny] |= 1 << i;
            q.push({nx, ny, i, cur.steps + 1});
        }
    }
    printf("-1\n");
}