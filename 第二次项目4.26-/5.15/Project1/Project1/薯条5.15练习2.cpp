#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
    ����ת��
        ͨ�����ϳ��Ի��� R ȡ������ֱ����Ϊ0�������������м�Ϊ�����
        ������Χ 0~R-1�������� ��10 ʱ��ת��Ϊ��ĸ A~Z����10��A��35��Z����
    ����߽����
        ����Ϊ0ʱֱ�����"0"��
    ���岽��
        ѭ��ȡ�࣬��¼������Ӧ���ַ���
        ��ת�������еõ����ս����
*/
int main() {
    int N, R;
    cin >> N >> R;
    string ans;
    if (N == 0) {
        ans = "0";
    }
    else {
        while (N > 0) {
            int rem = N % R;
            char c;
            if (rem < 10) {
                c = '0' + rem;
            }
            else {
                c = 'A' + (rem - 10);
            }
            ans.push_back(c);
            N /= R;
        }
        reverse(ans.begin(), ans.end());
    }
    cout << ans << endl;
    return 0;
}