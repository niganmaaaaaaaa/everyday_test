#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
/*
    暴力搜索
    枚举所有可能的最终灯状态，满足按钮操作次数和亮灭约束。
    每个按钮按奇数次等效按1次，偶数次等效按0次，故只需枚举每个按钮按0或1次。
    总操作次数需满足：总按次数 ≤ c 且与 c 奇偶性相同（多余次数可通过无效操作补足）。
    枚举所有按钮按下的组合（共 2^4 = 16 种可能）。
    对每种组合生成灯状态，检查是否满足输入给出的亮灭约束。
    去重排序,用集合存储合法状态，最后排序输出。
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