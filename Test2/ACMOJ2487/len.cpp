#include <climits>
#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;
int n, a[100003], f[100003], book[100003], pos[100003];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        book[i] = 0;
    }
    if (f[1] == 1) {cout << 1 << endl;  return 0;}

    int l = INT_MAX, r = INT_MIN;
    book[1] = 1;
    for (int i = 1; i <= n; ++i) {
        int mid = l + (r - l) / 2;
        l = std::min(l, pos[i]);
        r = std::max(r, pos[i]);
        ++book[r - l + 1];
    }
    for (int i = 2; i <= n; ++i) {
        book[i] += book[i - 1];
        if (f[i] < book[i]) {cout << i << endl;  return 0;}
    }
    cout << 0 << endl;
    return 0;
}