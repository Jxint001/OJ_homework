#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;
int main() {
    int n, m;
    long long money = 0;
    cin >> n >> m;
    int a[m], b[n];
    for (int i = 0; i < n; ++i) { cin >> b[i];}
    for (int i = 0; i < m; ++i)  cin >> a[i];
    std::sort(a, a + m);
    std::sort(b, b + n);
    int j = 0, i = 0;

    while (j < n && i < m) {
        if (a[i] <= b[j]) {
            money += b[j];
            ++i;
        }
        ++j;
    }
    if (i < m) {
        cout << -1 << endl;
        return 0;
    }
    cout << money << endl;
    return 0;
}  