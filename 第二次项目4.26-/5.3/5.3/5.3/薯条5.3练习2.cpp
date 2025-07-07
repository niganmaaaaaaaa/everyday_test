#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    思路：区间合并去重
    要计算多个区间覆盖的总长度。由于区间可能存在重叠或相邻，直接累加会导致重复计算。
        将所有区间按起点升序排列。排序后，相邻区间的位置关系明确，便于合并操作。
        初始化当前合并区间为第一个区间，依次遍历后续每个区间：
            若当前遍历区间的起点 ≤ 当前合并区间的终点，说明两区间有重叠或相邻，合并为一个更大的区间（终点取两者最大值）。
            若不相交，则将当前合并区间保存，并更新为新的遍历区间。
    统计总长度：合并完成后，所有区间彼此独立且不重叠，直接累加每个区间的长度（终点-起点）即为答案。
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