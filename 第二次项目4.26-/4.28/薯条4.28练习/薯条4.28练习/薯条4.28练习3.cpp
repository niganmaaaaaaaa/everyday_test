#include<iostream>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

long long n, m, counts, count1, result = 0, Max = -1;

long long num[500001] = { 0 };
map<pair<long long, long long >, long long > Map;
long long count2 = 0;//map数量

long long  jiecheng(long long a) {
	long long b = a, c = 1;
	a--;
	while (a > 0) {
		b *= a;
		a--;
	}
	return b;
}

int main() {
	cin >> counts;
	vector<long long > nums(counts);

	//memset(num, 0, sizeof(long long) * 50001);
	for (int i = 0; i < counts; ++i) {
		long long  a;
		cin >> a;
		nums[i] = a;
		Max = max(Max, a);

		num[a]++;
		count1++;
		if (num[a] > 1) {
			count1--;//种类数
		}
	}
	for (int i = 0; i < nums.size(); ++i) {//遍历所有的数
		for (int j = 0; j < nums.size(); ++j) {
			if (i == j) continue;//跳过自身
			if (nums[i] * nums[j] == counts - 2) {

				int count3 = count2;
				Map.insert(make_pair(make_pair(nums[i], nums[j]), i));
				count2 = Map.size();
				if (count3 == count2) continue;

				num[nums[i]] -= 1;
				num[nums[j]] -= 1;

				long long all = 0;
				for (int k = 0; k <= Max; ++k) {
					if (num[k] != 0) {
						all += num[k];
					}
				}

				all = jiecheng(all);
				for (int k = 0; k <= Max; ++k) {
					if (num[k] != 0) {
						all /= num[k];
					}
				}
				result += all;

				num[nums[i]] += 1;
				num[nums[j]] += 1;
			}
		}
	}
	cout << result << endl;

	return 0;
}