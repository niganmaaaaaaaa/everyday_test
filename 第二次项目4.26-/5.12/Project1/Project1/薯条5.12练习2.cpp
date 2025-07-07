#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
    build_map 函数：构建字符映射表，将字母映射到对应的数字。
                    使用 fill 函数将 char_map 数组的所有元素初始化为 0，然后分别将对应字母赋值为相应的数字。

    n：存储输入的电话号码数量。
    char_map[256]：用于存储字符到数字的映射关系。
    count   unordered_map<string, int> 类型的容器，用于统计每个标准形式电话号码的出现次数。
        键是标准形式的电话号码，值是该号码出现的次数。
    输入电话号码数量：使用 cin >> n; 读取输入的电话号码数量。
    构建字符映射表：调用 build_map(char_map); 构建字符到数字的映射表。
    处理每个电话号码：
    使用 for 循环遍历每个电话号码。
    对于每个电话号码 s，创建一个新的字符串 converted 用于存储转换后的数字形式。
    遍历电话号码 s 中的每个字符 c：
        如果 c 是连字符 -，则跳过。
        如果 c 是数字，直接将其添加到 converted 中。
        如果 c 是字母，根据 char_map 将其转换为对应的数字并添加到 converted 中。
    将转换后的电话号码格式化为标准形式：string standard = converted.substr(0, 3) + "-" + converted.substr(3, 4);，即前三个字符和后四个字符用连字符连接。
    更新 count 中对应标准形式电话号码的出现次数：count[standard]++;。
    找出重复的电话号码并存储：

    创建一个 vector<pair<string, int>> 类型的容器 res，用于存储重复的电话号码及其出现次数。
    遍历 count 中的每个键值对 p：
    如果 p.second（出现次数）大于等于 2，则将该电话号码及其出现次数以 pair 的形式添加到 res 中。

    如果 res 为空，说明没有重复的电话号码，输出 No duplicates.。
    如果 res 不为空，先对 res 进行排序（sort(res.begin(), res.end());），然后遍历 res，按要求的格式输出每个重复的电话号码及其出现次数。
*/

void build_map(int char_map[]) {
    fill(char_map, char_map + 256, 0);
    char_map['A'] = char_map['B'] = char_map['C'] = '2';
    char_map['D'] = char_map['E'] = char_map['F'] = '3';
    char_map['G'] = char_map['H'] = char_map['I'] = '4';
    char_map['J'] = char_map['K'] = char_map['L'] = '5';
    char_map['M'] = char_map['N'] = char_map['O'] = '6';
    char_map['P'] = char_map['R'] = char_map['S'] = '7';
    char_map['T'] = char_map['U'] = char_map['V'] = '8';
    char_map['W'] = char_map['X'] = char_map['Y'] = '9';
}

int main() {
    int n;
    cin >> n;
    int char_map[256];
    build_map(char_map);
    unordered_map<string, int> count;

    for (int i = 0; i < n; ++i) {
        string s, converted;
        cin >> s;
        for (char c : s) {
            if (c == '-') continue;
            if (isdigit(c)) {
                converted.push_back(c);
            }
            else {
                converted.push_back(char_map[c]);
            }
        }
        string standard = converted.substr(0, 3) + "-" + converted.substr(3, 4);
        count[standard]++;
    }

    vector<pair<string, int>> res;
    for (auto& p : count) {
        if (p.second >= 2) {
            res.emplace_back(p.first, p.second);
        }
    }

    if (res.empty()) {
        cout << "No duplicates." << endl;
    }
    else {
        sort(res.begin(), res.end());
        for (auto& p : res) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}