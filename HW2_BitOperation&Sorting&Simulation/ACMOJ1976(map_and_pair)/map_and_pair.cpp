#include <map>
#include <iostream>
#include <utility>
typedef long long int LL;
using std::cin,std::cout,std::endl,std::map,std::pair;
map<pair<LL,LL>,int> students;
pair<LL,LL> infmt[50001];
int main() {
    int n,k,i;
    cin >> n;
    LL h,w;
    for (i = 0; i < n; ++i) {
        cin >> infmt[i].first >> infmt[i].second;
        students[infmt[i]] +=  1;
    }
    cin >> k;
    int count = 0;
    for (i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            LL height = infmt[i].first ^ j;
            LL weight = infmt[i].second ^ (k-j);
            pair<LL,LL> find = std::make_pair(height, weight);
            count += students[find];
        }
    }
    if(k == 0) count -= n;
    cout << count/2 << endl;
    return 0;
}