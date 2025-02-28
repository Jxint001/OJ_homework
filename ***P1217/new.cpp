#include <iostream>
#include <cmath>
using namespace std;

bool prime(int i);

int main()
{
	int i, a, b, d1, d2, d3, d4;
	cin >> a >> b;
	for (int i : {5, 7, 11}){
		if (i >= a && i <= b) cout << i << endl;
	}
	for (d1 = 1; d1 <= 9; d1 += 2){
		for (d2 = 0; d2 <= 9; ++d2){
			i = d1*100 + d2*10 + d1;
			if (i >= a && i <= b && prime(i)) cout << i << endl;
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2){
		for (d2 = 0; d2 <= 9; ++d2){
			for (d3 = 0; d3 <= 9; ++d3){
				i = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
				if (i >= a && i <= b && prime(i)) cout << i << endl;
			}
		}
	}
	for (d1 = 1; d1 <= 9; d1 += 2){
		for (d2 = 0; d2 <= 9; ++d2){
			for (d3 = 0; d3 <= 9; ++d3){
				for (d4 = 0; d4 <= 9; ++d4){
					i = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100 + d2*10 + d1;
					if (i >= a && i <= b && prime(i)) cout << i << endl;
				}
			}
		}
	}
	
	return 0;
}

bool prime(int i)
{
	bool flag2 = 1;
	int m;
	for (m = 2; m <= sqrt(i); ++m){
		if (i % m == 0){
			flag2 = 0;
			break;
		}
	}
	return flag2;
}