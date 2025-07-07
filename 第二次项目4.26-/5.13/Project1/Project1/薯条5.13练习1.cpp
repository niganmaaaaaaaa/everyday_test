#include <iostream>
#include <cstring>
using namespace std;
/*
    坐标计算：首先根据输入的楼间距离，计算每栋楼的坐标。
    预处理前缀和：计算每个区间内学生数的前缀和以及带权位置的前缀和，以便快速计算某个区间内学生到某一点的带权距离之和。
    计算最小距离成本：对于每个可能的区间，计算在该区间内建立一所小学的最小带权距离和。这里使用带权中位数来确定最优的学校位置。
    动态规划：使用动态规划来划分区间，将问题分解为多个子问题，逐步求解前i栋楼建立j所小学的最小带权距离和。
*/
const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int n, k;
int s[MAXN];
int d[MAXN];
int pos[MAXN];
int sum_s[MAXN][MAXN];
int sum_pos[MAXN][MAXN];
int cost[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i < n; ++i)
        cin >> d[i];
    pos[1] = 0;
    for (int i = 2; i <= n; ++i)
        pos[i] = pos[i - 1] + d[i - 1];
    // 预处理sum_s和sum_pos
    for (int i = 1; i <= n; ++i) {
        sum_s[i][i] = s[i];
        sum_pos[i][i] = s[i] * pos[i];
        for (int j = i + 1; j <= n; ++j) {
            sum_s[i][j] = sum_s[i][j - 1] + s[j];
            sum_pos[i][j] = sum_pos[i][j - 1] + s[j] * pos[j];
        }
    }
    // 计算cost[i][j]
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int min_cost = INF;
            for (int m = i; m <= j; ++m) {
                int sum_s_left = sum_s[i][m];
                int sum_s_right = (m + 1 > j) ? 0 : sum_s[m + 1][j];
                int sum_pos_left = sum_pos[i][m];
                int sum_pos_right = (m + 1 > j) ? 0 : sum_pos[m + 1][j];
                int total = pos[m] * (sum_s_left - sum_s_right) + (sum_pos_right - sum_pos_left);
                if (total < min_cost)
                    min_cost = total;
            }
            cost[i][j] = min_cost;
        }
    }
    // 初始化动态规划数组
    memset(dp, INF, sizeof(dp));
    for (int j = 1; j <= n; ++j)
        dp[1][j] = cost[1][j];
    // 动态规划处理
    for (int t = 2; t <= k; ++t) {
        for (int j = t; j <= n; ++j) {
            dp[t][j] = INF;
            for (int m = t - 1; m < j; ++m) {
                if (dp[t - 1][m] + cost[m + 1][j] < dp[t][j])
                    dp[t][j] = dp[t - 1][m] + cost[m + 1][j];
            }
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}