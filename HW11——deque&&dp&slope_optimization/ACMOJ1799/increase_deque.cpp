#include <cstdio>
#include <deque>
constexpr int MAXL = 100005;
int n, cost[MAXL], left[MAXL], right[MAXL];
long long int presum[MAXL];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i]); 
        presum[i + 1] = presum[i] + cost[i];
        right[i] = n;
        left[i] = -1;
    }
    std::deque<int> minl, minr;
    for (int i = 0; i < n; ++i) {
        while (!minl.empty() && cost[minl.front()] >= cost[i]) {
            minl.pop_front();
        }
        if (!minl.empty()) {left[i] = minl.front(); }
        minl.push_front(i);

        while (!minr.empty() && cost[minr.front()] >= cost[n - i - 1]) {
            minr.pop_front();
        }
        if (!minr.empty()) {right[n - i - 1] = minr.front(); }
        minr.push_front(n - i - 1);
    }
    long long int max = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i] + 1;
        int r = right[i] - 1;
        long long int sum = presum[r + 1] - presum[l];
        long long int cur = sum * cost[i];
        max = cur > max? cur: max;
    }
    printf("%lld\n", max);
    return 0;
}