#include<iostream>
#include<math.h>
using namespace std;
struct node{
    int val,l,r,fa;
}t[10001];
int N,M,top=1,root=-1;
void Insert(int num,int id){
    if(root==-1){
        t[top].val=num;
        t[top].l=-1;
        t[top].r=-1;
        t[top].fa=-1;
        root=top;
        top++;
        return ;
    }
    if(num<t[id].val){
        if(t[id].l==-1){
            t[top].val=num;
            t[top].l=-1;
            t[top].r=-1;
            t[top].fa=id;
            t[id].l=top;
            top++;
            return ;
        }
        Insert(num,t[id].l);
    }
    else{
        if(t[id].r==-1){
            t[top].val=num;
            t[top].l=-1;
            t[top].r=-1;
            t[top].fa=id;
            t[id].r=top;
            top++;
            return ;
        }
        Insert(num,t[id].r);
    }
}
void Delete(int num,int id){
    if(num==t[id].val){
        if(t[id].l==-1&&t[id].r==-1){
            if(t[id].fa!=-1){
                if(t[t[id].fa].l==id) t[t[id].fa].l=-1;
                else t[t[id].fa].r=-1;
            }
            if(id==root) root=-1;
            return ;
        }
        if(t[id].l!=-1){
            int x=t[id].l;
            if(t[x].r==-1){
                if(t[id].r!=-1){
                    t[t[id].r].fa=x;
                    t[x].r=t[id].r;
                }
                t[x].fa=t[id].fa;
                if(t[id].fa!=-1){
                    if(t[t[id].fa].l==id) t[t[id].fa].l=x;
                    else t[t[id].fa].r=x;
                }
            }
            else{
                while(t[x].r!=-1) x=t[x].r;
                if(t[x].l!=-1){
                    t[t[x].l].fa=t[x].fa;
                    t[t[x].fa].r=t[x].l;
                }
                t[x].l=t[id].l;
                t[t[id].l].fa=x;
                if(t[id].r!=-1){
                    t[x].r=t[id].r;
                    t[t[id].r].fa=x;
                }
                t[x].fa=t[id].fa;
                if(t[t[id].fa].l==id) t[t[id].fa].l=x;
                else t[t[id].fa].r=x;
            }
            if(id==root) root=x;
        }
        else{
            int x=t[id].r;
            if(t[x].l==-1){
                if(t[id].l!=-1){
                    t[t[id].l].fa=x;
                    t[x].l=t[id].l;
                }
                t[x].fa=t[id].fa;
                if(t[id].fa!=-1){
                    if(t[t[id].fa].l==id) t[t[id].fa].l=x;
                    else t[t[id].fa].r=x;
                }
            }
            else{
                while(t[x].l!=-1) x=t[x].l;
                if(t[x].r!=-1){
                    t[t[x].r].fa=t[x].fa;
                    t[t[x].fa].l=t[x].r;
                }
                t[x].r=t[id].r;
                t[t[id].r].fa=x;
                if(t[id].l!=-1){
                    t[x].l=t[id].l;
                    t[t[id].l].fa=x;
                }
                t[x].fa=t[id].fa;
                if(t[t[id].fa].l==id) t[t[id].fa].l=x;
                else t[t[id].fa].r=x;
            }
            if(id==root) root=x;
        }
    }
    else{
        if(num<t[id].val) Delete(num,t[id].l);
        else Delete(num,t[id].r);
    }
}
bool Find(int num,int id){
    if(num==t[id].val) return true;
    if(num<t[id].val){
        if(t[id].l!=-1) return Find(num,t[id].l);
        return false;
    }
    if(t[id].r!=-1) return Find(num,t[id].r);
    return false;
}
void All(int id){
    if(root==-1) return;
    if(t[id].l!=-1) All(t[id].l);
    cout<<t[id].val<<' ';
    if(t[id].r!=-1) All(t[id].r);
}
int main(){
    ios_base::sync_with_stdio(false);
    int i,inp,x;
    string com;
    cin>>N>>M;
    for(i=1;i<=N;i++){
        cin>>inp;
        Insert(inp,root);
    }
    for(i=1;i<=M;i++){
        cin>>com;
        if(com=="Insert"){
            cin>>x;
            Insert(x,root);
        }
        if(com=="Delete"){
            cin>>x;
            Delete(x,root);
        }
        if(com=="Find"){
            cin>>x;
            if(Find(x,root)==true) cout<<"True"<<endl;
            else cout<<"False"<<endl;
        }
        if(com=="All"){
            All(root);
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}