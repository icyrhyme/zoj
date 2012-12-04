#include <iostream>
#include <cstdio>
#define MAXN 10
#define MAXM (1<<10)
using namespace std;
int main() {
	int n, cs = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		int permu[MAXN];
		char tmp[MAXN];
		char tab[MAXM];
		for(int i = 0; i < n; ++i) {
			scanf("%s", tmp);
			permu[i] = tmp[1] - '1';
		}
		scanf("%s", tab);
		int t;
		scanf("%d", &t);
		char val[MAXN], newval[MAXN];
		printf("S-Tree #%d:\n", cs);
		for(int i = 0; i < t; ++i) {
			scanf("%s", val);
			for(int j = 0; j < n; ++j)
				newval[j] = val[permu[j]];
			int num = 0;
			for(int j = 0; j < n; ++j) {
				num <<= 1;
				num |= newval[j] - '0';
			}
			//printf("num=%d\n", num);
			putchar(tab[num]);
		}
		putchar('\n');
		putchar('\n');
		++cs;
	}
}
