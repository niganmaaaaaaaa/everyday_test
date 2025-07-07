#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
    ����˼·
    ̰�ķ���
    �������򣺽�������������󰴽������С�������������������ͬ����ʼ��Ӵ�С����
        ����������Ծ��������ұ��������Ա������������ظ�������Щ����
    ��״���飺���ڿ��ٲ�ѯ�����ڵ�������������ȷ���Ƿ���Ҫ��������
    ���鼯�����ڸ�Ч���Һͱ�ǿ���������λ�ã������ظ�����Ѿ�������λ�á�    
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

    // ���������������У���������ͬʱ����ʼ�㽵������
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.e != b.e) return a.e < b.e;
        return a.b > b.b;
        });

    BIT bit(n);
    vector<int> parent(n + 2);
    iota(parent.begin(), parent.end(), 0); // ��ʼ�����鼯

    int total = 0;
    for (const auto& interval : intervals) {
        int b = interval.b;
        int e = interval.e;
        int required = interval.t;

        // ���㵱ǰ�������е�������
        int current = bit.query(e) - bit.query(b - 1);
        int need = required - current;

        if (need <= 0) continue;

        int remaining = need;
        int pos = e; // ���Ҷ˵㿪ʼ�ҿ���λ��

        while (remaining > 0) {
            int candidate = find(pos, parent);
            if (candidate < b) break; // ������߽�����ֹ

            // �ڸ�λ������
            bit.update(candidate, 1);
            total++;
            parent[candidate] = find(candidate - 1, parent); // ����ǰһ��λ��
            remaining--;
            pos = candidate - 1; // ����������
        }
    }

    cout << total << endl;

    return 0;
}