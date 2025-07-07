#include <iostream>
using namespace std;

/*
    ʹ�ö�ά����maze����ϰ���λ�ã���ά����vis��¼����״̬��
    DFS�㷨������㿪ʼ���ݹ鳢���ĸ�������ƶ���ÿ���ƶ�ǰ����Ƿ�Խ�硢�Ƿ������ϰ���Ƿ��ѷ��ʹ���λ�á������յ�ʱ��������һ������ʱ���÷���״̬��
    �߽紦���ر�ע�������յ��غϵ�������Լ��յ㱻�ϰ����赲�������
*/

int n, m, t;
int sx, sy, fx, fy;
int maze[6][6] = { 0 }; // �Թ���1��ʾ�ϰ�
bool vis[6][6] = { false }; // ���ʱ��
int ans = 0;

// �������飺��������
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    if (x == fx && y == fy) { // �����յ�
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) { // �����ĸ�����
        int nx = x + dx[i];
        int ny = y + dy[i];
        // ����������Ƿ�Ϸ��ҿ���
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
            && maze[nx][ny] == 0 && !vis[nx][ny]) {
            vis[nx][ny] = true;
            dfs(nx, ny);
            vis[nx][ny] = false; // ����
        }
    }
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    // �����ϰ���
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }
    // �յ����ϰ���ֱ�ӷ���0
    if (maze[fx][fy] == 1) {
        cout << 0 << endl;
        return 0;
    }
    vis[sx][sy] = true; // ����ѷ���
    dfs(sx, sy); // ��ʼ����
    cout << ans << endl;
    return 0;
}