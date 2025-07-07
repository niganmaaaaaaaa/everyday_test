#include <iostream>
#include <vector>
using namespace std;
/*
    check �������ڼ���ڸ��������ֵ max_sum �£��ܷ����зֳɲ����� m �Ρ�
		���������У��ۼ�ÿ�εĺͣ������� max_sum �����µ�һ�Ρ�
	binary_search ������ʹ�ö��ֲ�����ȷ��ÿ�κ͵����ֵ����Сֵ����߽� left ��ʼ��Ϊ�����е����ֵ���ұ߽� right ��ʼ��Ϊ���е��ܺ͡�
		�ڶ��ֲ��ҹ����У����� check �����ж��м�ֵ�Ƿ��������������ݽ���������ұ߽硣
*/

// ����ڸ��������ֵ�£��ܷ����зֳɲ����� m ��
bool check(const vector<int>& a, int m, int max_sum) {
    int sum = 0;
    int segments = 1;
    for (int num : a) {
        if (sum + num > max_sum) {
            segments++;
            sum = num;
        }
        else {
            sum += num;
        }
    }
    return segments <= m;
}

// ���ֲ���ÿ�κ͵����ֵ����Сֵ
int binary_search(const vector<int>& a, int m) {
    int left = 0, right = 0;
    // ȷ�����ֲ��ҵ����ұ߽�
    for (int num : a) {
        left = max(left, num);
        right += num;
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(a, m, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = binary_search(a, m);
    cout << result << endl;
    return 0;
}