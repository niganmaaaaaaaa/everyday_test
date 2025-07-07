#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> a(20);

int main() {
	a[0].push_back(1);
	a[0].push_back(0);
	a[1].push_back(0);
	a[1].push_back(1);
	for (int i = 2; i < 20; ++i) {
		a[i].push_back(a[i - 1][0] + a[i - 2][0]);
		a[i].push_back(a[i - 1][1] + a[i - 2][1]);
	}
	int x, y, xx,n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> xx >> y;
		if (x % 3 == 0) {
			if ((xx & 1) == 0) {
				cout << -1 << endl;
				continue;
			}
		}
		int d;
		d = (xx - a[x - 1][1]) / (a[x - 1][0] + a[x - 1][1]);
		cout << (a[y - 1][0] + a[y - 1][1]) * d + a[y - 1][1] << endl;
	}
	

	return 0;
}