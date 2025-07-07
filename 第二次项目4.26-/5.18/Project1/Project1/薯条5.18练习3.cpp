/*
�������ṹ��ʹ���ڽӱ�洢���Ľṹ����ͨ��BFSȷ��ÿ���ڵ�ĸ��ڵ����ȡ�
Ԥ�����������ڿ��ٲ�ѯ�����ڵ������������ȣ�LCA����
Ԥ��������ݴη���Ԥ�ȼ���ÿ���ڵ���ȵ�k�η�ֵ���Ա���ٲ�ѯ��
Ԥ����ǰ׺�����飺�洢ÿ���ڵ㵽���ڵ��·�������нڵ���ȵ�k�η��͡�
�����ѯ������Ԥ�������Ϣ���ټ���·���ϵ����k�η��͡�
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