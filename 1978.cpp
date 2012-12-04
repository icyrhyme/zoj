#include <cstdio>
#define MAXN 3000
#define MAXL 33900
using namespace std;
int ans[MAXN], a[MAXL];
int main() {
	for(int i = 0; i < MAXL; ++i) {
		a[i] = i + 2;
	}
	int len = MAXL;
	for(int i = 0; i < MAXN; ++i) {
		int val = a[0], j;
		ans[i] = val;
		//printf("%d\n", val);
		for(j = 0; j < len; j += val) {
			a[j] = 0;
		}
		int olen = len;
		for(j = 0, len = 0; j < olen; ++j) {
			if(a[j] != 0)
				a[len++] = a[j];
		}
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		--n;
		printf("%d\n", ans[n]);
	}
	return 0;
}
