#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
    问题分析：kkksc03需要复习四科，每科有若干题目，每个题目需要一定时间。
    他可以用左右脑同时处理同一科的两道题，求完成所有科目的最短时间。对于每科，我们需要将题目分成两组，使得完成时间最长的那个组的用时最短。
    关键思路：对于每一科，题目可以看作一个子集和问题，即将题目分成两组，使得两组的时间之和尽可能接近。这样，最大时间即为该科的最短完成时间。
    动态规划解法：使用动态规划来求解每科的最优分组。对于每科的总时间sum，寻找一个子集的和t，使得t尽可能接近sum的一半。
        使用布尔数组dp记录可能达到的子集和，最后找到最大的可行t，该科的最短时间即为sum - t。
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