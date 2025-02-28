#include<iostream>
using namespace std;
int dis(int x,int y)
{
    if(x>=y) return x-y;
    else return y-x;
}
int main()
{
    int n,m,k,i,j,f,huo[26][2],shi[6][2],map[101][101]={0},ans=0;//n*n,m火把,k萤石
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>huo[i][0]>>huo[i][1];//输入火把位置
        map[huo[i][0]][huo[i][1]]=1;
    }
    for(i=1;i<=k;i++){
        cin>>shi[i][0]>>shi[i][1];//输入萤石位置
        //map[shi[i][0]][shi[i][1]]=1;
    }
    if(k>0){//萤石照亮
        for(i=1;i<=k;i++){
            for(j=1;j<=n;j++){
                for(f=1;f<=n;f++){
                    if(dis(shi[i][0],j)<=2 && dis(shi[i][1],f)<=2) map[j][f]=1;
                }
            }
        }
    }
    for(i=1;i<=m;i++){//火把照亮
        for(j=1;j<=n;j++){
            for(f=1;f<=n;f++){
                if(dis(huo[i][0],j)+dis(huo[i][1],f)==1 or dis(huo[i][0],j)+dis(huo[i][1],f)==2) map[j][f]=1;
            }
        }
    }
    for(i=1;i<=n;i++){//输出
        for(j=1;j<=n;j++)
            if(map[i][j]==0) ans+=1;
    }
    cout<<ans;
    return 0;
}