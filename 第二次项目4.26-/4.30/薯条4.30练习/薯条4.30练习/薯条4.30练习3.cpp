#include <iostream>
#include <vector>
using namespace std;
/*
    check 函数用于检查在给定的最大值 max_sum 下，能否将数列分成不超过 m 段。
		它遍历数列，累加每段的和，若超过 max_sum 则开启新的一段。
	binary_search 函数：使用二分查找来确定每段和的最大值的最小值。左边界 left 初始化为数列中的最大值，右边界 right 初始化为数列的总和。
		在二分查找过程中，调用 check 函数判断中间值是否满足条件，根据结果更新左右边界。
*/

// 检查在给定的最大值下，能否将数列分成不超过 m 段
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

// 二分查找每段和的最大值的最小值
int binary_search(const vector<int>& a, int m) {
    int left = 0, right = 0;
    // 确定二分查找的左右边界
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