#include <iostream>
#include <algorithm>
using std::cin;

bool cmp(int a, int b) {return a > b;}
int a[65], next[65], n, sum, N;
bool suc = 0, book[65];

void dfs(int k, int index, int rest) {
    if (!rest) {
        if (k == n) {suc = 1;  return;}
        else {
            int i = 0;
            while (book[i])  ++i;
            book[i] = 1;
            dfs(k + 1, i, sum / n - a[i]);
            book[i] = 0;
            if (suc) return;
        }
    }
    int l = index + 1, r = N - 1, mid;
    while (l < r) {
        mid = l + ((r - l) >> 1);
        if (a[mid] > rest)  l = mid + 1;
        else r = mid;
    }
    for (int i = l; i < N; ++i) {
        if (book[i])  continue;
        book[i] = 1;
        dfs(k, i, rest - a[i]);
        book[i] = 0;
        if (suc)  return;
        if (rest == a[i] || rest == sum / n)  return;
        i = next[i];
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)  {cin >> a[i];  sum += a[i];}
    std::sort(a, a + N, cmp);
    next[N - 1] = N - 1;
    for (int i = N - 2; i >= 0; --i) {
        if (a[i] == a[i + 1])  next[i] = next[i + 1];
        else next[i] = i;
    }
    for (int len = a[0]; len <= sum / 2; ++len){
        if (sum % len)  continue;
        n = sum / len;
        suc = 0;
        book[0] = 1;
        dfs(1, 0, len - a[0]);
        book[0] = 0;
        if (suc) {std::cout << len << std::endl;  return 0;}
    }
    std::cout << sum << std::endl;
    return 0;
}