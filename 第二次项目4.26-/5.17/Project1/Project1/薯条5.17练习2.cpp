#include<iostream>
#include<vector>
#include<algorithm>
/*
	̰��
	�洢����һ����׼��ÿ����ʿ�ܿ��Ĵ���*���Ĺ�����
		  ���������׼���д洢��������
	����̰�ĵ�˼·�����������Ҫ5��Ӣ�ۣ���ô����˳��	1 2 3 4 5
		 ȡ����ĺ�����������Ӧ������������������ĵ�����5����*λ��1��������4����*λ��2....���������Ĺ����ܺʹ��ڵ���hp
		 ��������뷨��������1������Ҳ���������Ǹ������в�������������ܺ�С��hp����ô����������������������
��������	1		2		3		4		5	λ��
			max
			max-1	max
			max-2	max-1	max
			.........
			ע���������ֵ����->max
*/
using namespace std;
long long hp, atk, a, h, suma = 0, n;
vector<long long> sums;
int main() {
	cin >> n;
	cin >> atk >> hp;
	for (int i = 0; i < n; ++i) {
		cin >> a >> h;
		long long res = h / atk;
		if (h % atk != 0) {
			sums.push_back((res + 1) * a);
		}
		else {
			sums.push_back(res * a);
		}
	}
	sort(sums.begin(), sums.end());
	long long count1 = 1, mid = n / 2;
	while (suma < hp) {
		if (count1 > sums.size() - 1) {
			cout << "false";
			return 0;
		}
		suma = 0;
		long long xishu = 1;
		for (int i = sums.size() - count1; i < sums.size(); ++i) {
			suma += sums[i] * xishu;
			xishu++;
		}
		count1++;

	}
	cout << count1 - 1;
	return 0;
}