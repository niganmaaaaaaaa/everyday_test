#include <iostream>
#include <vector>
using namespace std;
/*
    ÿ��ͬѧ����ʱ��ͳ���Ѵ�����ѧ��С�ڵ�ǰѧ�ŵ�ͬѧ�������ܺͼ�Ϊ�𰸡�
        �ȼ��ڶ�̬ά��һ�����ϣ�֧�ֲ���Ͳ�ѯ��ĳ��С��Ԫ�ظ�����
    ��״���飨Fenwick Tree��
        �����������ѧ�Ŷ�Ӧ��λ�ü�1��
        ��ѯ��������ǰ׺�ͣ���ȡС�ڵ�ǰѧ�ŵ�Ԫ��������
    ���岽��
        ��ʼ����״���顣
        ����ÿ��ͬѧ��ѧ�ţ���ѯǰ׺�ͺ�������飬�ۼӽ����
*/
class BIT {
private:
    vector<int> tree;
public:
    BIT(int size) : tree(size + 2, 0) {}

    void update(int idx, int delta) {
        idx++; // ת��Ϊ1-based����
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++; // ת��Ϊ1-based����
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