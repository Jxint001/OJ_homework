//蛇形方阵
#include<iostream>
using namespace std;
int MOVE[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
    int d=0,n,x=1,y=1,num,tempx,tempy,i,j;
    int a[15][15];
    cin>>n;
    for(i=0;i<n+2;i++){
        for(j=0;j<n+2;j++)
            if((1<=i&&i<=n)&&(1<=j&&j<=n)) a[i][j]=0;
            else a[i][j]=1;
    }
    for(num=1;num<=n*n;num++){
        a[x][y]=num;
        tempx=x+MOVE[d][0];  tempy=y+MOVE[d][1];
        if(tempx<1 || tempx>n || tempy<1 || tempy>n || a[tempx][tempy]>0)  d=(d+1)%4;
        x+=MOVE[d][0],y+=MOVE[d][1];
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++)
            if(a[i][j]<10) cout<<"  "<<a[i][j];
            else cout<<" "<<a[i][j];
        cout<<endl;
    }
    return 0;
}
/* from xjq

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num[9][9] = {0}, n, j = 0, k = 0, judge = 0;
	cin >> n;
	for (int i = 1; i <= n*n; ++i){
		num[j][k] = i;
		switch (judge){
			case 0: k++; break;
			case 1: j++; break;
			case 2: k--; break;
			case 3: j--; break;
		}
		if (k >= n || k < 0 || j >= n || j < 0 || num[j][k] != 0){
			switch (judge){
				case 0: k--; break;
				case 1: j--; break;
				case 2: k++; break;
				case 3: j++; break;
		    }
		    ++judge;
		    judge %= 4;
		    switch (judge){
			    case 0: k++; break;
			    case 1: j++; break;
		    	case 2: k--; break;
			    case 3: j--; break;
		    }
		}
	}
	for (j = 0; j < n; ++j){
		for (k = 0; k < n; ++k){
			cout << setw(3) << setfill(' ') << num[j][k];
		}
		cout << endl;
	}
	
	return 0;
}*/