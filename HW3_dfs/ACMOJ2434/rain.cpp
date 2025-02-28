#include <algorithm>
#include <iostream>
typedef long long int ll;
bool used[1000005];
int h[1000005], n;
int lmax[1000005], rmax[1000005];
ll ans = 0;
void choose() {
    lmax[0] = h[0];
    rmax[n - 1] = h[n - 1];
    for (int i = 1; i < n; ++i)  lmax[i] = std::max(lmax[i - 1], h[i]);
    for (int i = n - 2; i >= 0; --i)  rmax[i] = std::max(rmax[i + 1], h[i]);
}
void read() {
    char ch = std::getchar();
    int k = 0;
    while (ch != ']') {
        int x = 0; bool d = 0;
        while ('0' <= ch && ch <= '9') {
            d = 1;
            x = x * 10 + ch - '0';
            ch = std::getchar();
        }
        if (d == 1) { 
            h[k] = x; ++k;
        }
        if (ch == ']')  break;
        ch = std::getchar();
    }
}
int main() {
    std::cin >> n;
    std::getchar();
    read();
    if (n - 2 == 0) { std::cout << 0 << std::endl;  return 0; }
    choose();
    for (int i = 0; i < n; ++i)  ans += std::min(lmax[i], rmax[i]) - h[i];
    std::cout << ans << std::endl;
    return 0;
}