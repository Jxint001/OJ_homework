#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

int n, m, p, q;
bool suc = false;
using std::cin, std::string, std::cout;
std::unordered_map<string, int> book;
std::unordered_map<int, string> findp;
std::unordered_map<int, string> findq;
std::vector<string> possibleans;

bool ok(string a, string b) {
    int l = a.length();
    bool check = 1;
    for (int i = 0; i < l - 1; ++i) {
        if (a[i] == b[i])  check = 0;
    }
    return check;
}

string reverse(string a) {
    string b;
    for (int i = 0; i < m; ++i) {
         if (a[i] == 'Y') {
            b += 'N';
        } else {
            b += 'Y';
        }
    }
    return b;
}

void smallest(string& last) {
    if (last[m - 1] == 'N') {
        last[m - 1] = 'Y';
    } else {
        int i;
        for (i = m - 2; i >= 0; --i) {
            if (last[i] == 'N' && last[i + 1] == 'Y')  break;
        }
        last[i] = 'Y';
        for (int j = i + 1; j < m; ++j)  last[j] = 'N';
    }
    string recur = reverse(last);
    if (book.find(last) == book.end() && book.find(recur) == book.end()) {
        suc = true;
        return;
    } 
    smallest(last);
    return;
}

int main() {
    cin >> n >> m >> p >> q;
    if (p + q > n) {cout << -1 << '\n';  return 0;}
    for (int i = 0; i < n; ++i) {
        string ans;
        cin >> ans;
        if (book.find(ans) != book.end())  ++book.find(ans)->second;
        else book.insert(std::make_pair(ans, 1));
    }
    int cnt1 = 0, cnt2 = 0;
    for (auto& i : book) {
        if (i.second == p) {
            findp.insert(std::make_pair(cnt1, i.first));
            ++cnt1;
        } 
        if (i.second == q) {
            findq.insert(std::make_pair(cnt2, i.first));
            ++cnt2;
        }
    }
    if (p == 0 && q > 0) {   
        if (findq.size() == 1) {
            string realans = reverse(findq[0]);
            if (book.find(realans) != book.end()) {
                cout << -1 << '\n';
            } else {
                cout << realans << '\n';
            }
            return 0;
        } else if (findq.size() == 0) {
            cout << -1 << '\n';
            return 0;
        } else {
            for (auto& i : findq) {
                string realans = reverse(i.second);
                if (book.find(realans) != book.end()) {
                    continue;
                } else {
                    possibleans.push_back(realans);
                }
            }
            if (possibleans.size() == 0) {
                cout << -1 << '\n';
                return 0;
            } else {
                std::sort(possibleans.begin(), possibleans.end());
                cout << possibleans[0] << '\n';
                return 0;
            }
        }
    } else if (q == 0 && p > 0) {
        if (findp.size() == 1) {
            string realans = reverse(findp[0]);
            if (book.find(realans) != book.end()) {
                cout << -1 << '\n';
            } else {
                cout << findp[0] << '\n';
            }
            return 0;
        } else if (findp.size() == 0) {
            cout << -1 << '\n';
            return 0;
        } else {
            for (auto& i : findp) {
                string realans = reverse(i.second);
                if (book.find(realans) != book.end()) {
                    continue;
                } else {
                    possibleans.push_back(i.second);
                }
            }
            if (possibleans.size() == 0) {
                cout << -1 << '\n';
                return 0;
            } else {
                std::sort(possibleans.begin(), possibleans.end());
                cout << possibleans[0] << '\n';
                return 0;
            }
        }
    } else if (p > 0 && q > 0) {
       if (findp.size() == 0 || findq.size() == 0) {
            cout << -1 << '\n';
            return 0;
        } else {
            for (auto& i : findp) {
                string realq = reverse(i.second);
                if (book.find(realq) != book.end()) {
                    if (book.find(realq)->second == q) {
                        possibleans.push_back(i.second);
                        // if (p == q) {
                        //     possibleans.push_back(realq);
                        // }
                    }
                }
            }
            if (possibleans.size() == 0) {
                cout << -1 << '\n';
                return 0;
            } else {
                std::sort(possibleans.begin(), possibleans.end());
                cout << possibleans[0] << '\n';
                return 0;
            }
        }
    } else {  //p == q == 0
        string ans1;
        for (int i = 0; i < m; ++i) {
            ans1 += 'N';
        }
        string ans2 = reverse(ans1);
        if (book.find(ans1) == book.end() && book.find(ans2) == book.end()) {
            cout << ans1 << '\n';
            return 0;
        }
        smallest(ans1);
        if (suc == true) { cout << ans1 << '\n';  return 0;}
        cout << -1 << '\n';
        return 0;
    }
    return 0;
}