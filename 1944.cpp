#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXL 32
using namespace std;
char ps[MAXL], is[MAXL];
void dfs(int pi, int pj, int ii, int ij) {
	int i;
	for(i = ii; i <= ij; ++i)
		if(is[i] == ps[pi])
			break;
	if(i - 1 >= ii)
		dfs(pi + 1, pi + i - ii, ii, i - 1);
	if(ij >= i + 1)
		dfs(pi + i - ii + 1, pj, i + 1, ij);
	putchar(is[i]);
}
int main() {
	while(scanf("%s%s", ps, is) != EOF) {
		int len = strlen(ps);
		dfs(0, len - 1, 0, len - 1);
		putchar('\n');
	}
	return 0;
}
