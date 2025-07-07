#include<iostream>
#include<math.h>

using namespace std;

double n, m, p,x,y,type;

/*
	平衡点设置不好，没过几组
*/
int main() {
	cin >> n >> m >> p;
	double min1 = 9999999999999,max1=-1;//分界线
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> type;
		if (type == 1) {//日光弹
			min1 = min(min1, y);
		}
		else {//月光弹
			max1 = max(max1, y);
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		if (abs(y-max1)<=abs(y-min1)) {
			cout << "1" << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}

	return 0;
}