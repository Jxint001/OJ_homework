#include<iostream>
using std::cin;
using std::cout;
using std::endl;
bool book[961];
int main()
{
    int m,n,i,j,k=0,x[961],y[961];//x,y记录学生位置
    cin>>m>>n;
    char map[31][31];

    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            cin>>map[i][j];
            if(map[i][j]!='.'){
                x[k]=i;
                y[k]=j;
                k+=1;
            }
        }
    }
    for(i=0;i<k;++i){//查看是否有同行/同列的人
        for(j=i+1;j<k;++j){
            if(x[i]==x[j]||y[i]==y[j]){
                book[i]=true;
                book[j]=true;
            }
        }
    }
    for(i=0;i<k;++i){//没有同行/同列则没办法
        if(book[i]==false){
            cout<<-1<<endl;
            return 0;
        }
    }
    int ans=0;
    for(i=0;i<k;++i){//只用xi,yi来生成坐标就行，xj,yj只是遍历查找
        bool flag=1;
        for(j=0;j<k;++j){
            if((x[i]==x[j]&&y[i]<y[j]&&map[x[i]][y[i]]=='D')||(x[i]==x[j]&&y[j]<y[i]&&map[x[i]][y[i]]=='A')
            ||(y[i]==y[j]&&x[i]<x[j]&&map[x[i]][y[i]]=='S')||(y[i]==y[j]&&x[j]<x[i]&&map[x[i]][y[i]]=='W')){
                flag=0;
            }
        }
        ans+=flag;
    }
    cout<<ans<<endl;
    return 0;
}