#include <stdio.h>
#include <string.h>
#define MAXN 64
long long calc(int permu[], int n, int c) {
	long long ret = 1;
	int i, j, vis[MAXN];
	memset(vis, 0, sizeof(int) * n);
	for(i = 0; i < n; ++i) {
		if(!vis[i]) {
			for(j = i; !vis[j]; j = permu[j]) {
				vis[j] = 1;
			}
			ret *= c;
		}
	}
	return ret;
}
int main() {
	int c, n;
	int permu[MAXN];
	while(scanf("%d%d", &c, &n) != EOF) {
		if(c == 0 && n == 0)
			break;
		long long res = 0;
		int i, j;
		for(i = 0; i < n; ++i) {
			for(j = 0; j < n; ++j)
				permu[j] = (i + j) % n;
			res += calc(permu, n, c);
			for(j = 0; j < n; ++j)
				permu[n - 1 - j] = (i + j) % n;
			res += calc(permu, n, c);
		}
		res /= 2 * n;
		printf("%lld\n", res);
	}
	return 0;
}
