#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
/*
    输入处理：读取城市数、道路数、僵尸城市数及危险距离，接着读取住宿费用和被僵尸占领的城市。
    BFS从所有僵尸城市出发，计算每个城市到最近僵尸城市的距离，确定危险城市。
    根据距离确定每个城市的住宿费用，排除僵尸城市。
    构建不含僵尸城市及其相关边的邻接表。
    使用优先队列优化的Dijkstra算法，计算从城市1到城市N的最小费用路径，考虑每个节点的住宿费用。
*/
const int MAXN = 100005;

vector<int> adj[MAXN];
bool is_zombie[MAXN];
int dist[MAXN];
long long cost[MAXN];
long long min_cost[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K, S;
    cin >> N >> M >> K >> S;
    int P, Q;
    cin >> P >> Q;

    // 读取僵尸城市并标记
    memset(is_zombie, false, sizeof(is_zombie));
    queue<int> zombie_q;
    for (int i = 0; i < K; ++i) {
        int c;
        cin >> c;
        is_zombie[c] = true;
        zombie_q.push(c);
    }

    // 读取边并构建邻接表
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 多源BFS计算每个节点到最近僵尸城市的距离
    memset(dist, -1, sizeof(dist));
    queue<int> bfs_q;
    while (!zombie_q.empty()) {
        int u = zombie_q.front();
        zombie_q.pop();
        dist[u] = 0;
        bfs_q.push(u);
    }

    while (!bfs_q.empty()) {
        int u = bfs_q.front();
        bfs_q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                bfs_q.push(v);
            }
        }
    }

    // 计算每个节点的住宿费用
    for (int u = 1; u <= N; ++u) {
        if (u == 1 || u == N) {
            cost[u] = 0;
        }
        else if (is_zombie[u]) {
            cost[u] = LLONG_MAX; // 标记为不可达
        }
        else {
            if (dist[u] != -1 && dist[u] <= S) {
                cost[u] = Q;
            }
            else {
                cost[u] = P;
            }
        }
    }

    // 构建过滤后的邻接表，排除僵尸城市
    vector<int> filtered_adj[MAXN];
    for (int u = 1; u <= N; ++u) {
        if (is_zombie[u]) continue;
        for (int v : adj[u]) {
            if (!is_zombie[v]) {
                filtered_adj[u].push_back(v);
            }
        }
    }

    // Dijkstra算法求最小费用
    fill(min_cost, min_cost + N + 1, LLONG_MAX);
    min_cost[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();

        if (u == N) {
            cout << current_cost << endl;
            return 0;
        }

        if (current_cost > min_cost[u]) continue;

        for (int v : filtered_adj[u]) {
            long long next_cost = current_cost + (v == N ? 0 : cost[v]);
            if (next_cost < min_cost[v]) {
                min_cost[v] = next_cost;
                pq.emplace(next_cost, v);
            }
        }
    }

    // 输入保证有解，无需处理无解情况
    return 0;
}