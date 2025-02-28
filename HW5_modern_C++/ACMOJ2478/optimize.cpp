#include <iostream>
#include <vector>
#include <string.h>
typedef unsigned long long ull;
using std::vector;
constexpr ull N = 1e7 + 9;

ull seed, steps[N], nxt[N], ans[N], n;
int head[N], edge[N], next_edge[N], total = 0;
int visit[N];
vector<int> cycles[N];

inline unsigned long long nextInteger(unsigned long long x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

int t = 1;
void BookCycle(int start) {
	int index = 0;
	int l = 0;
	for (int node = start; !l || (l && node != start); node = nxt[node]) {
		cycles[t - 1].push_back(node);
		++l;
	}
	++t;
}

bool dfs(int node) {
	visit[node] = 2;
    for (int i = head[node]; i != -1; i = next_edge[i]) {
        int neighbour = edge[i];
        if (visit[neighbour] == 2) {
			BookCycle(neighbour);
			return true;
		}
		if (visit[neighbour] == 1) {
			if (dfs(neighbour)) {
				return true;
			}
		}
    }
	visit[node] = 3;
	return false;
}

void FindCycle() {
	for (int i = 1; i <= n; ++i) {
		visit[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == 1) {
			dfs(i);
		}
	}
}

int path[N];
int path_index = 0;
void dfs_path(int node, int i, int round, vector<int>& cycle) {
    if (head[node] == -1)  return;
    for (int j = head[node]; j != -1; j = next_edge[j]) {
        int next = edge[j];
        if (ans[next] == 0) {
            path[path_index++] = next;

			if (steps[next] >= round) {
				ans[next] = cycle[ (i + ((steps[next] - round) % cycle.size())) % cycle.size() ];
			} else {
				ans[next] = path[round - steps[next] - 1];
			}
			dfs_path(next, i, round + 1, cycle);
            --path_index;
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
            if (head[node] == -1) {
                 continue; 
            } else {
				path_index = 0;
				dfs_path(node, i, 1, cycle);
			}
		}
	}
}

int main() {
	std::cin >> n >> seed;
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= n; ++i) {
		seed = nextInteger(seed);
		nxt[i] = (seed % n) + 1;
        edge[total] = i;
        next_edge[total] = head[nxt[i]];
        head[nxt[i]] = total++;
	}
	for (int i = 1; i <= n; ++i) {
		seed = nextInteger(seed);
		steps[i] = (seed % n) + 1;
		visit[i] = 0;
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