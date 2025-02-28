#include <iostream>
using std::cin, std::cout, std::endl;
int ans;
bool a[4][4];
void op(int x,int y)
{
    a[x][y]=1 - a[x][y];
    a[x+1][y]=1 - a[x+1][y];
    a[x][y+1]=1 - a[x][y+1];
    a[x-1][y]=1 - a[x-1][y];
    a[x][y-1]=1 - a[x][y-1];
}
int m = 10;
void dfs(int k) {
    if (k > m)  return;
    int s = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)  s += a[i][j];
    }
    if (s == 9) {
        ans = k - 1;
        m = ans;
        return;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            op(i, j);
            dfs(k + 1);
            op(i, j);
        }
    }
    return;
}
int main() {
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            if (!a[i][j])  ++cnt;
        }
    }
    if (!cnt) { cout << 0 << endl;  return 0; }
    dfs(1);
    cout << ans << endl;
    return 0;
}