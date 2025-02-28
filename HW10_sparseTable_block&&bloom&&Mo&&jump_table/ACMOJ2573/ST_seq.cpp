#include <cstdio>
#include <cmath>
constexpr int MAXL = 1000005;
int n, m, seq[MAXL], pre0[MAXL], maxd[MAXL][32], lg[MAXL];
void pre(int n) {
    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int k = 1; k <= lg[n]; ++k) {
        for (int i = 0; i + (1 << k) - 1 <= n; ++i) {
            maxd[i][k] = std::max(maxd[i][k - 1], maxd[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int query1(int l, int r) {
    l -= 1;
    int s = lg[r - l + 1];
    return std::max(maxd[l][s], maxd[r - (1 << s) + 1][s]) - pre0[l] + r - pre0[r];
}
int query2(int l, int r) {
    //这有问题?
    if (pre0[r] - pre0[l - 1] < r - l + 1 && pre0[r] - pre0[l - 1] > 0) { //排除全0 or 全1
        //排除11...100...0
        int num0 = pre0[r] - pre0[l - 1];
        if (num0 != pre0[r] - pre0[r - num0]) {return 2; }
    }
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    scanf("%d", &seq[1]);
    pre0[1] += 1 - seq[1];
    maxd[1][0] = 2 * pre0[1] - 1;
    //presum[1] = seq[1];
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &seq[i]);
        pre0[i] = pre0[i - 1] + 1 - seq[i];
        maxd[i][0] = 2 * pre0[i] - i;
        //presum[i] = seq[i] + presum[i - 1];
    }
    pre(n);
    int type, l, r;
    while (m > 0) {
        --m;
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            //printf("ans: ");
            printf("%d\n", query1(l, r));
        }
        if (type == 2) {
            //printf("ans: ");
            printf("%d\n", query2(l, r));
        }
    }
    return 0;
}
// notice that the seq is 0 and 1