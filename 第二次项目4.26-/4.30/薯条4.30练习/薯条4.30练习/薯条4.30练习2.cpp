#include <iostream>
using namespace std;

/*
    使用二维数组maze标记障碍物位置，二维数组vis记录访问状态。
    DFS算法：从起点开始，递归尝试四个方向的移动。每次移动前检查是否越界、是否遇到障碍物、是否已访问过该位置。到达终点时计数器加一，回溯时重置访问状态。
    边界处理：特别注意起点和终点重合的情况，以及终点被障碍物阻挡的情况。
*/

int n, m, t;
int sx, sy, fx, fy;
int maze[6][6] = { 0 }; // 迷宫，1表示障碍
bool vis[6][6] = { false }; // 访问标记
int ans = 0;

// 方向数组：上下左右
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    if (x == fx && y == fy) { // 到达终点
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) { // 尝试四个方向
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 检查新坐标是否合法且可走
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
            && maze[nx][ny] == 0 && !vis[nx][ny]) {
            vis[nx][ny] = true;
            dfs(nx, ny);
            vis[nx][ny] = false; // 回溯
        }
    }
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    // 设置障碍物
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }
    // 终点是障碍物直接返回0
    if (maze[fx][fy] == 1) {
        cout << 0 << endl;
        return 0;
    }
    vis[sx][sy] = true; // 起点已访问
    dfs(sx, sy); // 开始搜索
    cout << ans << endl;
    return 0;
}