# include <cstdio>
# include <deque>
int n, m, ans, sx, sy, tx, ty;
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }, map[26][2];
char g[305][305];
bool vis[305][305];
struct State{
    int x, y, step;
};

int main() {
     // initalize map
    for (int i = 0; i < 26; ++i) {
        map[i][0] = map[i][1] = -1;
    }
    // input
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == '@')  sx = i, sy = j;
            else if (g[i][j] == '=')  tx = i, ty = j;
            else if ('A' <= g[i][j] && g[i][j] <= 'Z') {
                int c = g[i][j] - 'A';
                map[c][map[c][0] != -1] = i * m + j;
            }
        }
    }
    // BFS
    std::deque<State> q;
    q.push_back({sx, sy, 0});  vis[sx][sy] = true;

    while (!q.empty()) {
        auto cur = q.front();  q.pop_front();
        int x = cur.x, y = cur.y, step = cur.step;

        if (x == tx && y == ty) {
            printf("%d\n", step);
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if (g[nx][ny] == '#')  continue;

            if ('A' <= g[nx][ny] && g[nx][ny] <= 'Z') {
                int c = g[nx][ny] - 'A', a, b;
                int x0 = map[c][0] / m, y0 = map[c][0] % m;
                int x1 = map[c][1] / m, y1 = map[c][1] % m;
                if (nx == x0 && ny == y0)  a = x1, b = y1;
                else if (nx == x1 && ny == y1) a = x0, b = y0;
                else a = nx, b = ny;
                if (!vis[a][b]) {
                    vis[a][b] = true;
                    q.push_back({a, b, step + 1});
                }
                continue;
            }
            if (vis[nx][ny])  continue;
            vis[nx][ny] = true;
            q.push_back({nx, ny, step + 1});
            
        }
    }
    return 0;
}