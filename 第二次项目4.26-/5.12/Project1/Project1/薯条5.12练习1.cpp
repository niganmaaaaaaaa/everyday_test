
# include<iostream>
# include<cstdio>
# include<cstring>
using namespace std;
/*
*   搞得题解思路：
        用二维数组
        i存跳到第几步
        j存跳到次数
        若跳 f[i][j]=f[i-1][j-1]+s[i]
        若不跳
        f[i][j]=f[i-1][j]
        当跳的次数是t的倍数时
        若不跳
        f[i][j]=f[i-1][j]-s[i]
        若跳 f[i-1][j-1]+s[i]+b[i])
        取最大值
        初始化
        f[i][0]=f[i-1][0]-s[i]
        即一直不跳
        输出f[n]i中最大值
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
