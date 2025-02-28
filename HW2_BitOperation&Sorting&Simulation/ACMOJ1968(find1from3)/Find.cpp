#include <stdio.h>
int count[32];
int num[10000001];
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
    return x*f;
}
int main() {
    int n,ans;
    n = read();
    for(int i = 0; i < n; ++i) {
        num[i] = read();
        for(int j = 0; j < 32; ++j) {
            count[j] += (num[i] >> j)&1;
        }
    }
    ans = 0;
    for(int j = 0; j < 32; ++j) {
        if(count[j] % 3 > 0) {
            ans |= (1 << j);
        }
    }
    printf("%d",ans);
    return 0;
}