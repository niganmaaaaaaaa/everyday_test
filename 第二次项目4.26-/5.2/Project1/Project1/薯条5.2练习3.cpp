#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    ���ȣ����� dateToDay ������������¡���ת��Ϊһ���еĵڼ��죬�����������ͳһ����
    ���ţ�����Щ����æµ���ڵ������洢�� busyDays ���鲢����
    Ȼ�󣬼������������ʱ�䡣����Ҫ��������������������һ��æµ�ա�æµ��֮�䡢���һ��æµ�յ���ĩ�����⼸��������ҳ�������������ʱ��Ρ�
    ��󣬰��� ������һ�գ��˼�һ�ꡱ �Ĺ��򣬰����������ת��Ϊ���ϵ�ʱ�䣬ʹ�ù�ʽ 86400 * maxIdleDays / 366 ���㣬���������뵽���������
*/

// ÿ���µ�������4000 ��������
const int daysInMonth[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// ������ת��Ϊһ���еĵڼ���
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

    // ��ȡ�������˼������
    for (int i = 0; i < n; i++) {
        int month, day;
        cin >> month >> day;
        busyDays.push_back(dateToDay(month, day));
    }

    // �Ա������˼�����ڽ�������
    sort(busyDays.begin(), busyDays.end());

    // �������������ʱ��
    int maxIdleDays = 0;
    if (busyDays.empty()) {
        maxIdleDays = 366;
    }
    else {
        // �����������һ��æµ�յĿ���ʱ��
        maxIdleDays = busyDays[0] - 1;
        for (int i = 1; i < busyDays.size(); i++) {
            int idleDays = busyDays[i] - busyDays[i - 1] - 1;
            maxIdleDays = max(maxIdleDays, idleDays);
        }
        // �������һ��æµ�յ���ĩ�Ŀ���ʱ��
        maxIdleDays = max(maxIdleDays, 366 - busyDays.back());
    }

    // ���������ϵ�ʱ�䣨�������뾫ȷ�� 1 �룩
    int heavenTime = static_cast<int>(86400.0 * maxIdleDays / 366 + 0.5);

    cout << heavenTime << endl;

    return 0;
}