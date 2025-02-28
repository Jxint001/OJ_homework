#include <cstdio>
#include <iostream>
using std::cin,std::cout,std::endl;
int a[10002];
int main() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    std::getchar();
    while (Q) {
        char command[10];
        char com;
        int len = 0;
        com = std::getchar();
        while (com != '\n') {
            command[len] = com;
            ++len;
            com = std::getchar();
        }
        if (command[0] == '1') {
            int ch = 2, x = 0,v = 0;
            while (ch < len && command[ch] != ' ') {
                x = x * 10 + command[ch] - '0';
                ++ch;
            }
            ++ch;
            while (ch < len && command[ch] != ' ') {
                v = v * 10 + command[ch] -'0';
                ++ch;
            }
            a[x] = v;
        }
        if (command[0] == '2') {
            int ch = 2, x = 0;
             while (ch < len && command[ch] != ' ') {
                x = x * 10 + command[ch] - '0';
                ++ch;
            }
            int pos = 1,st = a[x];
            for (int i = 1; i <= n; ++i) {
                if (a[i] < st) ++pos;
                if ( a[i] == st && i < x)  ++pos;
            }
            cout << pos << endl;
        }
        --Q;
    }
    return 0;
}