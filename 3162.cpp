#include <iostream>
#define MAXN 50000000
using namespace std;
int bitcnt[32];
void init() {
	bitcnt[0] = 0;
	bitcnt[1] = 1;
	int sum = 1;
	for(int i = 2; (1 << i) < MAXN; ++i) {
		bitcnt[i] = sum + (1 << (i - 1));
		sum += bitcnt[i];
	}
}
int bitcount(int a) {
	if(a == 0)
		return 0;
	int ret = 0, i;
	for(i = 1; (1 << i) - 1 < a; ++i) {
		ret += bitcnt[i];
	}
	ret += (a - (1 << (i - 1)) + 1) + bitcount(a - (1 << (i - 1)));
	/*for(p = 1; p <= a; p <<= 1)
		;
	p >>= 1;
	return a + bitcount(a - p);*/
	return ret;
}
double prob(int a) {
	if(a == 0)
		return 0;
	int p, i;
	double ret = 0;
	for(i = 1; (1 << i) - 1 < a; ++i) {
		ret += 1.0 * bitcnt[i] / i;
	}
	ret += 1.0 * ((a - (1 << (i - 1)) + 1) + bitcount(a - (1 << (i - 1)))) / i;
	return ret;
}
double solve(int a, int b) {
	return (prob(b) - prob(a - 1)) / (b - a + 1);
}
int main() {
	init();
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%.6lf\n", solve(a, b));
	}
	return 0;
}
