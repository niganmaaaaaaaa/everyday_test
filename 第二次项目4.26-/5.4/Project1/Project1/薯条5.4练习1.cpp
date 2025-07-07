#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/*

    osaraju�㷨�����㷨�����ҵ�����ǿ��ͨ������SCC�������岽�����£�
    ��һ��DFS������ԭͼ����¼�ڵ�����˳��
    ����ת��ͼ����ԭͼ�е����б߷�ת��
    �ڶ���DFS�������˳����������ת��ͼ���õ�����SCC��
    ���봦����ȡ�ڵ����ͱ����������ڽӱ�����˫���·��t=2����ͬʱ�����������ıߡ�
    SCC������������SCC���ҵ�������ֵ�����С��SCC��ͨ������ÿ��SCC�Ľڵ㲢�����ֵ���Ƚ�ʵ�֡�
    ������SCC�Ĵ�С��������Ľڵ㣬���������С�
    а��,vs��Щ�������ⲻ��
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