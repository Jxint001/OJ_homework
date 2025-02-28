#include <iostream>
#include <map>
#include <vector>
#include <set>
typedef unsigned int ul;
using std::cin, std::multimap, std::cout, std::endl, std::vector, std::set;
multimap<ul, ul> match;
int main() {
    int n, flag;
    cin >> n >> flag;
    if (flag == 0) {
        ul a[300001], max = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (match.find(a[i]) != match.end())  match.find(a[i])->second += 1;
            else match.insert(std::make_pair(a[i], 1));
            if (max < match.find(a[i])->second)  max = match.find(a[i])->second;
        }
        for (auto &j : match) {
            if (j.second == max)  cout << j.first << " ";
        }
        cout << endl;
        return 0;
    }
    if (flag == 1) {
        int count = 0;
        ul cur, tp;
        for (int i = 0; i < n; ++i) {
            cin >> cur;
            if (count == 0) {
                tp = cur;
                ++count;
            } else if (cur == tp)  ++count;
            else if (cur != tp)  --count;
        }
        cout << tp << endl;
        return 0;
    }
    if (flag == 2) {
        ul a[n+5];
        for (int i = 0; i < n; ++i)  cin >> a[i];
        ul book[32];
        for (ul i = 0; i <= 31; ++i) {
            book[i] = 0;
            for (int k = 0; k < n; ++k)  if (a[k] & (1ul << i))  ++book[i];
        }
        vector<ul> ambw;
        set<ul> result;
        ul num = 0;
        for (ul i = 0; i <= 31; ++i) {
            if (book[i] > n/2)  num |= 1ul << i;
            if (!(n&1ul) && book[i] == n/2)  ambw.push_back(i);
        }
        for (ul i = 0; i < (1ul << ambw.size()); ++i) {
            ul st = num, index = 0;
            for (auto &k : ambw) {
                if (i & (1ul << index)) st |= 1ul << k;
                ++index;
            }
            result.insert(st);
        }
        for (auto &i : result)  cout << i << " ";
        cout << endl;
        return 0;
    }
    return 0;
}