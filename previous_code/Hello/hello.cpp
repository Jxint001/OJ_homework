#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
const int PI=3;
const char unchange='L';
#include"newtype.hpp"
int main()
{
    char name='A';
    string NAME="ABC";
    cout<<"hello"<<endl<<name<<endl;
    cout<<int(name)<<endl;
    cout<<NAME<<endl;
    cout<<unchange<<endl;
    //cout<<int(NAME);
    int n;
    n=2147483647;
    cout<<n<<endl<<PI<<endl;
    cout<<ONE<<" "<<TWO<<endl;
    cout<<-5%3<<endl;
    int a=9,b=3;
    cout<<fixed<<setprecision(2)<<double(a)/double(b)<<endl;//整除后浮点也自动保留成整数,需要用fixed setprecision（n）头文件iomanip
    int m=10    ;
    m/=10;
    cout<<m<<endl;
    char happy[10];
    for(int i=0;i<7;i++){
        cin>>happy[i];
    }
    cout<<happy[6]<<endl;
    char STR[100]="hello";
    char STR1[2][100];
    strcpy(STR1[0],STR);
    cout<<STR1[0];
    cout<<"hello";
    return 0;
}