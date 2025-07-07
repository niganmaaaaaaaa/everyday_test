#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
    ���������kkksc03��Ҫ��ϰ�Ŀƣ�ÿ����������Ŀ��ÿ����Ŀ��Ҫһ��ʱ�䡣
    ��������������ͬʱ����ͬһ�Ƶ������⣬��������п�Ŀ�����ʱ�䡣����ÿ�ƣ�������Ҫ����Ŀ�ֳ����飬ʹ�����ʱ������Ǹ������ʱ��̡�
    �ؼ�˼·������ÿһ�ƣ���Ŀ���Կ���һ���Ӽ������⣬������Ŀ�ֳ����飬ʹ�������ʱ��֮�;����ܽӽ������������ʱ�伴Ϊ�ÿƵ�������ʱ�䡣
    ��̬�滮�ⷨ��ʹ�ö�̬�滮�����ÿ�Ƶ����ŷ��顣����ÿ�Ƶ���ʱ��sum��Ѱ��һ���Ӽ��ĺ�t��ʹ��t�����ܽӽ�sum��һ�롣
        ʹ�ò�������dp��¼���ܴﵽ���Ӽ��ͣ�����ҵ����Ŀ���t���ÿƵ����ʱ�伴Ϊsum - t��
*/
int main() {
    int s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    int total_time = 0;

    for (int i = 0; i < 4; ++i) {
        vector<int> times(s[i]);
        for (int j = 0; j < s[i]; ++j) {
            cin >> times[j];
        }
        int sum = accumulate(times.begin(), times.end(), 0);
        int max_half = sum / 2;
        vector<bool> dp(max_half + 1, false);
        dp[0] = true;

        for (int a : times) {
            for (int j = max_half; j >= a; --j) {
                if (dp[j - a]) {
                    dp[j] = true;
                }
            }
        }

        int best = 0;
        for (int j = max_half; j >= 0; --j) {
            if (dp[j]) {
                best = j;
                break;
            }
        }
        total_time += (sum - best);
    }

    cout << total_time << endl;
    return 0;
}