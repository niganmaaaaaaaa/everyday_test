#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int map[1001][1001],n,m;
/*
	直接暴力解决了
		定义二维数组，每个值为0
		在每次输入左上右下坐标时，就根据这个范围，来让范围内坐标值++
	最后直接根据n值，输出最后二维数组值。

*/

int main() {
	cin >> n >> m;
	memset(map, 0, sizeof(int) * 1001 * 1001);
	for (int i = 0; i < m; ++i) {
		int x, y,x1,y1;
		cin >> x>>y>>x1>>y1;
		for (int j = x; j <= x1; ++j) {
			for (int k = y; k <= y1; ++k) {
				map[j][k]++;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}