#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> g(n), s(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> s[i] >> b[i];
    }

    vector<int> sorted_g(g.begin(), g.end());
    vector<int> sorted_s(s.begin(), s.end());
    vector<int> sorted_b(b.begin(), b.end());
    sort(sorted_g.begin(), sorted_g.end());
    sort(sorted_s.begin(), sorted_s.end());
    sort(sorted_b.begin(), sorted_b.end());

    for (int i = 0; i < n; ++i) {
        auto cnt_g = sorted_g.end() - upper_bound(sorted_g.begin(), sorted_g.end(), g[i]);
        int rank_g = cnt_g + 1;

        auto cnt_s = sorted_s.end() - upper_bound(sorted_s.begin(), sorted_s.end(), s[i]);
        int rank_s = cnt_s + 1;

        auto cnt_b = sorted_b.end() - upper_bound(sorted_b.begin(), sorted_b.end(), b[i]);
        int rank_b = cnt_b + 1;

        int best = min({ rank_g, rank_s, rank_b });
        cout << best << '\n';
    }

    return 0;
}