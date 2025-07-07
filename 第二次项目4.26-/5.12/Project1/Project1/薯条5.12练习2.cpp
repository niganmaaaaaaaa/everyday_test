#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
    build_map �����������ַ�ӳ�������ĸӳ�䵽��Ӧ�����֡�
                    ʹ�� fill ������ char_map ���������Ԫ�س�ʼ��Ϊ 0��Ȼ��ֱ𽫶�Ӧ��ĸ��ֵΪ��Ӧ�����֡�

    n���洢����ĵ绰����������
    char_map[256]�����ڴ洢�ַ������ֵ�ӳ���ϵ��
    count   unordered_map<string, int> ���͵�����������ͳ��ÿ����׼��ʽ�绰����ĳ��ִ�����
        ���Ǳ�׼��ʽ�ĵ绰���룬ֵ�Ǹú�����ֵĴ�����
    ����绰����������ʹ�� cin >> n; ��ȡ����ĵ绰����������
    �����ַ�ӳ������� build_map(char_map); �����ַ������ֵ�ӳ���
    ����ÿ���绰���룺
    ʹ�� for ѭ������ÿ���绰���롣
    ����ÿ���绰���� s������һ���µ��ַ��� converted ���ڴ洢ת�����������ʽ��
    �����绰���� s �е�ÿ���ַ� c��
        ��� c �����ַ� -����������
        ��� c �����֣�ֱ�ӽ�����ӵ� converted �С�
        ��� c ����ĸ������ char_map ����ת��Ϊ��Ӧ�����ֲ���ӵ� converted �С�
    ��ת����ĵ绰�����ʽ��Ϊ��׼��ʽ��string standard = converted.substr(0, 3) + "-" + converted.substr(3, 4);����ǰ�����ַ��ͺ��ĸ��ַ������ַ����ӡ�
    ���� count �ж�Ӧ��׼��ʽ�绰����ĳ��ִ�����count[standard]++;��
    �ҳ��ظ��ĵ绰���벢�洢��

    ����һ�� vector<pair<string, int>> ���͵����� res�����ڴ洢�ظ��ĵ绰���뼰����ִ�����
    ���� count �е�ÿ����ֵ�� p��
    ��� p.second�����ִ��������ڵ��� 2���򽫸õ绰���뼰����ִ����� pair ����ʽ��ӵ� res �С�

    ��� res Ϊ�գ�˵��û���ظ��ĵ绰���룬��� No duplicates.��
    ��� res ��Ϊ�գ��ȶ� res ��������sort(res.begin(), res.end());����Ȼ����� res����Ҫ��ĸ�ʽ���ÿ���ظ��ĵ绰���뼰����ִ�����
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