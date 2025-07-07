#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
/*
	����ö��
		ö�ٿ��С����ô���г���С��n���˿��Ի�ã�
		��ô������ȡ��ֵ��С����ֵ���������Ĵ�
*/

int small(int x, int y) {
	return x > y ? y : x;
}
int main() {
	int n, a, b, min = 2e9;
	bool flag = false;
	scanf("%d", &n);
	for (int i = sqrt(12 * n); i >= 3; i--) {
		if (12 * n % i) continue;
		if (i % 3 == 0) a = i, b = 12 * n / i;
		else a = 12 * n / i, b = i;
		for (int j = 0; j <= b / 4; j++) {
			if ((b - 4 * j) % 3 == 0) {
				min = small(small(min, j * a / 3), n - j * a / 3);
				flag = true;
			}
		}
		if (flag == true) break;
	}
	printf("%d", min);
	return 0;
}