#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    定义 Edge 结构体，包含道路两端点 u、v 和道路分值 c，并重载 < 运算符，方便按分值对道路进行排序。
    使用 vector<Edge> 类型的 edges 存储所有道路信息，int 类型的数组 parent 用于并查集操作，初始时每个交叉路口的父节点设为自身。

    交叉路口数量 n 和道路数量 m。
    读取每条道路的两个端点 u、v 和分值 c，将道路信息存入 edges。
    对 edges 进行排序，使得道路按分值从小到大排列。
    使用并查集
        find 用于查找某节点的根节点，采用路径压缩方式，提高后续查找效率。
        unite 用于合并两个节点所在的集合。若两个节点的根节点不同，则将一个根节点设为另一个根节点的父节点；若根节点相同，则说明两节点已在同一集合中，无需合并。

        遍历排序后的 edges。
        对每条道路，尝试用 unite 函数合并其两端点所在集合。若合并成功（即两端点不在同一集合），道路数量 cnt 加 1，并更新已选道路中的最大分值 max_c。
        当已选道路数量达到 n - 1 时（n 个节点构成连通图最少需要 n - 1 条边），停止遍历。

    输出所需道路数量（ n - 1，保证所有交叉路口连通且道路数最少）和已选道路中的最大分值 max_c，满足道路分值最大的道路分值尽量小的要求。
*/
struct Edge {
    int u, v, c;
    bool operator<(const Edge& other) const {
        return c < other.c;
    }
};

vector<Edge> edges;
int parent[305];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[x] = y;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({ u, v, c });
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int max_c = 0, cnt = 0;
    for (Edge& e : edges) {
        if (unite(e.u, e.v)) {
            cnt++;
            max_c = max(max_c, e.c);
            if (cnt == n - 1) break;
        }
    }

    cout << n - 1 << " " << max_c << endl;
    return 0;
}