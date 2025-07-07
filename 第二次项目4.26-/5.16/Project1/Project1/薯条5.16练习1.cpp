#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

/*
    计算x->count1，y->count3和平局数count2
    如果x>y直接输出0
    如果x<=y
        先看有没有平局
            有平局
                平局数量能构满足x+count2>y
                    直接输出y-x+1
                不能满足
                    那么就先处理平局，count1+=count2;
                    然后就没有平局了
            没有平局
                如果x==y 那么只用平局一次，那么就胜利了,直接return 0;，不用+1超过,
                如果x!=y 那么就循环处理，两人分数差，从最小开始，sum+=分差+1，然后count1++,count3--，这就不用管奇数，偶数了
                    如果遇到x==y那就按照上面处理
*/
ll n, a, b, count1 = 0, count2 = 0, sum = 0, count3 = 0;
vector<ll> nums1, nums2;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums1.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b;
        ll c = nums1[i] - b;
        if (c < 0) {//讯风输
            nums2.push_back(c);
            count3++;
        }
        else if (c > 0) {//迅风赢
            count1++;
        }
        else {//平局
            count2++;
        }
    }
    if (count1 > count3) {
        cout << "0";
    }
    else if (count1 <= count3) {
        if (count2 != 0) {//有平局
            if (count3 - count1 + 1 <= count2) {
                //平局就能搞定
                cout << count3 - count1 + 1;
                return 0;
            }
        }
        if (count2 != -0) {//先把平局搞定
            count1 += count2;
            sum += count2;
        }
        sort(nums2.begin(), nums2.end());
        while (count1 <= count3) {
            ll size = nums2.size() - 1;//末位
            if (count1 == count3) {//最后一步
                sum += abs(nums2[size]);//对面少一子就能赢
                break;
            }
            sum += abs(nums2[size]) + 1;
            nums2.pop_back();
            count1++, count3--;
        }
        cout << sum;
    }

    return 0;
}