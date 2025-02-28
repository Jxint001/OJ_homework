#include<iostream>
using namespace std;
int main(){
    int n,i,j,num=65;
    cin>>n;
    char cht[2001][2001];
    for(i=1;i<=n;++i){
        for(j=1;j<=2*n-1;++j){
            if(j>=n-i+1 && j<=n+i-1){
                cht[i][j]=char(num);
                num+=1;
                if(num==91) num=65;
            }else{
                cht[i][j]=' ';
            }
                
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=2*n-1;++j){
            putchar(cht[i][j]);
        }
        cout<<endl;
    }
    return 0;
}