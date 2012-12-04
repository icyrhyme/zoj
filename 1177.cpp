#include <iostream>
#include <cstdio>
#define INF 1000000000
#define MAXL 100000
using namespace std;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, a[MAXL], res[MAXL];
		scanf("%d", &n);
		int len = INF;
		for(int i = 1; i < 10; ++i) {
			a[0] = i;
			int carry = 0, j;
			for(j = 1; ; ++j) {
				carry += a[j - 1] * n;
				a[j] = carry % 10;
				carry /= 10;
				if(a[j] == a[0] && carry == 0)
					break;
			}
			//for(; j > 0; --j)
			//	printf("%d", a[j]);
			//putchar('\n');
			if(j < len) {
				len = j;
				for(; j > 0; --j)
					res[j] = a[j];
			}
		}
		for(int i = len; i > 0; --i)
			printf("%d", res[i]);
		putchar('\n');
		if(cs != 0)
			putchar('\n');
	}
	return 0;
}
