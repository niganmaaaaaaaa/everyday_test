#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
    贪心排序：降序排列商品价格，优先用优惠券购买高价商品。
    枚举优惠券数量：计算每个数量下的总成本，取最小值
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

    // 降序排序
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