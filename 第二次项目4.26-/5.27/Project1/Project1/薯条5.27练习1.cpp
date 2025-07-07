#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/*
	��Դ���·����
		������ǰ�������������·����Ȼ���ٸ����յ�仯���ʵ���ȥ����ĳ��������·��
	���鿴���https://www.luogu.com.cn/article/azvbm988
*/

#define inf 2147483647
#define int long long
int n, m, b, s;
struct edge {
	int to, next, dis;
}e[1100000];
int dis[1100000], vis[1100000];
int head[1100000], tot, t;
struct cg {
	int time, x;
}c[1100000];
struct node {
	int dis, pos;
	bool operator<(const node& x)const {
		return x.dis < dis;
	}
};
priority_queue<node>q;
inline void add(int x, int y, int w) {
	e[++tot].to = y;
	e[tot].next = head[x];
	e[tot].dis = w;
	head[x] = tot;
}
inline bool cmp(cg a, cg b) {
	return a.time < b.time;
}
void dijkstra() {
	dis[b] = 0;
	q.push((node) { 0, b });
	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		int x = tmp.pos;
		if (vis[x])continue;
		vis[x] = 1;
		for (int i = head[x]; i; i = e[i].next) {
			int y = e[i].to;
			if (dis[y] > dis[x] + e[i].dis) {
				dis[y] = dis[x] + e[i].dis;
				if (!vis[y])q.push((node) { dis[y], y });
			}
		}
	}
}
signed main() {
	scanf("%lld%lld%lld%lld", &n, &m, &b, &s);
	for (int i = 1; i <= n; ++i)dis[i] = inf;
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		add(x, y, z); add(y, x, z);
	}scanf("%lld", &t);
	for (int i = 1; i <= t; ++i)scanf("%lld%lld", &c[i].time, &c[i].x);
	sort(c + 1, c + t + 1, cmp);//���������� 
	dijkstra();//dijkstra
	c[0].x = s;//��ʼ�� 
	for (int i = 1; i <= t; ++i)
		if (dis[c[i].x] < c[i + 1].time) {//�ж��ܷ񵽴� 
			printf("%lld\n", max(dis[c[i].x], c[i].time));//�ܾ�����ϴ���Ǹ� 
			return 0;
		}
	printf("%lld\n", max(dis[c[t].x], c[t].time));//������һ���������ץס 
	return 0;
}