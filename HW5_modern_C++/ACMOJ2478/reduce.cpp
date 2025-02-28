#include <iostream>
#include <string.h>
typedef unsigned long long ull;
constexpr ull N = 1e7 + 9;

ull seed, steps[N], nxt[N], ans[N], n;
int head[N], edge[N], next_edge[N], total = 0;
int visit[N];
int cycle[N];

inline unsigned long long nextInteger(unsigned long long x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}
int length = 0;

int path[N];
int path_index = 0;
void dfs_path(int node, int i, int round) {
    if (head[node] == -1)  return;
    for (int j = head[node]; j != -1; j = next_edge[j]) {
        int next = edge[j];
        visit[next] = 3;
        if (ans[next] == 0) {
            path[path_index++] = next;
			if (steps[next] >= round) {
				ans[next] = cycle[ (i + steps[next] - round) % length ];
			} else {
				ans[next] = path[round - steps[next] - 1];
			}
			dfs_path(next, i, round + 1);
            --path_index;
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
	}

	for (int i = 1; i <= n; ++i) {
		visit[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == 1) {
			int neighbour = 0, node = i, count = 0;
            bool ret, con;
            while (true) {
                ret = false;   con = false;
                if (visit[node] == 1)  visit[node] = 2;
                for (int j = node; count < N; j = neighbour) {
                    neighbour = nxt[j];
                    if (visit[neighbour] == 2) {
                        length = 0;
                        for (int k = neighbour; !length || (length && k != neighbour); k = nxt[k]) {
                            cycle[length] = k;
                            ++length;
                            visit[k] = 3;
                        }
                        for (int k = 0; k < length; ++k) {
                            int present = cycle[k];
                            ans[present] = cycle[ (k + steps[present]) % length ];
                            if (head[present] == -1) {
                                continue;
                            } else {
                                path_index = 0;
                                dfs_path(present, k, 1);
                            }
                        }
                        visit[node] = 3;
                        ret = true;
                        break;
                    }
                    if (visit[neighbour] == 1) {
                        //change
                        node = neighbour;
                        con = true;
                        break;
                    }
                    if (visit[neighbour] == 3) {
                        visit[node] = 3;
                        ret = true;
                        break;
                    }
                    ++count;
                }
                if (con == true)  continue;
                visit[node] = 3;                                                                                                                            
                if (ret == true)  break;
            }
		}
	}
	ull output = 0;
	for (int i = 1; i <= n; ++i) {
		output ^= ans[i];
	}
	std::cout << output << std::endl;
	return 0;
}