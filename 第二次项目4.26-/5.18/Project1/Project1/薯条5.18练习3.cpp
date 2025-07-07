/*
构建树结构：使用邻接表存储树的结构，并通过BFS确定每个节点的父节点和深度。
预处理倍增表：用于快速查询两个节点的最近公共祖先（LCA）。
预处理深度幂次方：预先计算每个节点深度的k次方值，以便快速查询。
预处理前缀和数组：存储每个节点到根节点的路径上所有节点深度的k次方和。
处理查询：利用预处理的信息快速计算路径上的深度k次方和。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

const int MOD = 998244353;
const int MAXN = 300005;
const int LOG = 20;

vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN];
int up[MAXN][LOG];
int pow_dk[MAXN][51];
int sum[MAXN][51];

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; j--) {
        if (diff & (1 << j)) {
            u = up[u][j];
        }
    }
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS to compute parent and depth
    queue<int> q;
    q.push(1);
    memset(parent, 0, sizeof(parent));
    parent[1] = 0;
    depth[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (v != parent[u] && parent[v] == 0) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    // Preprocess up table for LCA
    for (int i = 1; i <= n; i++) {
        up[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != 0) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
            else {
                up[i][j] = 0;
            }
        }
    }

    // Precompute pow_dk
    for (int u = 1; u <= n; u++) {
        long long d = depth[u];
        pow_dk[u][1] = d % MOD;
        for (int k = 2; k <= 50; k++) {
            pow_dk[u][k] = (1LL * pow_dk[u][k - 1] * d) % MOD;
        }
    }

    // Precompute sum
    for (int k = 1; k <= 50; k++) {
        sum[1][k] = pow_dk[1][k]; // which is 0
        queue<int> q_sum;
        q_sum.push(1);
        while (!q_sum.empty()) {
            int u = q_sum.front(); q_sum.pop();
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                sum[v][k] = (sum[u][k] + pow_dk[v][k]) % MOD;
                q_sum.push(v);
            }
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int u, v, k;
        cin >> u >> v >> k;
        int l = lca(u, v);
        long long sum_u = sum[u][k];
        long long sum_v = sum[v][k];
        long long sum_l = sum[l][k];
        long long depth_l_pow = pow_dk[l][k];

        long long ans = (sum_u + sum_v) % MOD;
        ans = (ans - (2 * sum_l) % MOD + MOD) % MOD;
        ans = (ans + depth_l_pow) % MOD;
        cout << ans << '\n';
    }

    return 0;
}