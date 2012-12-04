#include <cstdio>
#define MAXN 102
using namespace std;
class BigNum {
	int len, data[MAXN];
	BigNum() {
		len = 1;
		data[0] = 0;
	}
	BigNum(int n) {
		len = 0;
		do {
			data[len++] = n % 10;
			n /= 10;
		}
		while(n > 0)
	}
};
