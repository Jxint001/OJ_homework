#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int n, m, x, y;
double t;
double f[2004], a[2004][2004], st = 0;
inline void init() {
    for (int i = 2; i <= m - 1; ++i) {
        a[i][i - 1] = 0.25;
        a[i][i] = -0.75;
        a[i][i + 1] = 0.25; 
    }
    a[1][1] = static_cast<double>(-2) / 3;
    a[1][2] = static_cast<double>(1) / 3;
    a[m][m - 1] = static_cast<double>(1) / 3;
    a[m][m] = static_cast<double>(-2) / 3;
}
void eliminate() {
    int c, r = 1, i, j, x;
    for (c = 1; c <= m; ++c) {
        double t = a[r][c];
        for (j = c; j <= min(m + 1, c + 1); ++j) { a[r][j] /= t; }
        if (c + 1 < m + 1) a[r][m + 1] /= t;
        for (x = r + 1; x <= r + 1; ++x) {
            t = a[x][c];
            for (j = c; j <= min(m + 1, c + 1); ++j) { a[x][j] = a[x][j] - t * a[r][j];}
            if (c + 1 < m + 1) a[x][m + 1] = a[x][m + 1] - t * a[r][m + 1];
        }
        ++r;
    }
}
void solve() {
    for (int c = m, r = m; c >= 1; --c, --r) {
        f[c] = a[r][m + 1];
        for (int j = min(m, r + 1); j > c; --j) { f[c] = f[c] - f[j] * a[r][j];}
    }
}
int main() {
    cin >> n >> m >> x >> y;
    if (x == n) {
        cout << fixed << setprecision(5) << 0.00000 << endl;
        return 0;
    }
    if (m == 1) {
        cout << fixed << setprecision(5) << static_cast<double>(2 * (n - x)) << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= m; ++i) {
        a[i][m + 1] = -1;
    }
    const double eps = 0.00001;
    for (int i = 1; i <= n - x; ++i) {
        eliminate();
        solve();
        if (fabs(f[y] - st) < eps) {
            cout << fixed << setprecision(5) << f[y] << endl;
            return 0;
        }
        st = f[y];
        if (i <= n - x - 1) {
            init();
            for (int j = 2; j <= m - 1; ++j) { a[j][m + 1] = -f[j] / 4 - 1; }
            a[1][m + 1] = -f[1] / 3 - 1;
            a[m][m + 1] = -f[m] / 3 - 1;
        }
    }
    cout << fixed << setprecision(5) << f[y] << endl;
    return 0;
}