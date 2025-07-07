#include<iostream>
#include<vector>

using namespace std;

/*
    思路
    可以直接将1开头的操作，先对数据进行处理一遍
    也可以找到输入的2开头的操作，然后遍历1开头的操作，然后对输入的索引位置数进行操作
        第二个操作可以优化，根据1开头的操作里的第二个数，使用桶装载，索引是约数，值是要加的数总和
        然后遇到2开头的操作里的j位置索引直接O（1）找到要操作加的数就可以了
    这两个操作可以是交替进行，根据要操作的数据数量选择合适的。     

*/

int n, m;
vector<long> nums(1, 0);
vector<pair<pair<int,int>,int>> caozuo;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int  a, b, c=10000000;
    while (m--) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c;
            if (n / b <= 1000) {//寻找合适的阈值
                int index = b;
                while (index <= n) {
                    nums[index] += c;
                    index += b;
                }
            }
            else {
                caozuo.push_back(make_pair(make_pair(a, b), c));
            }
        }
        else {
            long long scapegoat = nums[b];
            if(caozuo.size())
            for (int i = 0; i < caozuo.size(); ++i) {
                if(b%caozuo[i].first.second==0)
                scapegoat += caozuo[i].second;
            }
            cout << scapegoat << endl;
        }
    }
    return 0;
}