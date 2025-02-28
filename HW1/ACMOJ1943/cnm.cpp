#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int  t[100000];
    int i=0,j,n;
    while(cin>>n){
        t[i]=n;
        ++i;
    }
    for(j=i-1;j>=0;--j){
        cout<<t[j]<<endl;
    }
    return 0;
}