#include <iostream>
#include <vector>
#include <list>
#include <array>
typedef unsigned long long ull;
using std::array, std:: list, std::vector;
constexpr ull N = 1e7 + 9;
enum status {UN, ING, ED};

ull seed, steps[N], nxt[N], ans[N], n;
list<int> adj[N];
array<status, N> visit;
vector< vector<int>> cycles;

inline unsigned long long nextInteger(unsigned long long x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

int t = 1;
void BookCycle(int start) {
	vector<int> c;
	int index = 0;
	int l = 0;
	for (int node = start; !l || (l && node != start); node = nxt[node]) {
		c.push_back(node);
		++l;
	}
	cycles.push_back(c);
	++t;
}

bool dfs(int node) {
	visit[node] = ING;
	for (const auto& neighbour : adj[node]) {
		if (visit[neighbour] == ING) {
			BookCycle(neighbour);
			return true;
		}
		if (visit[neighbour] == UN) {
			if (dfs(neighbour)) {
				return true;
			}
		}
	}
	visit[node] = ED;
	return false;
}

void FindCycle() {
	for (int i = 1; i <= n; ++i) {
		visit[i] = UN;
	}
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == UN) {
			dfs(i);
		}
	}
}

vector<int> path;
void dfs_path(int node, int i, int round, vector<int>& cycle) {
	if (adj[node].empty())  return;
	for (const auto& next : adj[node]) {
		if (ans[next] == 0) {
			path.push_back(next);
			if (steps[next] >= round) {
				ans[next] = cycle[ (i + ((steps[next] - round) % cycle.size())) % cycle.size() ];
			} else {
				ans[next] = path[round - steps[next] - 1];
			}
			dfs_path(next, i, round + 1, cycle);
			path.pop_back();
		}
		
	}
}

void expand() {
	int index = 1;
	for (auto& cycle : cycles) {
		++index;
		if (index > t)  break;
		for (int i = 0; i < cycle.size(); ++i) {
			int node = cycle[i];
			ans[node] = cycle[ (i + (steps[node] % cycle.size())) % cycle.size() ];
			if (adj[node].empty())  continue;
			else {
				path.clear();
				dfs_path(node, i, 1, cycle);
			}
		}
	}
}

int main() {
	std::cin >> n >> seed;
	
	for (int i = 1; i <= n; ++i) {
		seed = nextInteger(seed);
		nxt[i] = (seed % n) + 1;
		adj[nxt[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		seed = nextInteger(seed);
		//steps[i] = seed;
		steps[i] = (seed % n) + 1;
	}
	FindCycle();
	expand();
	ull output = 0;
	for (int i = 1; i <= n; ++i) {
		output ^= ans[i];
	}
	std::cout << output << std::endl;
	return 0;
}