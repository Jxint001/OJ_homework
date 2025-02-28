#include <iostream>
#include <unordered_map>
typedef long long int ll;
std::unordered_map<ll, ll> book;
int main() {
    int a, b, c, d;
    ll ans = 0;
    std::cin >> a >> b >> c >> d;
    for (ll i = 1; i <= 1000; ++i) {
        for (ll j = 1; j <= 1000; ++j) {
            ll tmp = a * i * i + b * j * j;
            if (book.find(tmp) == book.end()) {
                book.insert(std::make_pair(tmp, 1));
            } else {
                book.find(tmp)->second += 1;
            }
        }
    }
    for (ll i = 1; i <= 1000; ++i) {
        for (ll j = 1; j <= 1000; ++j) {
            ll tmp = -1 * c * i * i - d * j * j;
            if (book.find(tmp) != book.end()) {
                ans += book.find(tmp)->second;
            }
        }
    }
    std::cout << ans * 16 << std::endl;
    return 0;
}
