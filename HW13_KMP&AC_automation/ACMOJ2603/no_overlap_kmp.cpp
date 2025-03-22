#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7, maxn = 1e6+5;
ll fail[maxn], level[maxn]; // offset from epsilon to the node
int n;
char s[maxn];
int main() {
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", s);
        int len = strlen(s), i = 1, j = 0;  // j是后缀末尾之后一个
        fail[0] = 0;  level[0] = 1;
        ll ans = 1;

        for ( ; i < len; ++i) {
            while (j > 0 && s[i] != s[j])  j = fail[j - 1];
            level[i] = level[j] + (s[i]==s[j]);
            j += s[i]==s[j];
            fail[i] = j;
        }

        j = 0;
        for (i = 1; i < len; ++i) {
            while (j > 0 && (s[j] != s[i]))  j = fail[j - 1];
            j += s[i] == s[j];
            while (j >0 && (j << 1) > (i + 1))  j = fail[j - 1];
            if (j > 0) {
                ans = (ans * (level[j-1] + 1)) % MOD;  // level数组多加的一个1可以理解为当前（前缀）字串也是满足要求的字串之一
            cout << "plus " << level[j-1] + 1 <<" j = "<< j << endl;}
        }
        printf("%lld\n", ans);
        
        for (int i = 0; i < len; ++i) {printf("%lld ", fail[i]); } 
        printf("\n");
        for (int i = 0; i < len; ++i) {printf("%lld ", level[i]); }
        printf("\n");
    }
}
