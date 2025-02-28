#include<iostream>
using namespace std;
int main()
{
    
    int s,v,t;
    cin >> s >> v;
    if(s%v==0) t = s/v+10;
    else t = s/v+11;
    int h,m,H,M;
    m = t%60;
    h = t/60;
    H = 8-h;
    if(m!=0) H-=1;
    if(H<0) H+=24;
    if(m!=0)M = 60-m;
    if(m==0)M = 0;
    if(H<10 && M<10){
        cout << 0 << H << ":" <<0<<M;
    }else if(H<10 && M>9){
        cout<<0<<H<<":"<<M;
    }else if(H>9 && M<10){
        cout<< H <<":"<<0<<M;
    }else{
        cout<< H <<":"<<M;
    }
    return 0;
}
/*
void op(int a,int b)
{
    if(a<10 && b<10){
        cout << 0 << a << ":" <<0<<b;
    }else if(a<10 && b>9){
        cout<<0<<a<<":"<<b;
    }else if(a>9 && b<10){
        cout<< a <<":"<<0<<b;
    }else{
        cout<< a <<":"<<b;
    }
    
}
*/
/*
    int s,v,time;
    cin>>s>>v;
    if(s%v==0) time = s/v+10;
    else time = s/v+11;
    int H,M;
    H = time/60;
    M = time%60;
    
    if(H<=8 && M>69)  cout<<0<<8-H<<":"<<60-M;
    if(H>8 && M>69)  cout<<31-H<<":"<<60-M;
    if(H<=8 && M<70)  cout<<0<<7-H<<":"<<0<<60-M;
    if(H>8 && M<70)  cout<<31-H<<":"<<0<<60-M;
    */