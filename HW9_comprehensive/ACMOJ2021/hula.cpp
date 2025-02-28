#include <iostream>
using namespace std;
int a[30], s = 0;
bool ok = false;
bool check(int x) {
    return x + 2 <= 9 || (x > 9 && x < 17) || (x > 18 && x < 26);
}
void dfs(int x) {
    if (s == 4) { ok = true;  return; }
    if (x >= 28) { return; }
    if (a[x] == 0) {
        while (!a[x]) { ++x; }
        dfs(x);
        if (ok) { return; }
    }
    if (a[x] >= 3) {
        a[x] -= 3;  s += 1;
        dfs(x);
        a[x] += 3;  s -= 1;
        if (ok) { return; }
    }
    if ((a[x] >= 1 && (x < 26 && a[x + 1] >= 1 && a[x + 2] >= 1)) && check(x)) {
        a[x] -= 1;  a[x + 1] -= 1;  a[x + 2] -= 1;  s += 1;
        dfs(x);
        a[x] += 1;  a[x + 1] += 1;  a[x + 2] += 1;  s -= 1;
        if (ok) { return; }
    }
}
int main() {
    for (int i = 0; i < 14; ++i) {
        static string str;
        cin >> str;
        switch (str[1]) {
            case 'A': ++a[str[0] - '0'];  break;
            case 'B': ++a[9 + (str[0] - '0')];  break;
            case 'C': ++a[18 + (str[0] - '0')];  break;
            default: break;
        }
    }
    for (int i = 1; i <= 27; ++i) {
        if (a[i] >= 2) {
            a[i] -= 2;
            s = 0;
            dfs(1);
            a[i] += 2;
        }
        if (ok) {
            cout << "True" << endl;
            return 0;
        }
    }
    cout << "False" << endl;
    return 0;
}