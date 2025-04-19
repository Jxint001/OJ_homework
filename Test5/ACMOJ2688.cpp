#include <cstdio>
const int maxn = 1e6 + 5;
int next[maxn], n;  // next[i] 是最长前后缀相同下标
char s[maxn];
void pre() {
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {j = next[j-1]; }
        if (s[i] == s[j]) {++j; }
        next[i] = j;
    }
}
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    pre();
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", next[i]);
    // }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        int t = i - next[i] + 1;
        if (i + 1 == t) {printf("%d\n", t); }
        else {printf("%d\n", (t - next[i]) % t);}
    }
    return 0;
}