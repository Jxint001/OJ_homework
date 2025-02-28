#include <iostream>
using namespace std;
int s[11][11], c;
bool check(int x, int y) {
    for (int i = 1; i <= 9; ++i) {
        if (s[x][y] == s[x][i] && y != i) { return false; }
        if (s[x][y] == s[i][y] && x != i) { return false; }
    }
    int row, col;
    row = (x - 1) / 3;
    col = (y - 1) / 3;
    for (int i = row * 3 + 1; i <= row * 3 + 3; ++i) {
        for (int j = col * 3 + 1; j <= col * 3 + 3; ++j) {
            if (s[x][y] == s[i][j] && !((x == i) && (y == j))) {
                return false;
            }
        }
    }
    return true;
}
void dfs(int x, int y) {
    if (!c) {
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 9; ++j) {
                cout << s[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0); 
    }
    if (s[x][y] != 0) {
        while (s[x][y] != 0) {
            if (y == 9) {
                y = 1;  ++x;
            } else {
                ++y;
            }
        }
    }
    --c;
    for (int num = 1; num <= 9; ++num) {
        s[x][y] = num;
        if (check(x, y)) {
            dfs(x, y);
        }
    }
    ++c;
    s[x][y] = 0;
}
int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> s[i][j];
            if (s[i][j] == 0)  ++c;
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}