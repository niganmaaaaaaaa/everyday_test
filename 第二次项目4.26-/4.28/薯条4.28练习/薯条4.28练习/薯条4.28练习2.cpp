#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

/*
		���������ֱ�Ӱ��������������ݶ����������ԣ���i������������λ�ã��ֱ���2*i+1,2*i+2
			��ɫ��ֵ1����ɫ��ֵ-1
		�������󣬸���n,k�������������㷽�����Ǽ���ò�֮ǰ�����н������Ȼ�����k
			Ȼ��������ֱ���ҵ����������ж���1����-1�����RED����BLACK
		�����׸�m��ѭ���Ϳ�����
		����̫�������ܲ���������������RE
*/

long long m, n, k,Max=-1;//m,n,k,Max���������
vector<long long > nums;


int main() {
	cin >> m;//�����
	for (int i = 0; i < m; ++i) {
		cin >> n >> k;//�У��ڼ���
		long long  a = 1,count1=n-1,count2=0;
		while (count1) {
			a *= 2;
			count2 += a/2;
			count1--;
		}
		Max = max(count2+k, Max);
		nums.push_back(count2+k);
	}
	vector<long long >numss(99999);//����
	numss[0]=1;
	for (int i = 0; i < Max; ++i) {
		numss[2 * i + 1] = numss[i];
		numss[2 * i + 2] = -numss[i];
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (numss[nums[i]-1] == 1) {
			cout << "RED" << endl;
		}
		else {
			cout << "BLACK" << endl;
		}
	}
	return 0;
}