#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    首先，借助 dateToDay 函数把输入的月、日转化为一年中的第几天，这样方便后续统一处理。
    接着，将这些代表忙碌日期的天数存储在 busyDays 数组并排序。
    然后，计算最长连续空闲时间。这需要考虑三种情况：年初到第一个忙碌日、忙碌日之间、最后一个忙碌日到年末。在这几种情况中找出空闲天数最多的时间段。
    最后，按照 “天上一日，人间一年” 的规则，把最长空闲天数转化为天上的时间，使用公式 86400 * maxIdleDays / 366 计算，并四舍五入到整数输出。
*/

// 每个月的天数，4000 年是闰年
const int daysInMonth[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 将日期转换为一年中的第几天
int dateToDay(int month, int day) {
    int totalDays = 0;
    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += day;
    return totalDays;
}

int main() {
    int n;
    cin >> n;
    vector<int> busyDays;

    // 读取必须在人间的日期
    for (int i = 0; i < n; i++) {
        int month, day;
        cin >> month >> day;
        busyDays.push_back(dateToDay(month, day));
    }

    // 对必须在人间的日期进行排序
    sort(busyDays.begin(), busyDays.end());

    // 计算最长连续空闲时间
    int maxIdleDays = 0;
    if (busyDays.empty()) {
        maxIdleDays = 366;
    }
    else {
        // 计算年初到第一个忙碌日的空闲时间
        maxIdleDays = busyDays[0] - 1;
        for (int i = 1; i < busyDays.size(); i++) {
            int idleDays = busyDays[i] - busyDays[i - 1] - 1;
            maxIdleDays = max(maxIdleDays, idleDays);
        }
        // 计算最后一个忙碌日到年末的空闲时间
        maxIdleDays = max(maxIdleDays, 366 - busyDays.back());
    }

    // 计算在天上的时间（四舍五入精确到 1 秒）
    int heavenTime = static_cast<int>(86400.0 * maxIdleDays / 366 + 0.5);

    cout << heavenTime << endl;

    return 0;
}