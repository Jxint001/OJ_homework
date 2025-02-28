//蛇形方阵
#include<iostream>
using namespace std;
int main()
{
    int n,d=0,i,j;
    cin>>n;
    int a[20][20];
    for(i=0;i<n+2;i++){
        for(j=0;j<n+2;j++)
            if((1<=i&&i<=n)&&(1<=j&&j<=n)) a[i][j]=0;
            else a[i][j]=1;
    }
    a[1][1]=1;
    int flag=0;
    i=j=1;
    while(flag<=n*n+9){
        switch(d){
            case(0)://right
                if(a[i][j+1]==0){
                    a[i][j+1]=a[i][j]+1;
                    j+=1;
                    break;
                }else{
                    d+=1; 
                    [[fallthrough]];
                }
            case(1)://down
                if(a[i+1][j]==0){
                    a[i+1][j]=a[i][j]+1;
                    i+=1;
                    break;
                }else{
                    d+=1;
                    [[fallthrough]];
                }
            case(2)://left
                if(a[i][j-1]==0){
                    a[i][j-1]=a[i][j]+1;
                    j-=1;
                    break;
                }else{
                    d+=1;
                    [[fallthrough]];
                }
            case(3)://up
                if(a[i-1][j]==0){
                    a[i-1][j]=a[i][j]+1;
                    i-=1;
                    break;
                }else{
                    d+=1;
                    [[fallthrough]];
                }
            default:break;
        }
        d%=4;
        flag=flag+1;
    }//如果转到case3才把d+1，循环次数会增多一次，以此类推，一共几层就会多几次
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++)
            if(a[i][j]<10) cout<<"  "<<a[i][j];
            else cout<<" "<<a[i][j];
        cout<<endl;
    }
    return 0;
}