#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    ˼·������ϲ�ȥ��
    Ҫ���������串�ǵ��ܳ��ȡ�����������ܴ����ص������ڣ�ֱ���ۼӻᵼ���ظ����㡣
        ���������䰴����������С���������������λ�ù�ϵ��ȷ�����ںϲ�������
        ��ʼ����ǰ�ϲ�����Ϊ��һ�����䣬���α�������ÿ�����䣺
            ����ǰ������������ �� ��ǰ�ϲ�������յ㣬˵�����������ص������ڣ��ϲ�Ϊһ����������䣨�յ�ȡ�������ֵ����
            �����ཻ���򽫵�ǰ�ϲ����䱣�棬������Ϊ�µı������䡣
    ͳ���ܳ��ȣ��ϲ���ɺ���������˴˶����Ҳ��ص���ֱ���ۼ�ÿ������ĳ��ȣ��յ�-��㣩��Ϊ�𰸡�
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> intervals;
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        intervals.emplace_back(a, b);
    }

    sort(intervals.begin(), intervals.end());

    vector<pair<long long, long long>> merged;
    long long current_start = intervals[0].first;
    long long current_end = intervals[0].second;

    for (size_t i = 1; i < intervals.size(); ++i) {
        long long a = intervals[i].first;
        long long b = intervals[i].second;

        if (a <= current_end) {
            current_end = max(current_end, b);
        }
        else {
            merged.emplace_back(current_start, current_end);
            current_start = a;
            current_end = b;
        }
    }

    merged.emplace_back(current_start, current_end);

    long long total = 0;
    for (const auto& p : merged) {
        total += p.second - p.first;
    }

    cout << total << endl;

    return 0;
}