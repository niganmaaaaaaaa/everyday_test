#include <iostream>
#include <vector>
using namespace std;
/*
    动态规划,01背包问题
        在容量 V 的箱子中装入物品，使总体积最大。剩余空间即为 V - 最大体积。
        状态dp[j] 表示容量为 j 时能装入的最大体积。
        状态转移方程思路：
            逆序遍历容量（从 V 到物品体积 v），确保每个物品只被选取一次。
            dp[j] = max(dp[j], dp[j - v] + v)。
        最终 dp[V] 为最大装入体积，剩余空间为 V - dp[V]。
*/
int main() {
    int V, n;
    cin >> V >> n;
    vector<int> volumes(n);
    for (int i = 0; i < n; ++i) {
        cin >> volumes[i];
    }

    vector<int> dp(V + 1, 0); // 初始化dp数组，表示容量为j时的最大装入体积

    for (int v : volumes) {
        // 逆序遍历防止重复选取
        for (int j = V; j >= v; --j) {
            // 更新当前容量下的最大体积
            if (dp[j - v] + v > dp[j]) {
                dp[j] = dp[j - v] + v;
            }
        }
    }

    cout << V - dp[V] << endl; // 剩余空间 = 总容量 - 最大装入体积
    return 0;
}