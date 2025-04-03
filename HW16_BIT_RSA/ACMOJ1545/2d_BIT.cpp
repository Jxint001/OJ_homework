#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXM = 3005;
const int MAX_U = 6005;
int m, n, U_size;
int arr[MAXM][MAXM], tree[MAX_U][MAX_U];

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

// 坐标变换：原点 (x,y) 转换到新坐标 (U, V)  U = x+y-1,  V = x-y+n
inline void transform(int x, int y, int &U, int &V) {
    U = x + y - 1;
    V = x - y + n;
}

void add(int U, int V, int d) {
    for (int i = U; i <= U_size; i += i & -i) {
        for (int j = V; j <= U_size; j += j & -j) {
            tree[i][j] += d;
        }
    }
}

// 返回 (1,1) 到 (U, V) 的和
ll query(int U, int V) {
    ll ret = 0;
    for (int i = U; i > 0; i -= i & -i) {
        for (int j = V; j > 0; j -= j & -j) {
            ret += tree[i][j];
        }
    }
    return ret;
}

// 返回 (U1,V1) 到 (U2,V2) 的和
ll retmj(int U1, int V1, int U2, int V2) {
    if(U1 > U2 || V1 > V2) return 0;
    return query(U2, V2) - query(U1 - 1, V2) - query(U2, V1 - 1) + query(U1 - 1, V1 - 1);
}

int main(){
    m = read();
    n = read();
    U_size = m + n - 1;

    for (int y = 1; y <= n; y++){
        for (int x = 1; x <= m; x++){
            int val = read();
            arr[x][y] = val;
            int U, V;
            transform(x, y, U, V);
            add(U, V, val);
        }
    }
    
    int flag;
    while (scanf("%d", &flag) != EOF) {
        if(flag == 1){
            int x = read(), y = read(), d = read();
            arr[x][y] += d;
            int U, V;
            transform(x, y, U, V);
            add(U, V, d);
        } else {
            int x = read(), y = read(), a = read();
            int U0, V0;
            transform(x, y, U0, V0);
            int U1 = max(1, U0 - a);
            int U2 = min(U_size, U0 + a);
            int V1 = max(1, V0 - a);
            int V2 = min(U_size, V0 + a);
            ll ans = retmj(U1, V1, U2, V2);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
