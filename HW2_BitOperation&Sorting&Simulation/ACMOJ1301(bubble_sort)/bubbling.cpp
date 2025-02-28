#include <iostream>
typedef long long int LL;
LL n, a[1000005], ans[1000005], tmp[1000005];
void Merge (LL* abg, LL* aend, LL* bbg, LL* bend, LL* tmp) {
    int plus = 0;
    while (abg != aend && bbg != bend) {
        if (*bbg < *abg) {
            *tmp = *bbg;
            ans[*bbg] += aend - abg;
            ++bbg;  ++plus;
        } else {
            *tmp = *abg;
            ans[*abg] += plus;
            ++abg;
        }
        ++tmp;
    }
    for ( ; abg != aend; ++abg, ++tmp) { *tmp = *abg;  ans[*abg] += plus;}
    for ( ; bbg != bend; ++bbg, ++tmp) { *tmp = *bbg;}
}
void Sort (LL* a, LL l, LL r) {
    if (r - l <= 1)  return;
    LL mid = l + ((r - l) >> 1);
    Sort(a, l, mid);  Sort(a, mid, r);
    Merge(a + l, a + mid, a + mid, a + r, tmp + l);
    for (int i = l; i < r; ++i) a[i] = tmp[i];
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i)  std::cin >> a[i];
    Sort(a, 1, n + 1);
    for (int i = 1; i <= n; ++i) std::cout << ans[i] << " ";
    std::cout << std::endl;
    return 0;
}