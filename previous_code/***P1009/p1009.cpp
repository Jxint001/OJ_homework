//ans=1!+2!+...+n!
#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,store[50][100]={0},ans[100]={0};
    cin>>n;
	//把每组阶乘存储在第0行到第n-1行的数组中
	for(k=0;k<n;++k){//从第一到第n个阶乘
		store[k][0]=1;
		for(i=2;i<=k+1;++i){//乘数
			for(j=0;j<100;++j){//位数
				store[k][j]*=i;//如果无需进位，则数组的后面（相当于数字的前面）全是0
			}
			for(j=0;j<100;++j){//进位（往后/右进位）
				if(store[k][j]>9){
					store[k][j+1]+=store[k][j]/10;
					store[k][j]%=10;
				}
			}
		}
	}
    //加起来
	for(k=0;k<n;++k){
		for(i=0;i<100;++i){
			ans[i]+=store[k][i];
		}
		for(i=0;i<100;++i){
			if(ans[i]>9){
				ans[i+1]+=ans[i]/10;
				ans[i]%=10;
			}
		}
	}
	//输出
	bool flag=0;
	for(i=99;i>=0;--i){
		if(ans[i]>0) flag=1;
		if(flag) cout<<ans[i];
	}
    return 0;
}
/*
from xjq
#include <iostream>
using namespace std;

int main()
{
	int n, i, j, k, a[50][65] = {0}, result[66] = {0};
	bool flag = false;
	cin >> n;
	for (k = 0; k < n; ++k){
		a[k][0] = 1;
		for (i = 2; i <= k + 1; ++i){
			for (j = 0; j < 65; ++j){
				a[k][j] *= i;
			}
			for (j = 0; j < 65; ++j){
				if (a[k][j] > 9){
					a[k][j + 1] += a[k][j] / 10;
					a[k][j] = a[k][j] % 10;
				}
			}
		}
	}
	
	for (j = 0; j < 65; ++j){
		for(k = 0; k < n; ++k){
			result[j] += a[k][j];
		} 
	}
	for (j = 0; j < 65; ++j){
		if (result[j] > 9){
			result[j + 1] += result[j] / 10;
			result[j] = result[j] % 10;
		}
	}
	for (j = 65; j >= 0; --j){
		if (result[j] != 0) flag = true;
		if (flag) cout << result[j];
	}
	
	return 0;
}
*/