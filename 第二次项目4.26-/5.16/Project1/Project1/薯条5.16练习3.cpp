#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
    ̰�����򣺽���������Ʒ�۸��������Ż�ȯ����߼���Ʒ��
    ö���Ż�ȯ����������ÿ�������µ��ܳɱ���ȡ��Сֵ
*/
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, w;
    cin >> n >> m >> w;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // ��������
    sort(a.rbegin(), a.rend());

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    ll total_sum = prefix_sum[n];
    int k_max = (n + m - 1) / m;
    ll min_cost = LLONG_MAX;

    for (int k = 0; k <= k_max; ++k) {
        int s = min(k * m, n);
        ll cost = (ll)k * w + (total_sum - prefix_sum[s]);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }

    cout << min_cost << endl;

    return 0;
}