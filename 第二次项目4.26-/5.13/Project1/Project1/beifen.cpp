//#include<iostream>
//#include<map>
//#include<vector>
//#include<math.h>
//#include<windows.h>
//
//using namespace std;
//int n, m, k, s, p, q, type;//typeΪ0����ʬ�ǣ�1Σ�ճǣ�2��ȫ��
//long long MIN = 99999999999999, sum = 0;//���ļ�Ǯ
//
//vector<int> jiyihua(51, 0);
//
//void dfs(int index, vector<vector<int>>& a) {
//	//if (a[index][0] == -1||jiyihua[index]!=0) {//���仯������ʬ���Լ��������þͲ�����
//	//	return;
//	//}
//	jiyihua[index] = 1;//�����������
//
//	//Sleep(500);
//	sum += a[index][0];//���ϸõ�ס��
//	if (index == n) {//�����յ�
//		MIN = min(MIN, sum);
//		cout << sum;
//		cout << endl;
//		jiyihua[n] = 0;
//		//sum -= a[index][0]; 
//		return;
//	}
//	for (int i = 1; i < a[index].size(); ++i) {
//		if (jiyihua[a[index][i]] != 0) continue;//�����һ�����Ѿ�̽�������ǾͲ�̽���ˡ�
//		cout << index << ' ';
//		dfs(a[index][i], a);//����ӵ�е����еĵ�
//	}
//	sum -= a[index][0];
//	jiyihua[index] = 0;
//}
//
//int main() {
//	cin >> n >> m >> k >> s >> p >> q;
//
//	vector<int> u(1, p);//��ʼ����
//	vector<vector<int>>  a(n + 1, u);//��ʼ��
//
//	for (int i = 0; i < k; ++i) {
//		int b;
//		cin >> b;
//		a[b][0] = -1;//��Ԫ���Ǽ۸�
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
//	a[1][0] = 0;//1��nס��Ϊ0
//	a[n][0] = 0;
//	dfs(1, a);//��������Сֵ
//
//	cout << MIN;
//
//	return 0;
//}