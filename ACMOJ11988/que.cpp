#include<iostream>
#include<deque>
using namespace std;
deque<int>card;
struct newtype{//存储操作
	char c[10000];
	int num[10000];
    int xnum[10000];
    int ynum[10000];
};

int main(){
    newtype opr;
    int N,M,i,j,store[1000000];
    cin>>N;
    for(i=0;i<N;++i){
        cin>>store[i];
        card.push_back(store[i]);
    }
    cin>>M;
    int dnum=0,abc=0;//dnum记录D的次数,abc记录A/B/C的次数
    for(i=0;i<M;++i){
        cin>>opr.c[i];
        if(opr.c[i]=='D'){
            cin>>opr.xnum[dnum]>>opr.ynum[dnum];
            dnum+=1;//下一次输入的下标
        }else{
            cin>>opr.num[abc];
            abc+=1;
        }
    }
    int tp=0;//C D循环时存储第一个数
    int dt=-1,abct=-1;//分别记录D和A/B/C已完成的总操作次数-1
    bool found=false;
    for(i=0;i<M;++i){
        switch(opr.c[i]){
            case 'A'://插入队首
                abct+=1;
                card.push_front(opr.num[abct]);
                break;
            case 'B'://插入队尾
                abct+=1;
                card.push_back(opr.num[abct]);
                break;
            case 'C'://查找并删除第一个
                abct+=1;    found=false;
                //循环一遍，返回正常序列的队列，同时完成操作
                for(j=0;j<card.size();++j){
                    if((card.front()==opr.num[abct])&&(found==false)){
                        found=true;
                        tp=card.front();
                        card.erase(card.begin());
                        j-=1;
                        //it=card.begin()+x;
                        //card.erase(it);
                    }else{
                        tp=card.front();
                        card.erase(card.begin());
                        card.push_back(tp);
                    }
                }
                break;
            case 'D'://第一张x后面加个y（若有x)
                dt+=1;  found=false;
                for(j=0;j<card.size();++j){
                    if(card.front()==opr.xnum[dt]&&found==false){
                        found=true;
                        tp=card.front();
                        card.erase(card.begin());
                        card.push_back(tp);
                        card.push_front(opr.ynum[dt]);
                        //j-=1;
                        //it=card.begin()+x;
                        //card.erase(it);
                    }else{
                        tp=card.front();
                        card.erase(card.begin());
                        card.push_back(tp);
                    }
                }
                break;
            default:break;
        }
    }
    int size=card.size();
    cout<<size<<endl;
        /*
        deque<int>::iterator it;
        it=card.begin();
        for(i=0;i<card.size();++i){
            cout<<*it<<" ";
            it+=1;
        }
        cout<<endl;
        */
    for(i=0;i<size;++i){
        cout<<card.front()<<" ";
        card.erase(card.begin());
    }
    cout<<endl;
    
    return 0;
}