#include<iostream>
#include<vector>

using namespace std;

long long  n,count1=0,type,Max;
vector<long long> nums(1,0);

void count2(int l, int r) {
	long long  Min = 9999999;
	for (int i = l; i <= r; ++i) {
		Min = min(Min, nums[i]);
	}
	for (int i = l; i <= r; ++i) {
		nums[i] -= Min;
	}
	count1 += Min;
}

int main() {
	cin >> n;
	for (int k = 1; k <= n; ++k) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
	nums.push_back(0);
	long long i=1, j=i;

	while (1) {
		i = 1;
		while(nums[i] < 1&&i<=n) {
			++i;
		}
		j = i;
		while (nums[j]>0&&j<=n) {
			++j;
		}
		if (i >n) {//说明已经解决完了
			break;
		}
		count2(i, --j);
	}

	cout << count1;
	return 0;
}