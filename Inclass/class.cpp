#include<iostream>
const double E=2.79;
int main()
{
    double ans[21];
    ans[1]=1-1/E;
    std::cout<<ans[1]<<std::endl;
    for(int i=2;i<20;++i){
        ans[i]=1-i*ans[i-1];
        std::cout<<ans[i]<<std::endl;
    }
    return 0;
}