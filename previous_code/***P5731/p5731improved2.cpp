//蛇形方阵         不对这个不行！！！！！！
#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int a[20][20];
    a[1][1]=1;
    int num;
    //如果该方向没超且方向正确，继续填写.!...表示未赋值？
    for(i=1,j=1,num=1;num<n*n;){
        while(!a[i][j+1]&&j+1<=n){a[i][j+1]=++num; ++j;}//right
        while(!a[i+1][j]&&i+1<=n){a[i+1][j]=++num; ++i;}//down
        while(!a[i][j-1]&&j-1>=1){a[i][j-1]=++num; --j;}//left
        while(!a[i-1][j]&&i-1>=1){a[i-1][j]=++num; --i;}//up
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++)
            if(a[i][j]<10) cout<<"  "<<a[i][j];
            else cout<<" "<<a[i][j];
        cout<<endl;
    }
    return 0;
}
