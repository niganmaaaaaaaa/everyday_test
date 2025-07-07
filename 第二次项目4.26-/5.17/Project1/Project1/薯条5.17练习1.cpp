#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 20;

int n;
vector<int> a(MAXN);
vector<int> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];

// 预处理LCA
void dfs(int u, int parent) {
    up[u][0] = parent;
    depth[u] = depth[parent] + 1;
    for (int i = 1; i < LOGN; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }
}

// 查询LCA
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); // 预处理LCA信息

    int ans = 0;
    // 枚举所有点对 (x, y)
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            int ancestor = lca(x, y);
            if (a[x] % a[ancestor] == 0 && a[y] % a[ancestor] == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}