#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

/*
    ����x->count1��y->count3��ƽ����count2
    ���x>yֱ�����0
    ���x<=y
        �ȿ���û��ƽ��
            ��ƽ��
                ƽ�������ܹ�����x+count2>y
                    ֱ�����y-x+1
                ��������
                    ��ô���ȴ���ƽ�֣�count1+=count2;
                    Ȼ���û��ƽ����
            û��ƽ��
                ���x==y ��ôֻ��ƽ��һ�Σ���ô��ʤ����,ֱ��return 0;������+1����,
                ���x!=y ��ô��ѭ���������˷��������С��ʼ��sum+=�ֲ�+1��Ȼ��count1++,count3--����Ͳ��ù�������ż����
                    �������x==y�ǾͰ������洦��
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
        if (c < 0) {//Ѷ����
            nums2.push_back(c);
            count3++;
        }
        else if (c > 0) {//Ѹ��Ӯ
            count1++;
        }
        else {//ƽ��
            count2++;
        }
    }
    if (count1 > count3) {
        cout << "0";
    }
    else if (count1 <= count3) {
        if (count2 != 0) {//��ƽ��
            if (count3 - count1 + 1 <= count2) {
                //ƽ�־��ܸ㶨
                cout << count3 - count1 + 1;
                return 0;
            }
        }
        if (count2 != -0) {//�Ȱ�ƽ�ָ㶨
            count1 += count2;
            sum += count2;
        }
        sort(nums2.begin(), nums2.end());
        while (count1 <= count3) {
            ll size = nums2.size() - 1;//ĩλ
            if (count1 == count3) {//���һ��
                sum += abs(nums2[size]);//������һ�Ӿ���Ӯ
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