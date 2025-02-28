#include <set>
#include <iostream>
#include <utility>
using std::cin, std::cout, std::endl, std::string;
constexpr long long int mod = 1e9+7, x = 131;
constexpr long long int mod2 = 1e7+9, y = 283;

long long int n, m;
void CntSubstr(string s, long long int l)
{
	long long int hash = 0, hash1 = 0;
	for (long long int i = 0; i < l; i++) {
		hash = (hash * x + (s[i] - 97)) % mod;
		hash1 = (hash1 * y + (s[i] - 97)) % mod2;
	}
	long long int pow_l = 1, pow_ll = 1;
	for (long long int i = 0; i < l - 1; i++) {
        pow_l = (pow_l * x) % mod;
        pow_ll = (pow_ll * y) % mod2;
    }
	std::set<std::pair<long long int, long long int>> result;
	result.insert(std::make_pair(hash, hash1));
	for (long long int i = l; i < s.size(); i++) {
		hash = ((hash - pow_l * (s[i - l] - 97) + m * mod) * x + (s[i] - 97)) % mod;
        hash1 = ((hash1 - pow_ll * (s[i - l] - 97) + m * mod2) * y + (s[i] - 97)) % mod2; 
		result.insert(std::make_pair(hash, hash1));
	}
	cout << result.size() << endl;
}
int main()
{
    string s;
	cin >> n >> m >> s;

	CntSubstr(s, m);

	return 0;
}
