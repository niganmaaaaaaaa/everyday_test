#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
/*
    ��������
    ö�����п��ܵ����յ�״̬�����㰴ť��������������Լ����
    ÿ����ť�������ε�Ч��1�Σ�ż���ε�Ч��0�Σ���ֻ��ö��ÿ����ť��0��1�Ρ�
    �ܲ������������㣺�ܰ����� �� c ���� c ��ż����ͬ�����������ͨ����Ч�������㣩��
    ö�����а�ť���µ���ϣ��� 2^4 = 16 �ֿ��ܣ���
    ��ÿ��������ɵ�״̬������Ƿ������������������Լ����
    ȥ������,�ü��ϴ洢�Ϸ�״̬��������������
*/
int main() {
    int n, c;
    cin >> n >> c;

    vector<int> lights_on;
    int x;
    while (cin >> x && x != -1) {
        lights_on.push_back(x);
    }

    vector<int> lights_off;
    while (cin >> x && x != -1) {
        lights_off.push_back(x);
    }

    vector<int> mask1(n, 1);

    vector<int> mask2(n, 0);
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 1) {
            mask2[i] = 1;
        }
    }

    vector<int> mask3(n, 0);
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 0) {
            mask3[i] = 1;
        }
    }

    vector<int> mask4(n, 0);
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 3 == 1) {
            mask4[i] = 1;
        }
    }

    set<string> possible_states;

    for (int a1 = 0; a1 <= 1; ++a1) {
        for (int a2 = 0; a2 <= 1; ++a2) {
            for (int a3 = 0; a3 <= 1; ++a3) {
                for (int a4 = 0; a4 <= 1; ++a4) {
                    int k = a1 + a2 + a3 + a4;
                    if (k > c || (c - k) % 2 != 0) {
                        continue;
                    }

                    vector<int> total_mask(n, 0);
                    if (a1) {
                        for (int i = 0; i < n; ++i) {
                            total_mask[i] ^= mask1[i];
                        }
                    }
                    if (a2) {
                        for (int i = 0; i < n; ++i) {
                            total_mask[i] ^= mask2[i];
                        }
                    }
                    if (a3) {
                        for (int i = 0; i < n; ++i) {
                            total_mask[i] ^= mask3[i];
                        }
                    }
                    if (a4) {
                        for (int i = 0; i < n; ++i) {
                            total_mask[i] ^= mask4[i];
                        }
                    }

                    vector<int> state(n);
                    for (int i = 0; i < n; ++i) {
                        state[i] = 1 ^ total_mask[i];
                    }

                    bool valid = true;
                    for (int x : lights_on) {
                        if (state[x - 1] != 1) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    for (int x : lights_off) {
                        if (state[x - 1] != 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    string s;
                    for (int bit : state) {
                        s += (bit ? '1' : '0');
                    }
                    possible_states.insert(s);
                }
            }
        }
    }

    if (possible_states.empty()) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        vector<string> sorted(possible_states.begin(), possible_states.end());
        sort(sorted.begin(), sorted.end());
        for (const string& s : sorted) {
            cout << s << endl;
        }
    }

    return 0;
}