#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
    方法思路
    贪心方法
    区间排序：将居民的区间请求按结束点从小到大排序，如果结束点相同则按起始点从大到小排序。
        这样处理可以尽可能在右边种树，以便后续区间可以重复利用这些树。
    树状数组：用于快速查询区间内的树的数量，以确定是否需要补种树。
    并查集：用于高效查找和标记可以种树的位置，避免重复检查已经种树的位置。    
*/

struct Interval {
    int b, e, t;
    Interval(int b_, int e_, int t_) : b(b_), e(e_), t(t_) {}
};

struct BIT {
    vector<int> tree;
    int n;

    BIT(int size) : n(size), tree(size + 2, 0) {}

    void update(int idx, int delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    vector<Interval> intervals;
    for (int i = 0; i < h; ++i) {
        int b, e, t;
        cin >> b >> e >> t;
        intervals.emplace_back(b, e, t);
    }

    // 按结束点升序排列，结束点相同时按起始点降序排列
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.e != b.e) return a.e < b.e;
        return a.b > b.b;
        });

    BIT bit(n);
    vector<int> parent(n + 2);
    iota(parent.begin(), parent.end(), 0); // 初始化并查集

    int total = 0;
    for (const auto& interval : intervals) {
        int b = interval.b;
        int e = interval.e;
        int required = interval.t;

        // 计算当前区间已有的树数量
        int current = bit.query(e) - bit.query(b - 1);
        int need = required - current;

        if (need <= 0) continue;

        int remaining = need;
        int pos = e; // 从右端点开始找可用位置

        while (remaining > 0) {
            int candidate = find(pos, parent);
            if (candidate < b) break; // 超出左边界则终止

            // 在该位置种树
            bit.update(candidate, 1);
            total++;
            parent[candidate] = find(candidate - 1, parent); // 连接前一个位置
            remaining--;
            pos = candidate - 1; // 继续向左找
        }
    }

    cout << total << endl;

    return 0;
}