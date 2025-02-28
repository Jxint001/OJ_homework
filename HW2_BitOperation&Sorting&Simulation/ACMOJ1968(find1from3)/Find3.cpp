#include <stdio.h>
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read() {
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
    int n,h1 = 0,h2 = 0;
    n = read();
    for(int i = 0; i < n; ++i) {
        int num = read();
        h2 = (h2 ^ num) & (~h1);
        h1 = (h1 ^ num) & (~h2);
    }
    printf("%d",h2);
    return 0;
}
/*
三位计算器：
h1  h2
0   0   c0
0   1   c1
1   0   c2
只有只出现一次的数的是1位会停留在c1，其余均从c0出发又回到c0
*/