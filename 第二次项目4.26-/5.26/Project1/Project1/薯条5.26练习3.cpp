#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
/*
	暴力枚举
		枚举宽大小，那么就有长大小（n有了可以获得）
		那么这两者取差值最小绝对值，就是最后的答案
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