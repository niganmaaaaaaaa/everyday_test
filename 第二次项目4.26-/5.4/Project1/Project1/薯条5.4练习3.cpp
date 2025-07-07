﻿#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;
/*
*	抄的题解 ，这题主要字符转换，细节太多了
	这题不会很难,但细节极其多
	首先在输入上就有坑。输入的字符串可能会有空格，不能直接用 scanf 或者 cin。
	然后是输出。当有特殊情况特判掉的时候，要再补上换行，不然会出现奇怪的 WA 错误。
	在判断质数与分解质因数时，可以加上优化。因为分解质因数只需要模质数，而除了 2 与 3 之外模 6 都是 1 或 5 
		所以先特判 2 与 3 之后每 6 个数去尝试分解就可以了。这样的优化能把常数变成原来的  3，1​
  ，能跑得快一点。
*/

char str[1001];//输入的字符
int n;//那个数 
void str2lld() {//转换成数字 
	long long ret = 0;
	bool flg = false;//一开始没有数字 
	for (int i = 1; str[i] && ret <= 40000000; ++i)
		if ('0' <= str[i] && str[i] <= '9') {//这一位是数字 
			ret = ret * 10 + str[i] - '0';
			flg = true;//标记有数字 
		}
	if (!flg)n = 0x7fffffff;//没有数字 
	else n = ret;
}
void trial() {//试除法
	if (n < 2) {
		puts("No!\n");//小于2 
		return;
	}
	do {
		if (n == 2 || n == 3) {//2或3 
			puts("Yes!\n");
			return;
		}
		if (!(n & 1)) {//2的倍数 
			puts("No!");
			break;
		}
		if (!(n % 3)) {//3的倍数 
			puts("No!");
			break;
		}
		bool flag = true;
		for (int i = 5; i * i <= n; i += 6) {
			if (n % i == 0) {
				puts("No!");
				flag = false;
				break;
			}
			if (n % (i + 2) == 0) {
				puts("No!");
				flag = false;
				break;
			}
		}
		if (flag) {
			puts("Yes!\n");
			return;
		}
	} while (0);
	if (n > 40000000) {
		puts("The number is too large!\n");
		return;
	}
	int m = n;
	map<int, int> mp;//有多少质数
	while (!(n & 1)) {//是偶数
		n >>= 1;//除以2 
		if (mp.count(2))++mp[2];
		else mp[2] = 1;
	}
	while (!(n % 3)) {//是3的倍数 
		n /= 3;//除以3
		if (mp.count(3))++mp[3];
		else mp[3] = 1;
	}
	for (int i = 5; i * i <= n; i += 6) {//其他的都%6余1或5 
		while (!(n % i)) {
			n /= i;//试除i(mod 6=5)
			if (mp.count(i))++mp[i];
			else mp[i] = 1;
		}
		while (!(n % (i + 2))) {
			n /= i + 2;//试除i+2(mod 6=1)
			if (mp.count(i + 2))++mp[i + 2];
			else mp[i + 2] = 1;
		}
	}
	if (n > 1)++mp[n];
	printf("%d=", m);
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)//遍历质因数 
		if (it == mp.begin())printf("%d^%d", it->first, it->second);
		else printf("*%d^%d", it->first, it->second);
	printf("\n\n");
}
int main() {
	string s;
	while (1) {
		printf("Enter the number=\n");
		getline(cin, s);//读入一整行 
		strcpy(str + 1, s.c_str());
		str2lld();//转换数字 
		if (n == 0x7fffffff)return 0;//没有数字直接退出 
		printf("Prime? ");
		trial();
	}
}