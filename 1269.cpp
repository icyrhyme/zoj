#include <iostream>
#include <cstdio>
using namespace std;
int gao(int n) {
	int ret = -1;
	for(int i = 2; i <= n; ++i) {
		int num = n, cnt = 0;
		while(num % i == 1) {
			num -= 1;
			num = num / i * (i - 1);
			++cnt;
		}
		if(cnt == i && num % i == 0)
			ret = max(ret, i);
	}
	return ret;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n < 0)
			break;
		int ans = gao(n);
		if(ans == -1)
			printf("%d coconuts, no solution\n", n);
		else
			printf("%d coconuts, %d people and 1 monkey\n", n, ans);
	}
	return 0;
}
