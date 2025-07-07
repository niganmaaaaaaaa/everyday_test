#include <iostream>
#include <cstring>
using namespace std;
/*
    ������㣺���ȸ��������¥����룬����ÿ��¥�����ꡣ
    Ԥ����ǰ׺�ͣ�����ÿ��������ѧ������ǰ׺���Լ���Ȩλ�õ�ǰ׺�ͣ��Ա���ټ���ĳ��������ѧ����ĳһ��Ĵ�Ȩ����֮�͡�
    ������С����ɱ�������ÿ�����ܵ����䣬�����ڸ������ڽ���һ��Сѧ����С��Ȩ����͡�����ʹ�ô�Ȩ��λ����ȷ�����ŵ�ѧУλ�á�
    ��̬�滮��ʹ�ö�̬�滮���������䣬������ֽ�Ϊ��������⣬�����ǰi��¥����j��Сѧ����С��Ȩ����͡�
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
    // Ԥ����sum_s��sum_pos
    for (int i = 1; i <= n; ++i) {
        sum_s[i][i] = s[i];
        sum_pos[i][i] = s[i] * pos[i];
        for (int j = i + 1; j <= n; ++j) {
            sum_s[i][j] = sum_s[i][j - 1] + s[j];
            sum_pos[i][j] = sum_pos[i][j - 1] + s[j] * pos[j];
        }
    }
    // ����cost[i][j]
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
    // ��ʼ����̬�滮����
    memset(dp, INF, sizeof(dp));
    for (int j = 1; j <= n; ++j)
        dp[1][j] = cost[1][j];
    // ��̬�滮����
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