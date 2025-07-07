#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    ���� Edge �ṹ�壬������·���˵� u��v �͵�·��ֵ c�������� < ����������㰴��ֵ�Ե�·��������
    ʹ�� vector<Edge> ���͵� edges �洢���е�·��Ϣ��int ���͵����� parent ���ڲ��鼯��������ʼʱÿ������·�ڵĸ��ڵ���Ϊ����

    ����·������ n �͵�·���� m��
    ��ȡÿ����·�������˵� u��v �ͷ�ֵ c������·��Ϣ���� edges��
    �� edges ��������ʹ�õ�·����ֵ��С�������С�
    ʹ�ò��鼯
        find ���ڲ���ĳ�ڵ�ĸ��ڵ㣬����·��ѹ����ʽ����ߺ�������Ч�ʡ�
        unite ���ںϲ������ڵ����ڵļ��ϡ��������ڵ�ĸ��ڵ㲻ͬ����һ�����ڵ���Ϊ��һ�����ڵ�ĸ��ڵ㣻�����ڵ���ͬ����˵�����ڵ�����ͬһ�����У�����ϲ���

        ���������� edges��
        ��ÿ����·�������� unite �����ϲ������˵����ڼ��ϡ����ϲ��ɹ��������˵㲻��ͬһ���ϣ�����·���� cnt �� 1����������ѡ��·�е�����ֵ max_c��
        ����ѡ��·�����ﵽ n - 1 ʱ��n ���ڵ㹹����ͨͼ������Ҫ n - 1 ���ߣ���ֹͣ������

    ��������·������ n - 1����֤���н���·����ͨ�ҵ�·�����٣�����ѡ��·�е�����ֵ max_c�������·��ֵ���ĵ�·��ֵ����С��Ҫ��
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