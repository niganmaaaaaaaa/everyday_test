#include<iostream>
#include<vector>

using namespace std;

/*
	这个应该是约瑟夫环吧，那么关键就是除余操作了
	记录轮盘图案顺序，还有每次所转的次数，也就数据多点
	三个轮盘，依次对应三个转次
		可以用三个变量依次记录当前的图案索引，并且每次转后都	%图案数 除余操作，保证不越界
	将每次转的结果都存储起来，并判断加多少分，加到最后结果里去
		这个判断简单点，随便搞搞就行
*/


vector<vector<int>> nums;//三个轮盘的图案数，记录输入的数据
vector<vector<int>> cnt;//每次每个轮盘转的次数
long long counts[3];

int check(int x, int y, int z)
{
	//判定方法1
	if (x == y && y == z && x == z)return 200;
	//判定方法2
	if (x == y || y == z || x == z)return 100;
	//判定方法3
	if (y == x + 1 && z == y + 1)return 200;
	//判定方法4
	int mx = max(x, max(y, z));
	int mn = min(x, min(y, z));
	int md = x + y + z - mx - mn;
	//mx,md,mn为最大值，中间值，最小值
	//mn,md,mx从小到大排序
	if (md == mn + 1 && mx == md + 1)return 100;
	return 0;
}

int main() {
	long long n,m,score=0;//n,m和计数
	cin >> n;

	for (int i = 0; i < 3; ++i) {//载入数据
		vector<int> a;
		for (int j = 0; j < n; ++j) {
			long long nums1;
			cin >> nums1;
			a.push_back(nums1);
		}
		nums.push_back(a);
	}
	cin >> m;//转的次数
	for (int i = 0; i < m; ++i) {
		vector<int> b;
		for (int j = 0; j < 3; ++j) {
			long long cnt1;
			cin >> cnt1;
			b.push_back(cnt1);
		}
		cnt.push_back(b);
	}
	int index[3] = { 0 };
	for (int i = 0; i < m; ++i) {
		index[0] = (index[0] + cnt[i][0]) % n;//记录索引
		index[1] = (cnt[i][1] + index[1]) % n;
		index[2] = (index[2] + cnt[i][2]) % n;
		for (int j = 0; j < 3; ++j) {
			counts[j] = nums[j][index[j]];//存储每轮的图案
		}
		score += check(counts[0],counts[1],counts[2]);//判断图案得分
	}
	cout << score;
	return 0;
}