#include <cstdio>
#include <deque>
int n, k, a[2000005], ans[1000005];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i < n + k; ++i) {
        a[i] = a[i - n];
    }
    std::deque<int> dq;
    for (int i = 0; i < n + k; ++i) {
        if (!dq.empty() && dq.front() < i - k + 1) {dq.pop_front(); }
        while (!dq.empty() && a[dq.back()] <= a[i]) {dq.pop_back(); }
        dq.push_back(i);
        if (i >= k - 1) {ans[i - k + 1] = a[dq.front()]; }
    }
    for (int i = 0; i < n; ++i) {printf("%d ", ans[i]); }
    printf("\n");
    return 0;
}