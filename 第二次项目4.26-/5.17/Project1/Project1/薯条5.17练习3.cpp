#include<iostream>

/*
    借鉴的题解
        我感觉有点繁杂，不搞了，看题解吧
    先根据规律将数据变成中间形态，期间要寻找临界点(细节在这里体现)
    中间形态是一维数组形式，然后再根据螺旋矩阵规律输出到另一个二维数组就可以了
*/
using namespace std;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };//定义方向数组
char a[505][505], b[250005], c[505][505];//b数组为链
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];  //读入
        }
    }
    int i = 1, j = 1, f = 1;//定义坐标和方向变量
    for (int k = 1; k <= n * n; k++) {
        b[k] = a[i][j];
        i -= f, j += f;//每回更新坐标
        if (j > n) j = n, i += 2, f = -f;//如果j大于n，i增加2，j变回n，更改方向
        else if (i > n) i = n, j += 2, f = -f;//如果i大于n，j增加2，i变回n，更改方向
        else if (i < 1) i = 1, f = -f;//如果i小于n，i变回1，更改方向
        else if (j < 1) j = 1, f = -f;//如果j小于1，j变回1，更改方向
        //注意顺序不能改
    }//蛇形矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = '@';//初始化
        }
    }
    c[1][n + 1] = '!';//方便判角
    c[n + 1][n] = '!';//方便判角
    c[0][n] = '!';//方便判角
    i = 1, j = 1, f = 0;//重置坐标
    for (int k = 1; k <= n * n; k++) {
        c[i][j] = b[k];//赋值
        if (c[i + dx[f]][j + dy[f]] == '!' || c[i + dx[f]][j + dy[f]] != '@') f = (f + 1) % 4;//更新方向数组的索引。
        i += dx[f], j += dy[f];//更新坐标
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << c[i][j];//输出
        }
        cout << '\n';
    }
    return 0;//华丽结束
}