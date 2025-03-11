#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int n, m, arr[MAXN], lg[MAXN], pre0[MAXN], st[MAXN][32];

inline void build(int n) {
    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i <= n; ++i) {
        lg[i] = lg[i>>1] + 1;
    }
    for (int k = 1; k <= lg[n]+1; ++k) {
        for (int i = 0; i + (1 << k) - 1 <= n; ++i) {
            st[i][k] = max(st[i][k-1], st[i+(1<<(k-1))][k-1]);
        }
    }
}
int read(){
    char ch=0;
    int w=1,num=0;
    while(ch<'0' or ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0' and ch<='9'){
        num=num*10+(ch-'0');
        ch=getchar();
    }
    return num*w;
}
void write(int num){
    int top=0;
    int sta[65];
    do{
        sta[top++]=num%10;
        num/=10;
    }while(num);
    while(top) putchar(sta[--top]+'0');
}

int main() {
    n = read(), m = read();
    for(int i = 1; i <= n; i++) {
        arr[i] = read();
        pre0[i] = pre0[i-1] + 1 - arr[i];
        st[i][0] = 2 * pre0[i] - i;
    }
    //st[0][0] = 1;
    build(n);
    int ql, qr;
    for(int i = 1; i <= m; i++) {
        ql = read(), qr = read();
        --ql;
        int ans, s = lg[qr-ql];
       //cout << max(st[ql][s], st[qr-(1<<s)+1][s]) << endl;
        ans = max(st[ql][s], st[qr-(1<<s)+1][s]) + qr - pre0[qr] - pre0[ql];
        //cout << "ans: ";
        write(ans);
        putchar('\n');
    }
//     cout << lg[8] << endl;
// cout << st[0][3] << " " << 8 - pre0[8] - pre0[0] << endl;
// cout << st[1][3] << endl;
    //cout << st[1][1] << " " << st[2][1];
    //for (int i = 1; i <= n; ++i) {cout << pre0[i] << " ";}

    return 0;
}