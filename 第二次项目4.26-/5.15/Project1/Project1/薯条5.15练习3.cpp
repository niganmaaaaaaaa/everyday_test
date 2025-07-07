#include <iostream>
#include <vector>
using namespace std;
/*
    每个同学进入时，统计已存在且学号小于当前学号的同学数量。总和即为答案。
        等价于动态维护一个集合，支持插入和查询比某数小的元素个数。
    树状数组（Fenwick Tree）
        插入操作：将学号对应的位置加1。
        查询操作：求前缀和，获取小于当前学号的元素总数。
    具体步骤
        初始化树状数组。
        遍历每个同学的学号，查询前缀和后插入数组，累加结果。
*/
class BIT {
private:
    vector<int> tree;
public:
    BIT(int size) : tree(size + 2, 0) {}

    void update(int idx, int delta) {
        idx++; // 转换为1-based索引
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++; // 转换为1-based索引
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> order(N);
    for (int i = 0; i < N; ++i) {
        cin >> order[i];
    }

    BIT bit(N);
    long long ans = 0;
    for (int a : order) {
        ans += bit.query(a - 1);
        bit.update(a, 1);
    }
    cout << ans << endl;

    return 0;
}