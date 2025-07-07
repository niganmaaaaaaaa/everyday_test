#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
/*
     超时了两个，不优化了
     问题转换：将问题转换为背包问题，其中每个字符串的价值是 'c' 的数量，重量是's' 和 'c' 的数量差。
    动态规划：使用动态规划维护每个可能的重量差对应的最大价值和。
    状态转移：对于每个字符串，更新所有可能的重量差对应的最大价值和。
     
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (char c : s) {
            if (c == 's') a++;
            else if (c == 'c') b++;
        }
        int d = a - b;
        int val = b;
        unordered_map<int, int> tmp(dp);
        for (const auto& p : dp) {
            int new_d = p.first + d;
            int new_val = p.second + val;
            if (tmp.find(new_d) == tmp.end() || new_val > tmp[new_d]) {
                tmp[new_d] = new_val;
            }
        }
        dp = tmp;
    }
    cout << (dp.count(0) ? dp[0] : 0) << endl;
    return 0;
}