//#include<iostream>
//#include<map>
//#include<vector>
//#include<math.h>
//#include<windows.h>
//
//using namespace std;
//int n, m, k, s, p, q, type;//type为0，僵尸城，1危险城，2安全城
//long long MIN = 99999999999999, sum = 0;//最后的价钱
//
//vector<int> jiyihua(51, 0);
//
//void dfs(int index, vector<vector<int>>& a) {
//	//if (a[index][0] == -1||jiyihua[index]!=0) {//记忆化搜索僵尸城以及搜索过得就不搞了
//	//	return;
//	//}
//	jiyihua[index] = 1;//标记搜索过了
//
//	//Sleep(500);
//	sum += a[index][0];//加上该点住宿
//	if (index == n) {//到达终点
//		MIN = min(MIN, sum);
//		cout << sum;
//		cout << endl;
//		jiyihua[n] = 0;
//		//sum -= a[index][0]; 
//		return;
//	}
//	for (int i = 1; i < a[index].size(); ++i) {
//		if (jiyihua[a[index][i]] != 0) continue;//如果下一个点已经探索过了那就不探索了。
//		cout << index << ' ';
//		dfs(a[index][i], a);//搜索拥有的所有的点
//	}
//	sum -= a[index][0];
//	jiyihua[index] = 0;
//}
//
//int main() {
//	cin >> n >> m >> k >> s >> p >> q;
//
//	vector<int> u(1, p);//初始化用
//	vector<vector<int>>  a(n + 1, u);//初始化
//
//	for (int i = 0; i < k; ++i) {
//		int b;
//		cin >> b;
//		a[b][0] = -1;//首元素是价格
//	}
//
//	for (int i = 0; i < m; ++i) {
//		int x, y;
//		cin >> x >> y;
//		if (a[x][0] == -1 && a[y][0] == -1) {
//			continue;
//		}
//		if (a[x][0] == -1) {
//			a[y][0] = q;
//			continue;
//		}
//		else if (a[y][0] == -1) {
//			a[x][0] = q;
//			continue;
//		}
//		a[x].push_back(y);
//		a[y].push_back(x);
//	}
//	for (int i = 0; i < a.size(); ++i) {
//		if ()
//	}
//	a[1][0] = 0;//1，n住宿为0
//	a[n][0] = 0;
//	dfs(1, a);//搜索找最小值
//
//	cout << MIN;
//
//	return 0;
//}