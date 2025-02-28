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
    int s1=0,s2=0,n;
    n = read();
    for(int i = 0; i < n; ++i) {
        int num = read();
        s1 = ~s2 & (s1 ^ num);
        s2 = ~s1 & (s2 ^ num);
    }
    printf("%d",s1);
    return 0;
}