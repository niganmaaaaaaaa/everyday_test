#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
/*
    �������
        ���Ѻܼ򵥣���¼һ��Ŀǰ�Ե�������θ����������
    ���������ο�https://www.luogu.com.cn/article/7rbg8975
*/
using namespace std;
int read() {
    int a = 0, k = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-')k = -1; c = getchar(); }
    while (isdigit(c)) { a = a * 10 + c - '0'; c = getchar(); }
    return a * k;
}
int n, m, vis[5000005], maxn = 0;
struct node {
    int num, vis;
};
int main() {
    int x, y;
    memset(vis, 0, sizeof(vis));
    n = read(); x = read(); y = read();
    queue<node>q;//����һ��q����
    node a; a.num = x; a.vis = 0;
    node b; b.num = y; b.vis = 0;
    q.push(a); q.push(b);
    vis[x] = 1; vis[y] = 1;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (t.num + x > n)maxn = max(maxn, t.num);
        if (t.num + x <= n && vis[t.num + x] == 0) { vis[t.num + x] = 1; node k; k.num = t.num + x; k.vis = t.vis; q.push(k); }
        if (t.num + y > n)maxn = max(maxn, t.num);
        if (t.num + y <= n && vis[t.num + y] == 0) { vis[t.num + y] = 1; node k; k.num = t.num + y; k.vis = t.vis; q.push(k); }
        if (t.vis == 0 && vis[t.num / 2] == 0) { vis[t.num / 2] = 1; node k; k.num = t.num / 2; k.vis = 1; q.push(k); }
    }
    printf("%d\n", maxn);//������ֵ
    return 0;
}