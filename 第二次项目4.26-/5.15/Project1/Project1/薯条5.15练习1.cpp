#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
/*
    动态规划状态定义
    定义 dp[i][j] 表示到达第 i 行第 j 列时能获得的最大P点值。由于每秒必须下移一行，每个位置的最大值仅依赖于上一行的某些位置。
    转移方程
        对于每个位置 j，其前一行可能的列范围为 [j-T, j+T]。直接遍历这些列的时间复杂度为 O(T*M*N)，无法处理大输入。
    使用单调队列优化滑动窗口最大值：
        左到右扫描：维护一个窗口 [j-T, j]，计算每个位置左侧的最大值 max_left[j]。
        右到左扫描：维护窗口 [j, j+T]，计算右侧最大值 max_right[j]。
        合并 max_left 和 max_right 得到每个位置的前驱最大值。
    具体步骤
        初始化第一行的 dp 值为对应格子的P点。
        对后续每一行，分别计算 max_left 和 max_right 数组，合并后更新当前行的 dp 值。
        最终结果为最后一行 dp 的最大值。
*/
int main() {
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<vector<int>> val_grid(N, vector<int>(M, 0));
    for (int k = 0; k < K; ++k) {
        int x, y, v;
        cin >> x >> y >> v;
        x--; // 转换为0-based索引
        y--;
        val_grid[x][y] = v;
    }

    vector<int> prev_dp(M);
    for (int j = 0; j < M; ++j) {
        prev_dp[j] = val_grid[0][j];
    }

    for (int i = 1; i < N; ++i) {
        vector<int> current_dp(M, 0);
        vector<int> max_left(M, 0);
        deque<int> dq_left;

        // 计算max_left数组
        for (int j = 0; j < M; ++j) {
            int left = max(0, j - T);
            while (!dq_left.empty() && dq_left.front() < left) {
                dq_left.pop_front();
            }
            while (!dq_left.empty() && prev_dp[dq_left.back()] <= prev_dp[j]) {
                dq_left.pop_back();
            }
            dq_left.push_back(j);
            max_left[j] = prev_dp[dq_left.front()];
        }

        // 计算max_right数组
        vector<int> max_right(M, 0);
        deque<int> dq_right;
        for (int j = M - 1; j >= 0; --j) {
            int right = min(M - 1, j + T);
            while (!dq_right.empty() && dq_right.front() > right) {
                dq_right.pop_front();
            }
            while (!dq_right.empty() && prev_dp[dq_right.back()] <= prev_dp[j]) {
                dq_right.pop_back();
            }
            dq_right.push_back(j);
            max_right[j] = prev_dp[dq_right.front()];
        }

        // 计算current_dp
        for (int j = 0; j < M; ++j) {
            int max_prev = max(max_left[j], max_right[j]);
            current_dp[j] = max_prev + val_grid[i][j];
        }

        prev_dp.swap(current_dp);
    }

    cout << *max_element(prev_dp.begin(), prev_dp.end()) << endl;

    return 0;
}