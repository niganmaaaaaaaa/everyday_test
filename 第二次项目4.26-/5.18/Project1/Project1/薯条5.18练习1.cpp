#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;
/*
    ���������ÿ�������Ŵ���ʼλ�ÿ�ʼ���Թ̶���������λ�ã�ֱ������λ�á�������Ҫ�ҵ������������ε�λ�á�
    �ؼ��۲죺���һ��λ�ñ����������Σ�����֮ǰ������λ�ñ�����ż���Σ���ô���λ�þ�������Ҫ�ҵġ�
    ���ֲ��ң�ʹ�ö��ֲ�������λ���λ�á�����ÿ���м�λ�ã����������������ڸ�λ�ü�֮ǰ�ķ��ʴ�������ż�ԡ�
    ��ż�Լ��㣺����ÿ�������ţ����������м�λ�ü�֮ǰ�ķ��ʴ��������ۼӵ��ܴ����С�ͨ�������������ж��ܴ�������ż�ԡ�
*/
struct Group {
    LL S, E, D;
    Group(LL s, LL e, LL d) : S(s), E(e), D(d) {}
};

// ������mid֮ǰ��λ�ã���С��Ĺ��׵���ż��
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

        // ���ֲ���
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

        // ͳ�Ƴ��ִ���
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