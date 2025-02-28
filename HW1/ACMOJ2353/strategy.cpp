#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
void prime_factor(int n);
int factor[32];
int main()
{
    int m,n[11001],i,j;
    cin>>m;
    for(i=0;i<m;++i) cin>>n[i];
    for(i=0;i<m;++i){
        bool flag=0;
        prime_factor(n[i]);
        for(j=0;factor[j]>0&&j<=32;++j){
            if(j>0){
                if(factor[j]==factor[j-1])continue;
            }
            int store=n[i]/factor[j];
            store=n[i]-store+((store%factor[j]==0)?0:(-1));
            if(store%2==0){
                flag=1;
                cout<<"Mio"<<endl;
                break;
            }
        }
        if(flag==0)cout<<"Noah"<<endl;
    }
    return 0;
}
void prime_factor(int n)
{
    int i,k=0;
    for(i=2;i<=sqrt(n);++i){
        while(n%i==0){
            factor[k++]=i;
            n/=i;
        }
    }
    for(i=k;i<=32;++i) factor[i]=0;
}