#include <iostream>
using std::cin;
bool a[4][4], ok = false;
int ans;
void op(int i, int j) {
    a[i][j] = 1 - a[i][j];
    if (i + 1 < 3)  a[i + 1][j] = 1 - a[i + 1][j];
    if (j + 1 < 3)  a[i][j + 1] = 1 - a[i][j + 1];
    if (i - 1 >= 0)  a[i - 1][j] = 1 - a[i - 1][j];
    if (j - 1 >= 0)  a[i][j - 1] = 1 - a[i][j - 1];
}
void dfs(int k) {
    //if (k > 9)  return;
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)  sum += a[i][j];
    }
    if (sum == 9) { ok = 1;  ans = k - 1;  return; }
    else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                op(i, j);
                dfs(k + 1);
                if (ok)  return;
                op(i, j);
            }
        }
    }
}
int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) 
            cin >> a[i][j];
    }
    dfs(0);
    std::cout << ans << std::endl;
    return 0;
}
//这是有问题的版本，引以为戒