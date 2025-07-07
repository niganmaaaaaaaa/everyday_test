#include<iostream>
#include<vector>

using namespace std;

/*
	���Ӧ����Լɪ�򻷰ɣ���ô�ؼ����ǳ��������
	��¼����ͼ��˳�򣬻���ÿ����ת�Ĵ�����Ҳ�����ݶ��
	�������̣����ζ�Ӧ����ת��
		�����������������μ�¼��ǰ��ͼ������������ÿ��ת��	%ͼ���� �����������֤��Խ��
	��ÿ��ת�Ľ�����洢���������жϼӶ��ٷ֣��ӵ��������ȥ
		����жϼ򵥵㣬��������
*/


vector<vector<int>> nums;//�������̵�ͼ��������¼���������
vector<vector<int>> cnt;//ÿ��ÿ������ת�Ĵ���
long long counts[3];

int check(int x, int y, int z)
{
	//�ж�����1
	if (x == y && y == z && x == z)return 200;
	//�ж�����2
	if (x == y || y == z || x == z)return 100;
	//�ж�����3
	if (y == x + 1 && z == y + 1)return 200;
	//�ж�����4
	int mx = max(x, max(y, z));
	int mn = min(x, min(y, z));
	int md = x + y + z - mx - mn;
	//mx,md,mnΪ���ֵ���м�ֵ����Сֵ
	//mn,md,mx��С��������
	if (md == mn + 1 && mx == md + 1)return 100;
	return 0;
}

int main() {
	long long n,m,score=0;//n,m�ͼ���
	cin >> n;

	for (int i = 0; i < 3; ++i) {//��������
		vector<int> a;
		for (int j = 0; j < n; ++j) {
			long long nums1;
			cin >> nums1;
			a.push_back(nums1);
		}
		nums.push_back(a);
	}
	cin >> m;//ת�Ĵ���
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
		index[0] = (index[0] + cnt[i][0]) % n;//��¼����
		index[1] = (cnt[i][1] + index[1]) % n;
		index[2] = (index[2] + cnt[i][2]) % n;
		for (int j = 0; j < 3; ++j) {
			counts[j] = nums[j][index[j]];//�洢ÿ�ֵ�ͼ��
		}
		score += check(counts[0],counts[1],counts[2]);//�ж�ͼ���÷�
	}
	cout << score;
	return 0;
}