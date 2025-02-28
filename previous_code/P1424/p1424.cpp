#include<iostream>
using namespace std;
int main()
{
    //周x，n天,250/天,s公里
    int x,n,s;
    cin>>x>>n;
    s=0;
    for(int i=0;i<n;i++){
        int w=x;
        w = (w+i)%7;
        //cout<<w;
        if(w!=0 && w!=6) s +=250;
        //cout<<s;
    }
    cout<<s;
    return 0;
}