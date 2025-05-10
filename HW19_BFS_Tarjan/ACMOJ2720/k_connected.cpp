#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MIN >> 2;

int n, k;
vector<vector<pair<int,int>>> adj;
vector<array<ll,2>> dp;

void dfs(int u, int p){
    ll base = 0;
    vector<ll> gain;
    for (auto [v,w] : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        base += dp[v][0];
        // 如果取 u-v 这条边，多出来的是
        gain.push_back(dp[v][1] + w - dp[v][0]);
    }
    sort(gain.begin(), gain.end(), greater<ll>());
    // 计算 dp[u][0]
    dp[u][0] = base;
    for (int i = 0; i < gain.size() && i < k && gain[i] > 0; ++i)
        dp[u][0] += gain[i];
    // 计算 dp[u][1]
    if (k > 0){
        dp[u][1] = base;
        for (int i = 0; i < gain.size() && i < k-1 && gain[i] > 0; ++i)
            dp[u][1] += gain[i];
    } else {
        dp[u][1] = INF;
    }
}

int main(){
    scanf("%d%d", &n, &k);
    adj.assign(n, {});
    for (int i = 0, u, v, w; i < n-1; ++i){
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dp.assign(n, {0,0});
    dfs(0, -1);
    printf("%lld\n", dp[0][0]);
    return 0;
}
// dp[u][0]:= 不保留u的父边时，u的子树的最大权重和
// dp[u][1]:= 保留u的父边时，u的子树的最大权重和