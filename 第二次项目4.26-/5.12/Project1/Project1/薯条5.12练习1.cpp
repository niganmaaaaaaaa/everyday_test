
# include<iostream>
# include<cstdio>
# include<cstring>
using namespace std;
/*
*   ������˼·��
        �ö�ά����
        i�������ڼ���
        j����������
        ���� f[i][j]=f[i-1][j-1]+s[i]
        ������
        f[i][j]=f[i-1][j]
        �����Ĵ�����t�ı���ʱ
        ������
        f[i][j]=f[i-1][j]-s[i]
        ���� f[i-1][j-1]+s[i]+b[i])
        ȡ���ֵ
        ��ʼ��
        f[i][0]=f[i-1][0]-s[i]
        ��һֱ����
        ���f[n]i�����ֵ
*/

int n, t;
int s[5001], b[5001];
int f[5001][5001];
int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        f[i][0] = f[i - 1][0] - s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j] - s[i], f[i - 1][j - 1] + s[i]);
            if (j % t == 0) f[i][j] = max(f[i - 1][j] - s[i], f[i - 1][j - 1] + s[i] + b[i]);
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}
