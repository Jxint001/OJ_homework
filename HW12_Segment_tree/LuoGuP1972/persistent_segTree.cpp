#include <cstdio>
typedef long long ll;
constexpr ll MAXN = 1e5+5;
ll n, m, a[MAXN];
inline void read(ll& ret) {
    ret = 0;
    ll f = 1;
    char cur = getchar();
    while(cur < '0' || cur > '9') {
		if(cur == '-') f = -1;
		cur = getchar();
	}
    while ('0' <= cur && cur <= '9') {
        ret = ret * 10 + (cur - '0');
        cur = getchar();
    }
    ret *= f;
}

int main() {
    read(n);
    for (ll i = 1; i <= n; ++i) {read(a[i]); }
    read(m);
    ll l, r; 
    while (m-- > 0) {
       read(l);  read(r);
    }
    //printf("%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n", n, m, a[1], a[2], l, r);
}