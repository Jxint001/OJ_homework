#include<iostream>
using std::cin;
using std::cout;
using std::endl;
//int testf(int);

#include"bracket.hpp"

int main()
{
    int a,b;
    cin>>a;
    b=testf(a);   
    cout<<b<<endl;
    return 0;
}
/*
int testf(int m)
{
    if(m>=10){
        return 0;
    }else{
        return 1;
    }
}
*/