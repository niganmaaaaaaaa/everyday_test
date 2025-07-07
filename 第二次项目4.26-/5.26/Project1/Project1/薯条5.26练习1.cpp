#include <iostream>
#include <cstdio>
#include <cmath>
#define mod 2007
#define ll long long
using namespace std;
/*
	ans=4 * n * 5^（n-1）
	找规律找到最后这个结果，在计算就好了
	规律总结https://www.luogu.com.cn/article/9h3upc57
*/

inline long long kp(long long base, long long a);

ll t, n;
long long ans = 0;
int main()
{
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		ans = kp(5, n - 1) * 4 * n % 2007;
		printf("%lld\n", ans);
		ans = 0;
	}
	return 0;
}

inline long long kp(ll base, ll a)
{
	long long turn = 1;
	while (a)
	{
		if (a & 1) turn *= base;
		a >>= 1;
		base *= base;

		turn %= mod;
		base %= mod;
	}
	return turn;
}