#include<iostream>
#include<math.h>

using namespace std;

double n, m, p,x,y,type;

/*
	ƽ������ò��ã�û������
*/
int main() {
	cin >> n >> m >> p;
	double min1 = 9999999999999,max1=-1;//�ֽ���
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> type;
		if (type == 1) {//�չⵯ
			min1 = min(min1, y);
		}
		else {//�¹ⵯ
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