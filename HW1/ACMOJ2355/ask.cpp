#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    double H[50],ans[101];
    double D,E,F;
    int a[50],c[50],m,i,j,k=0;//k用来记录ans下标;
    cin>>m>>H[0]>>D>>E>>F;
    if(H[0]>D || H[0]<=F){
        cout<<"GIVEUP"<<endl;
        return 0;
    }
    for(i=1;i<=m+1;++i) cin>>a[i]>>c[i];
    c[0]=0;
    for(i=1;i<=m+1;++i){
        H[i]=H[i-1]+a[i]*(c[i]-c[i-1]);
        if(H[i]<=D&&H[i]>F) continue;
        if(H[i]<=F){
            cout<<"GIVEUP"<<endl;
            return 0;
        }//还剩下H[i]>D的情况
        double time=c[i-1]+(D-H[i-1])/a[i];
        while(H[i]>D){
            H[i]-=E;
            if(H[i]<=F){
                cout<<"GIVEUP"<<endl;
                return 0;
            }
            ans[k]=time;
            ++k;
            if(H[i]<=D) break;
            time+=E/a[i];
        }
    }
    cout<<"KEEPUP"<<endl<<k<<endl;
    for(i=0;i<k;++i)cout<<ans[i]<<endl;
    return 0;
}