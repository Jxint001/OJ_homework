#include <cstdio>
#include <iostream>
using std::cin,std::cout,std::endl;
const int N = 10002;
int a[N];
int main() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; ++i)  cin >> a[i];
    while (Q) {
        int command;
        cin >> command;
        if (command == 1) {
            int x,v;
            cin >> x >> v;
            a[x] = v;
        }else {
            int x;
            cin >> x;
            int pos = 1, st = a[x];
            for (int i = 1; i <= n; ++i) {
                if (a[i] < st)  ++pos;
                if (a[i] == st && i < x)  ++pos;
            }
            cout << pos << endl;
        }
        --Q;
    }
    return 0;
}
