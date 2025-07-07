#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/*

    osaraju算法：该算法用于找到所有强连通分量（SCC），具体步骤如下：
    第一次DFS：遍历原图，记录节点的完成顺序。
    构建转置图：将原图中的所有边反转。
    第二次DFS：按完成顺序的逆序遍历转置图，得到所有SCC。
    输入处理：读取节点数和边数，构建邻接表。对于双向道路（t=2），同时添加两个方向的边。
    SCC处理：遍历所有SCC，找到最大且字典序最小的SCC。通过排序每个SCC的节点并进行字典序比较实现。
    输出最大SCC的大小及其包含的节点，按升序排列。
    邪术,vs有些许报错但问题不大
*/
void dfs1(int u, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& order) {
    stack<pair<int, bool>> st;
    st.push({ u, false });
    visited[u] = true;
    while (!st.empty()) {
        auto [v, processed] = st.top();
        st.pop();
        if (processed) {
            order.push_back(v);
            continue;
        }
        st.push({ v, true });
        for (auto w : adj[v]) {
            if (!visited[w]) {
                visited[w] = true;
                st.push({ w, false });
            }
        }
    }
}

vector<vector<int>> kosaraju(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    vector<int> order;

    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            dfs1(u, visited, adj, order);
        }
    }

    vector<vector<int>> adjT(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (auto v : adj[u]) {
            adjT[v].push_back(u);
        }
    }

    vector<bool> visited2(n + 1, false);
    vector<vector<int>> components;

    reverse(order.begin(), order.end());
    for (auto u : order) {
        if (!visited2[u]) {
            vector<int> component;
            stack<pair<int, bool>> st;
            st.push({ u, false });
            visited2[u] = true;
            component.push_back(u);
            while (!st.empty()) {
                auto [v, processed] = st.top();
                st.pop();
                if (!processed) {
                    st.push({ v, true });
                    for (auto w : adjT[v]) {
                        if (!visited2[w]) {
                            visited2[w] = true;
                            component.push_back(w);
                            st.push({ w, false });
                        }
                    }
                }
            }
            components.push_back(component);
        }
    }

    return components;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back(b);
        if (t == 2) {
            adj[b].push_back(a);
        }
    }

    vector<vector<int>> components = kosaraju(n, adj);

    vector<int> best;
    int max_size = 0;

    for (auto& comp : components) {
        sort(comp.begin(), comp.end());
        if (comp.size() > max_size) {
            max_size = comp.size();
            best = comp;
        }
        else if (comp.size() == max_size) {
            if (comp < best) {
                best = comp;
            }
        }
    }

    cout << max_size << '\n';
    for (size_t i = 0; i < best.size(); ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << best[i];
    }
    cout << '\n';

    return 0;
}