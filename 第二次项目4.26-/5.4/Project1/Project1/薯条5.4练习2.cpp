#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
    分解数字：将数字分解为千位、百位、十位和个位。
    构建各部分英文表达：分别处理千位、百位、十位和个位的英文单词。
    处理特殊组合：特别是十位和个位的组合，如11-19的特殊表达。
    条件判断：根据题目要求，在适当的位置添加“and”。
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

    // 处理千位
    if (q > 0) {
        parts.push_back(ones[q] + " thousand");
    }

    // 处理百位
    if (h > 0) {
        parts.push_back(ones[h] + " hundred");
    }

    // 判断是否需要加and
    bool need_and = false;
    if ((h > 0 && s > 0 && s <= 10) || (h == 0 && q > 0 && s > 0)) {
        parts.push_back("and");
    }

    // 处理十位和个位
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

    // 合并各部分
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