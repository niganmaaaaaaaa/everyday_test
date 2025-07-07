#include <iostream>
#include <vector>
using namespace std;
/*
    ��̬�滮,01��������
        ������ V ��������װ����Ʒ��ʹ��������ʣ��ռ伴Ϊ V - ��������
        ״̬dp[j] ��ʾ����Ϊ j ʱ��װ�����������
        ״̬ת�Ʒ���˼·��
            ��������������� V ����Ʒ��� v����ȷ��ÿ����Ʒֻ��ѡȡһ�Ρ�
            dp[j] = max(dp[j], dp[j - v] + v)��
        ���� dp[V] Ϊ���װ�������ʣ��ռ�Ϊ V - dp[V]��
*/
int main() {
    int V, n;
    cin >> V >> n;
    vector<int> volumes(n);
    for (int i = 0; i < n; ++i) {
        cin >> volumes[i];
    }

    vector<int> dp(V + 1, 0); // ��ʼ��dp���飬��ʾ����Ϊjʱ�����װ�����

    for (int v : volumes) {
        // ���������ֹ�ظ�ѡȡ
        for (int j = V; j >= v; --j) {
            // ���µ�ǰ�����µ�������
            if (dp[j - v] + v > dp[j]) {
                dp[j] = dp[j - v] + v;
            }
        }
    }

    cout << V - dp[V] << endl; // ʣ��ռ� = ������ - ���װ�����
    return 0;
}