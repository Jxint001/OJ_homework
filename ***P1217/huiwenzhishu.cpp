//回文质数
/*
#include<iostream>
#include<cmath>
using namespace std;
bool huiwen(int);
bool isprime(int);
int main()
{
    int a,b,i;
    cin>>a>>b;
    for(i=a;i<=b;i++){
        if(huiwen(i)){
            if(isprime(i)) cout<<i<<endl;
        }
    }

}
bool huiwen(int p)
{
    int ans=0,r=p,;
    while(p){
        ans=ans*10+p%10;
        p/=10;
    }
    if(ans==r) return true;
    else return false;
}
bool isprime(int q)
{
    int flag=1;
    for(int j=2;j<=sqrt(q);j++){
        if(q%j==0){
            flag=0;
            break;
        }
    }
    if(flag==1) return true;
    else return false;
}
*/

//所有偶数位数的回文数都是11的整数倍（除了11）
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
//bool prime[10000000];这个是配套埃氏筛选法
bool prime[10000000];
int store[10000000];
bool huiwen[10000000];
void primechart(int);
void huiwenchart();
int min(int,int);
//bool huiwen(int);

int main()
{
    int a,b,i;
    cin>>a>>b;
    if(b>9999999) b=9999999;
    a=min(a,b);
    primechart(b);
    huiwenchart();
    if(a%2==0) a++;
    for(i=a;i<=b;i+=2){
        if(prime[i]&&huiwen[i]){
            cout<<i<<endl;
        }
    }
}
/*
void primechart(int b)//埃氏筛选法
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i<=b;i++){
        if(prime[i]==true){
            for(int j=2;j<=b/i;j++){
                prime[i*j]=false;
            }
        }
    }
}
*/
//欧式筛选,避免重复排除一个大数
//i为合数，j[]为质数，当i=p*j[x](j[x]为最小因数),则任意i*j[q](q为大于x的任意有意义数)，都会在未来被j[x]*j[q]筛选到
void primechart(int b)
{
    int k=0;
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=b;++i){
        if(prime[i]==true)  store[k++]=i;
        for(int j=0;i*store[j]<=b&&j<k;++j){
            prime[i*store[j]]=false;
            if(i%store[j]==0) break;//这句之所以放在后面是为了让质数的平方被判断为合数，如9
        }
        
    }
}

void huiwenchart()//回文数表
{
    memset(huiwen,false,sizeof(huiwen));
    huiwen[11]=true;
    for(int d1=1;d1<=9;d1+=2){
        huiwen[d1]=true;
        for(int d2=0;d2<=9;d2++){
            huiwen[d1*100+d2*10+d1]=true;
            for(int d3=0;d3<=9;d3++){
                huiwen[d1*10000+d2*1000+d3*100+d2*10+d1]=true;
                for(int d4=0;d4<=9;d4++){
                    huiwen[d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1]=true;
                }
                
            }
           
        }
    }
}

int min(int a,int b){
    
    return (a<b)?a:b;
}