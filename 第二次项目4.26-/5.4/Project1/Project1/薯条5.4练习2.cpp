#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
    �ֽ����֣������ַֽ�Ϊǧλ����λ��ʮλ�͸�λ��
    ����������Ӣ�ı��ֱ���ǧλ����λ��ʮλ�͸�λ��Ӣ�ĵ��ʡ�
    ����������ϣ��ر���ʮλ�͸�λ����ϣ���11-19�������
    �����жϣ�������ĿҪ�����ʵ���λ����ӡ�and����
*/
string numberToWords(int num) {
    if (num == 0) return "zero";

    vector<string> parts;
    string ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    int q = num / 1000;
    int h = (num / 100) % 10;
    int t = (num / 10) % 10;
    int o = num % 10;
    int s = t * 10 + o;

    // ����ǧλ
    if (q > 0) {
        parts.push_back(ones[q] + " thousand");
    }

    // �����λ
    if (h > 0) {
        parts.push_back(ones[h] + " hundred");
    }

    // �ж��Ƿ���Ҫ��and
    bool need_and = false;
    if ((h > 0 && s > 0 && s <= 10) || (h == 0 && q > 0 && s > 0)) {
        parts.push_back("and");
    }

    // ����ʮλ�͸�λ
    string ten_str;
    if (s != 0) {
        if (t == 0) {
            ten_str = ones[o];
        }
        else if (t == 1) {
            ten_str = teens[o];
        }
        else {
            ten_str = tens[t];
            if (o != 0) {
                ten_str += " " + ones[o];
            }
        }
        parts.push_back(ten_str);
    }

    // �ϲ�������
    string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) {
            result += " ";
        }
        result += parts[i];
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << numberToWords(n) << endl;
    return 0;
}