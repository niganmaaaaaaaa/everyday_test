#include<iostream>
#include<string.h>

using namespace std;

long long  sum[1005];

int main() {
	long long k,count=0,max=-1;
	string s;
	cin >> k >> s;
	if (s.length() % k!=0||s.length()<k) {
		cout << "-1"; 
	}else {
		memset(sum, 0, sizeof(int) * 255);
		long long count1 = s.length() / k;
		for (long long  i = 0; i < count1; ++i) {
			for (long long j = i; j < s.length(); j += count1) {
				sum[s[j]]++;
				if (sum[s[j]] > max) {
					max = sum[s[j]];
				}
			}
			count += k - max;
			max = 0;
			memset(sum, 0, sizeof(long long ) * 255);
		}
		cout << count << endl;
	}
	return 0;
}