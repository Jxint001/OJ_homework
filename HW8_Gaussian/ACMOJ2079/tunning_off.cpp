#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;
int a[105][105], n, m, pvt[105], ans[105], F[105];
ll cntf = 1;
int guass() {
    int c, r = 1, i, j, x;
    for (c = 1; c <= n; ++c) {
        for (i = r, j = r + 1; j <= n; ++j) {
            if (abs(a[j][c]) > abs(a[i][c])) { i = j; }
        }
        if (a[i][c] == 0) { continue; }
        if (i != r) {
            for (j = 1; j <= n + 1; ++j) { swap(a[i][j], a[r][j]); }
        }
        pvt[r] = c;
        for (x = r + 1; x <= n; ++x) {
            int t = a[x][c];
            for (j = c; j <= n + 1; ++j) { a[x][j] ^= (t * a[r][j]); }
        }
        ++r;
    }
    for (i = r; i <= n; ++i) {
        if (a[i][n + 1] != 0) { return -1; }
    }
    return r - 1;
}
void backward() {
    int r = 1, c, i, j;
    for (c = 1; c <= n && r <= n; ++c) {
        if (c != pvt[r]) {
            F[cntf++] = c;
            continue;
        }
        for(i = r - 1; i >= 1; --i) {
            int t = a[i][c];
            for (j = c; j <= n + 1; ++j) { a[i][j] ^= (t * a[r][j]); }
        }
        ++r;
    }
}
void solve(int back) {
    int minsum = INT_MAX;
    ll tr = 1ll << (cntf - 1ll);
    for (ll k = 1; k <= tr; ++k) {
        int c = n, r = back;
        ll cnt = 0;
        while (c >= 1 && r >= 1) {
            if (c == pvt[r]) {
                ans[c] = a[r][n + 1];
                for (int j = n; j > c; --j) {
                    ans[c] = (ans[c] - ans[j] * a[r][j]) % 2;
                }
                if (ans[c] < 0) { ans[c] += 2; }
                --c;  --r;
            } else {
                ++cnt;
                if ((1ll << ll(cnt - 1)) & k) {
                    ans[c] = 1;
                } else {
                    ans[c] = 0;
                }
                --c;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) { sum += ans[i]; }
        minsum = min(minsum, sum);
    }
    cout << minsum << endl;
}
int main() {
    // freopen("test.in","r",stdin);
    // freopen("test.ans","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) { a[i][i] = 1;  a[i][n + 1] = 1;}
    for (int i = 1; i <= m; ++i) {
        static int u, v;
        cin >> u >> v;
        if (a[u][v] ==  0) {
            a[u][v] = 1;
            a[v][u] = 1;
        }
    }
    int back = guass();
    if (back == -1) {
        cout << -1 << endl;
    } else {
        backward();
        solve(back);
    }
    return 0;
}