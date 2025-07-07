#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
    枚举等待牌：对每个可能的牌，检查是否添加后形成有效和牌。
    和牌检查：使用贪心算法扣除刻子和顺子，检查剩余牌是否全为零。
*/
bool check(const vector<int>& tmp_orig, int n) {
    vector<int> tmp = tmp_orig;
    for (int i = 1; i <= n; ++i) {
        tmp[i] %= 3;
        if (i + 2 <= n) {
            int k = min({ tmp[i], tmp[i + 1], tmp[i + 2] });
            tmp[i] -= k;
            tmp[i + 1] -= k;
            tmp[i + 2] -= k;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (tmp[i] != 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    int total = 3 * m + 1;
    vector<int> cnt(n + 3, 0);
    for (int i = 0; i < total; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> res;
    for (int c = 1; c <= n; ++c) {
        cnt[c]++;
        bool valid = false;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] >= 2) {
                vector<int> tmp = cnt;
                tmp[i] -= 2;
                if (check(tmp, n)) {
                    valid = true;
                    break;
                }
            }
        }
        if (valid) res.push_back(c);
        cnt[c]--;
    }

    if (res.empty()) {
        cout << "NO" << endl;
    }
    else {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) {
            if (i > 0) cout << " ";
            cout << res[i];
        }
        cout << endl;
    }

    return 0;
}