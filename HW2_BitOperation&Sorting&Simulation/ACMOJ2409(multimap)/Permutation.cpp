#include <iostream>
#include <map>
#include <utility>
using std::cin,std::cout,std::endl,std::make_pair,std::multimap;
multimap<int,int> Numb;
int main() {
    int n,num,i,x = 0,a[100001];    //换a不换b
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> num;
        x ^= num;
        a[i] = num;
    }
    for (i = 0; i < n; ++i) {
        cin >> num;
        x ^= num;
        Numb.insert(make_pair(num,i));
    }
    for (i = 0; i < n; ++i){
        int b = a[i] ^ x;
        if (Numb.count(b)) {
            a[i] = Numb.find(b)->second;
            Numb.erase(Numb.find(b));
        }else {
            cout << -1 << endl;
            return 0;
        }
    }
    for (i = 0; i < n; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}