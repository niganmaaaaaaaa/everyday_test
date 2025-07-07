#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int map[1001][1001],n,m;
/*
	ֱ�ӱ��������
		�����ά���飬ÿ��ֵΪ0
		��ÿ������������������ʱ���͸��������Χ�����÷�Χ������ֵ++
	���ֱ�Ӹ���nֵ���������ά����ֵ��

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