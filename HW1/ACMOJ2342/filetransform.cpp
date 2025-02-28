#include<iostream>
using namespace std;
int main()
{
    int ch;
    ch=getchar();
    while(char(ch)!=EOF){
        if(char(ch)!='\r') cout<<char(ch);
        ch=getchar();
    }
    return 0;
}