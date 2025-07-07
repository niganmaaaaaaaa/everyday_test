#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
    进制转换
        通过不断除以基数 R 取余数，直到商为0。余数倒序排列即为结果。
        余数范围 0~R-1，当余数 ≥10 时，转换为字母 A~Z（如10→A，35→Z）。
    处理边界情况
        输入为0时直接输出"0"。
    具体步骤
        循环取余，记录余数对应的字符。
        反转余数序列得到最终结果。
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