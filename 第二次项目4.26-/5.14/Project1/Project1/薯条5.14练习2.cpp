#include<iostream>

using namespace std;
/*
	ȫ����ѧ����������������Ӧ��û����
	

*/
int main() {
	double a[8], sum = 0,result;
	for (int i = 1; i < 8; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	result = a[1] / sum * 1.0 * a[2] / (sum - 1) * a[3] / (sum - 2) * a[4] / (sum - 3) * a[5] / (sum - 4) * a[6] / (sum - 5) * a[7] * 5040;
	printf("%.3f", result);

	return 0;
}