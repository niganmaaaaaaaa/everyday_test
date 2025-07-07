#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
/*
     ��ʱ�����������Ż���
     ����ת����������ת��Ϊ�������⣬����ÿ���ַ����ļ�ֵ�� 'c' ��������������'s' �� 'c' �������
    ��̬�滮��ʹ�ö�̬�滮ά��ÿ�����ܵ��������Ӧ������ֵ�͡�
    ״̬ת�ƣ�����ÿ���ַ������������п��ܵ��������Ӧ������ֵ�͡�
     
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (char c : s) {
            if (c == 's') a++;
            else if (c == 'c') b++;
        }
        int d = a - b;
        int val = b;
        unordered_map<int, int> tmp(dp);
        for (const auto& p : dp) {
            int new_d = p.first + d;
            int new_val = p.second + val;
            if (tmp.find(new_d) == tmp.end() || new_val > tmp[new_d]) {
                tmp[new_d] = new_val;
            }
        }
        dp = tmp;
    }
    cout << (dp.count(0) ? dp[0] : 0) << endl;
    return 0;
}