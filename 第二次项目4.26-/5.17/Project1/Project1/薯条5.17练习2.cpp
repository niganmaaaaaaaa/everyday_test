#include<iostream>
#include<vector>
#include<algorithm>
/*
	贪心
	存储：搞一个标准，每个勇士能抗的次数*他的攻击力
		  按照这个标准进行存储，并排序
	按照贪心的思路，例如最后需要5个英雄，那么出场顺序	1 2 3 4 5
		 取数组的后五个数，相对应的依次是排序后的数组的倒数第5个数*位数1，倒数第4个数*位数2....，并且最后的攻击总和大于等于hp
		 按照这个想法，首先是1个数，也就是最大的那个数进行操作，如果攻击总和小于hp，那么就增加人数，依次往后排
操作步骤	1		2		3		4		5	位次
			max
			max-1	max
			max-2	max-1	max
			.........
			注：数组最大值索引->max
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