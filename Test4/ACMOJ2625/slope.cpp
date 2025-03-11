#include <climits>
#include <cstdio>
typedef long long ll;
const ll MAXN = 20005;
ll n, w[MAXN], t[MAXN], sumw[MAXN], F[MAXN], s[MAXN], dp[MAXN][2];
inline ll Y(ll k) {return dp[k][0] + F[k]; }
inline ll X(ll k) {return sumw[k]; }
inline ll K(ll i) {return s[i-1]; }
inline long double slope(ll i, ll j) {
    return (Y(i)-Y(j)) / (long double)(X(i)-X(j));
}
int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld%lld", &w[i], &t[i]);
        sumw[i] = sumw[i - 1] + w[i];
        s[i] = s[i - 1] + t[i];
    }
    for (ll i = 1; i <= n; ++i) { 
        F[i] = F[i - 1] + w[i] * s[i - 1];
        dp[i][0] = s[i-1] * sumw[i] - F[i];
    }

    ll que[MAXN], head = 0, tail = 1;
    que[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        while (head + 1 < tail && slope(que[head], que[head+1])<K(i)) {
            ++head;
        }
        ll B = Y(que[head]) - K(i)*X(que[head]);
        dp[i][1] = B + sumw[i]*s[i-1] - F[i];
        while (head + 1 < tail && slope(que[tail-2], que[tail-1]) > slope(que[tail-1], i)) {
            --tail;
        }
        que[tail++] = i;
    }

    ll ans = LONG_LONG_MAX;
    for (ll i = 1; i <= n; ++i) {
        ll candidate = dp[i][1] + s[n]*(sumw[n]-sumw[i]) - F[n] + F[i];
        ans = ans > candidate ? candidate : ans;
    }
     printf("%lld\n", ans);
    return 0;
}