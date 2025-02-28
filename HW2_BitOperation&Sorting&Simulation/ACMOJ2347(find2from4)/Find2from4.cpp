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
    int n=read();
    int h1 = 0,h2 = 0;
    for(int i = 0; i < n; ++i) {
        int num = read();
        h1 = (h2 & num) ^ h1;
        h2 = h2 ^ num;
    }
    printf("%d",h1);
    return 0;
}
/*
四位计算器：
h1  h2
0   0   c0
0   1   c1
1   0   c2
1   1   c3
只有只出现2次的数的是1位会停留在c2，其余均从c0出发又回到c0
*/