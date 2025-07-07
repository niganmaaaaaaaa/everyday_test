#include<iostream>
#include<vector>

using namespace std;
/*
*	�����õĶ������˼·��
	ʹ�õ��˵ڶ���ʲô˹���֣�������н���������⣬����Ȥ����ȥ�������Ұ�����Ӧ��
	https://zhuanlan.zhihu.com/p/350774728	

	˼·������n����������ͳ�Ƹ���
	Ȼ���õ��ڶ���˹���֣�Ҳ���Ǽ���������� ��ͳ�Ƶĸ�����ѡk�����ķ�������C �±�count1  �ϱ�k
		��������������㣬��ʱ������ʹ��������ڶ���˹���ּ��㷽����������ø���������ϴ�
	����Ҫ������������������ã�ֻ��Ҫ�������Ϳ��Լ��㷽���������Լ�������ϵļ��㷽��
*/

long long t, n, k;//���˸�����
int s[9][9];

void jisuan1() {
	s[0][0] = 1;
	// �ڶ���Stirling�����㣬������s[count1][k]�� ����������ʲô
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			s[i][j] = j * s[i - 1][j] + s[i - 1][j - 1];
		}
	}
}

int jisuan(long long n, long long k) {
	int count1 = 0;
	int n1 = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			count1++;
		}
		while (n % i == 0) {
			n /= i;//�������i�ı������´���
		}
	}
	if (n > 1) {
		count1++;
	} // ���ֽ��������
	if (count1 < k) {//����������Ҫ��
		return 0;
	}
	else {
		//int a, b;  ��ʱ
		//for (int i = count1; i > k; --i) {
		//	a *= i;
		//}
		//for (int i = k; i > 0; ++i) {
		//	b *= i;
		//}
		//return a / b;
		return s[count1][k];
	}
}

int main() {
	cin >> t;
	jisuan1();
	while (t--) {
		cin >> n >> k;
		cout << jisuan(n, k) << endl;
	}

	return 0;
}