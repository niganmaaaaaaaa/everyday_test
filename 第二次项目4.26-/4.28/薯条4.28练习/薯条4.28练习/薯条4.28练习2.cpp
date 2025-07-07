#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

/*
		暴力解决，直接把树画出来，根据二叉树的特性，第i棵树左右子树位置，分别是2*i+1,2*i+2
			红色赋值1，黑色赋值-1
		画出来后，根据n,k计算索引，计算方法就是计算该层之前的所有结点数，然后加上k
			然后按照索引直接找到数组数，判断是1还是-1，输出RED还是BLACK
		上面套个m层循环就可以了
		对于太大数不能操作，所以有两个RE
*/

long long m, n, k,Max=-1;//m,n,k,Max方便操作，
vector<long long > nums;


int main() {
	cin >> m;//结点数
	for (int i = 0; i < m; ++i) {
		cin >> n >> k;//行，第几个
		long long  a = 1,count1=n-1,count2=0;
		while (count1) {
			a *= 2;
			count2 += a/2;
			count1--;
		}
		Max = max(count2+k, Max);
		nums.push_back(count2+k);
	}
	vector<long long >numss(99999);//画树
	numss[0]=1;
	for (int i = 0; i < Max; ++i) {
		numss[2 * i + 1] = numss[i];
		numss[2 * i + 2] = -numss[i];
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (numss[nums[i]-1] == 1) {
			cout << "RED" << endl;
		}
		else {
			cout << "BLACK" << endl;
		}
	}
	return 0;
}