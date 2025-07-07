#include<iostream>
#include<vector>
#include<map>

using namespace std;

long long  n, l, r;
vector<long long> nums;
//map<long long, long long > sum;
long long Max=-99999999;

void find(int i,long long count1) {
	if (i > n) {
		if (count1 > Max) {
			Max = count1;
		}
		return;
	}
	count1+= nums[i];
	for (int j = l; j <= r; ++j) {
		find(i + j,count1);
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i <= n; ++i) {
		long long a;
		cin >> a;
		nums.push_back(a);
	}
	find(0, 0);
	cout << Max;

	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
#define N 200001
int dp[N], a[N], n, l, r;
int q[N][2], head = 1, tail = 0;
int main()
{
    scanf("%d%d%d", &n, &l, &r);
    if (l > r) swap(l, r);//防止l比r大
    for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= n - l + 1; i--)
    {
        dp[i] = a[i];
    }
    for (int i = n + 1; i >= l; i--)
    {
        while (tail >= head && dp[i] > q[tail][0]) tail--;
        tail++;
        q[tail][0] = dp[i];
        q[tail][1] = i;
        //以上为将dp[i]打入单调队列
        dp[i - l] = q[head][0] + a[i - l];//更新
        if (i + r == q[head][1]) head++;//弹出
    }
    cout << dp[0];
}