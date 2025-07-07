#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long N, K, q, x, y, count1 = 0, q1 = 5, a[3][50001];

int main() {
    cin >> N >> K;
    memset(a, -1, sizeof(long long) * 50001 * 3);
    for (int i = 0; i < N; ++i) {
        cin >> q >> x >> y;
        if (x > N || y > N || (q == 1 && x == y)) {//后两种情况
            count1++;
        }

        if (a[x][0] == -1 && a[y][0] == -1) {//未标识种类,两个都没有
            a[x][0] = q1, a[y][0] = q1++;
        }
        else if (a[x][0] > 4 || a[y][0] > 4) {//其中一个有种类另一个没有，有一个
            long long* c = (a[x][0] > a[y][0]) ? &a[x][0] : &a[x][0];
            *c = a[y][0];
        }else if()
    }

}


return 0;
}