#include <cstdio>
#include <algorithm>
#define MAXNUM ((1<<20)+1)
#define MAXN 128
using namespace std;
int bcnt[MAXNUM];
int main() {
	bcnt[0] = 0;
	for(int i = 1; i < MAXNUM; ++i) {
		bcnt[i] = bcnt[i >> 1] + (i & 1);
	}
	int cas, a[MAXN], b[MAXN];
	scanf("%d", &cas);
	while(cas--) {
		int n, m;
		scanf("%d%d", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		sort(a, a + m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		for(int i = 0; i < n; ++i) {
			int idx = 0;
			for(int j = 1; j < m; ++j) 
				if(bcnt[a[j] ^ b[i]] < bcnt[a[idx] ^ b[i]]) {
					idx = j;
				}
			printf("%d\n", a[idx]);
		}
	}
	return 0;
}
