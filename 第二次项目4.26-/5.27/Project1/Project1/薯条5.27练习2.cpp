#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
/*
	这是一个模拟，把管道看成是两条边，连着两个点，每个点有一个极限权值，如果大于就输出-1，
	因为水面再也无法上涨了；水从第一个点开始流，然后按照常识去算什么时候可以流到另一个管子里；
		首先将所有没有水但是可以被灌到水的管子标记为有水，然后求出有水的管子里水面高度的最小值。
		如果蜘蛛所在的管子有水且最小值为蜘蛛的位置，那么说明此时蜘蛛碰到了水，因为如果最小值大于蜘蛛高度，那么蜘蛛一定会被淹死，管子是个连通器。
	然后我们就比较深度就可以了，深度可以转化成高度，逆转一下，就比较好想了。
	参考题解：https://www.luogu.com.cn/article/zc3y6m2l
*/

struct node {
	int x, y, h;
}a[201];
bool f[201];
int n, m, x, y, z, t, cnt, head[2001], u, v, w;
struct Edge {
	int w, nxt, to;
}edge[201 * 201];
int hh(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i].x == x)
			return i;
	}
}
void add(int u, int v, int w)
{
	edge[++cnt].to = v;
	edge[cnt].nxt = head[u];
	edge[cnt].w = w;
	head[u] = cnt;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].h);
		a[i].h += a[i].y;
	}
	f[1] = 1;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		w = hh(u + w);
		u = hh(u - 1);
		add(u, w, v);
		add(w, u, v);
	}
	scanf("%d%d", &x, &y);
	while (1)
	{
		bool ff = 1;
		while (ff)
		{
			ff = 0;
			for (int i = 1; i <= n; i++)
			{
				if (f[i])
				{
					for (int j = head[i]; j; j = edge[j].nxt)
					{
						if (a[i].h <= edge[j].w && !f[edge[j].to])
							f[edge[j].to] = ff = 1;
					}
				}
			}
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			if (f[i])
				maxn = max(maxn, a[i].h);
			if (f[x] && maxn == y)
			{
				cout << t << endl;
				return 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (f[i] && a[i].y == a[i].h && a[i].y == maxn)
			{
				cout << "-1";
				return 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (f[i] && a[i].h == maxn)
			{
				a[i].h--;
				t++;
			}
		}
	}
	return 0;
}