#include<iostream>
using namespace std;
int main()
{
    int n,i;
    char opr[100000];
    long long int A[100000],B[100000];
    cin>>n;
    for(i=0;i<n;++i){
        cin>>opr[i]>>A[i]>>B[i];
    }
    for(i=0;i<n;++i){
        if(opr[i]=='+'){
            cout<<A[i]+B[i]<<endl;
        }
        if(opr[i]=='*'){
            cout<<A[i]*B[i]<<endl;
        }
    }
    return 0;
}