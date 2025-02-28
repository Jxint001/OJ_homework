#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,num,i,j,ans[1002][1002];
    //左0，右下1，下2，左上3
    int map[4][2]={ 0,-1,
                    1,1,
                    1,0,
                    -1,-1};
    cin>>n;
    //initialization
    for(i=0;i<n+2;++i){
        for(j=0;j<n+2;++j){
            if((1<=i&&i<=n)&&(1<=j&&j<=n)){
                ans[i][j]=0;
            }else{
                ans[i][j]=1;
            }
        }
    }
    int x=1,y=n-1,tx,ty,d=1;//最开始的位置,预储存位置,方向
    ans[1][n]=1;
    for(num=2;num<=(n*n+n)/2;++num){
        ans[x][y]=num;
        tx=x+map[d][0];
        ty=y+map[d][1];
        if(d==0 || d==2){
            d=(d+1)%4;
            x+=map[d][0];
            y+=map[d][1];
        }else if(ans[tx][ty]>0){
            d=(d+1)%4;
            x+=map[d][0];
            y+=map[d][1];
        }else{
            x=tx;
            y=ty;
        }
    }
    ans[n][1]=n*n;
    x=n,y=2,d=1;
    for(num=n*n-1;num>=(n*n+n)/2;--num){
        ans[x][y]=num;
        tx=x-map[d][0];
        ty=y-map[d][1];
        if(d==0 || d==2){
            d=(d+1)%4;
            x-=map[d][0];
            y-=map[d][1];
        }else if(ans[tx][ty]>0){
            d=(d+1)%4;
            x-=map[d][0];
            y-=map[d][1];
        }else{
            x=tx;
            y=ty;
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)
            cout<<setw(9)<<ans[i][j];
        cout<<endl;
    }
    return 0;
}