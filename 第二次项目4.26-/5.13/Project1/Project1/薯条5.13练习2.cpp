#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
/*
    ���봦����ȡ����������·������ʬ��������Σ�վ��룬���Ŷ�ȡס�޷��úͱ���ʬռ��ĳ��С�
    BFS�����н�ʬ���г���������ÿ�����е������ʬ���еľ��룬ȷ��Σ�ճ��С�
    ���ݾ���ȷ��ÿ�����е�ס�޷��ã��ų���ʬ���С�
    ����������ʬ���м�����رߵ��ڽӱ�
    ʹ�����ȶ����Ż���Dijkstra�㷨������ӳ���1������N����С����·��������ÿ���ڵ��ס�޷��á�
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

    // ��ȡ��ʬ���в����
    memset(is_zombie, false, sizeof(is_zombie));
    queue<int> zombie_q;
    for (int i = 0; i < K; ++i) {
        int c;
        cin >> c;
        is_zombie[c] = true;
        zombie_q.push(c);
    }

    // ��ȡ�߲������ڽӱ�
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // ��ԴBFS����ÿ���ڵ㵽�����ʬ���еľ���
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

    // ����ÿ���ڵ��ס�޷���
    for (int u = 1; u <= N; ++u) {
        if (u == 1 || u == N) {
            cost[u] = 0;
        }
        else if (is_zombie[u]) {
            cost[u] = LLONG_MAX; // ���Ϊ���ɴ�
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

    // �������˺���ڽӱ��ų���ʬ����
    vector<int> filtered_adj[MAXN];
    for (int u = 1; u <= N; ++u) {
        if (is_zombie[u]) continue;
        for (int v : adj[u]) {
            if (!is_zombie[v]) {
                filtered_adj[u].push_back(v);
            }
        }
    }

    // Dijkstra�㷨����С����
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

    // ���뱣֤�н⣬���账���޽����
    return 0;
}