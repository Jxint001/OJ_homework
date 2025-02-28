#include<iostream>
using namespace std;
int main()
{
    int i,j,n,lamp[2000001]={0};//n次操作,最多2000000盏灯
    cin>>n;
    int t[5001];
    double a[5001];
    for(i=0;i<n;i++) cin>>a[i]>>t[i];
    for(i=0;i<n;i++){
        for(j=1;j<=t[i];j++){
            lamp[int(a[i]*j)]=1-lamp[int(a[i]*j)];
        }
    }
    for(i=1;i<=2000000;i++){
        if(lamp[i]==1){
            cout<<i;
            break;
        }
    }
    return 0;
}