#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
int find1(int (*a),int length);//返回最好空座位的下标
int find2(int (*a),int length);//返回周围有人的空座位的下标
int main()
{
    int seat[2001],book[2001];
    memset(book,-1,sizeof(book));
    memset(seat,-1,sizeof(seat));
    bool change[2001];
    memset(change,false,sizeof(change));
    int n,m,i,j,ans=0;//n人，m座
    cin>>n>>m;
    int a[2001],b[2001];
    for(i=0;i<n;++i) cin>>a[i]>>b[i];
    int time;
    for(i=0;i<n;++i){//遍历人
        time=a[i];
        for(j=0;j<m;++j){//遍历座位
            if(time>seat[j]&&seat[j]>-1){
                seat[j]=-1;
                book[j]=-1;
                change[j]=false;
            }
        }
        int tp,mp;
        if((tp=find1(seat,m))!=-1){
            book[tp]=i;
            seat[tp]=b[i];
        }else if((mp=find2(seat,m))!=-1){
            book[mp]=i;
            b[i]=2*b[i]-a[i];
            seat[mp]=b[i];
            change[mp]=true;
            if(mp<m-1){
                if(book[mp+1]>-1&&change[mp+1]==false){
                    b[book[mp+1]]=2*b[book[mp+1]]-a[book[mp+1]];
                    seat[mp+1]=b[book[mp+1]];
                    change[mp+1]=true;
                }
            }
            if(mp>0){
                if(book[mp-1]>-1&&change[mp-1]==false){
                    b[book[mp-1]]=2*b[book[mp-1]]-a[book[mp-1]];
                    seat[mp-1]=b[book[mp-1]];
                    change[mp-1]=true;
                }
            }
        }else{
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
int find1(int (*a),int length)
{
    if(a[0]==-1&&a[1]==-1)  return 0;
    for(int k=1;k<length-1;++k){
        if(a[k-1]==-1&&a[k]==-1&&a[k+1]==-1)  return k;
    }
    if(a[length-1]==-1&&a[length-2]==-1)  return length-1;
    return -1;
}
int find2(int (*a),int length)
{
    for(int k=0;k<length;++k){
        if(a[k]==-1)  return k;
    }
    return -1;
}