#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;
/*
    问题分析：每个评估团从起始位置开始，以固定步长访问位置，直到结束位置。我们需要找到被访问奇数次的位置。
    关键观察：如果一个位置被访问奇数次，而其之前的所有位置被访问偶数次，那么这个位置就是我们要找的。
    二分查找：使用二分查找来定位这个位置。对于每个中间位置，计算所有评估团在该位置及之前的访问次数的奇偶性。
    奇偶性计算：对于每个评估团，计算其在中间位置及之前的访问次数，并累加到总次数中。通过异或操作快速判断总次数的奇偶性。
*/
struct Group {
    LL S, E, D;
    Group(LL s, LL e, LL d) : S(s), E(e), D(d) {}
};

// 计算在mid之前的位置，该小组的贡献的奇偶性
int compute_parity(const Group& g, LL mid) {
    if (g.S > mid) return 0;
    LL max_val = min(g.E, mid);
    if (g.D == 0) return (g.S <= mid) ? 1 : 0;
    LL k = (max_val - g.S) / g.D + 1;
    return k % 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Group> groups;
        LL max_E = 0;
        for (int i = 0; i < N; ++i) {
            LL S, E, D;
            cin >> S >> E >> D;
            groups.emplace_back(S, E, D);
            max_E = max(max_E, E);
        }

        // 二分查找
        LL left = 0, right = max_E;
        LL pos = -1;
        while (left <= right) {
            LL mid = (left + right) / 2;
            int parity = 0;
            for (const auto& g : groups) {
                parity ^= compute_parity(g, mid);
            }
            if (parity) {
                pos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        if (pos == -1) {
            cout << "Poor QIN Teng:(\n";
            continue;
        }

        // 统计出现次数
        int count = 0;
        for (const auto& g : groups) {
            if (g.D == 0) {
                if (g.S == pos && g.S <= g.E) count++;
            }
            else {
                if (pos >= g.S && pos <= g.E && (pos - g.S) % g.D == 0) count++;
            }
        }

        if (count % 2) {
            cout << pos << ' ' << count << '\n';
        }
        else {
            cout << "Poor QIN Teng:(\n";
        }
    }
    return 0;
}