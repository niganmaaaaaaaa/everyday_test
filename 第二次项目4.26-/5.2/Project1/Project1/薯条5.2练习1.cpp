#include<iostream>
#include<vector>

using namespace std;

/*
    ˼·
    ����ֱ�ӽ�1��ͷ�Ĳ������ȶ����ݽ��д���һ��
    Ҳ�����ҵ������2��ͷ�Ĳ�����Ȼ�����1��ͷ�Ĳ�����Ȼ������������λ�������в���
        �ڶ������������Ż�������1��ͷ�Ĳ�����ĵڶ�������ʹ��Ͱװ�أ�������Լ����ֵ��Ҫ�ӵ����ܺ�
        Ȼ������2��ͷ�Ĳ������jλ������ֱ��O��1���ҵ�Ҫ�����ӵ����Ϳ�����
    ���������������ǽ�����У�����Ҫ��������������ѡ����ʵġ�     

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
            if (n / b <= 1000) {//Ѱ�Һ��ʵ���ֵ
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