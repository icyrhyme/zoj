#include <iostream>
#define INF 1000000000
#define MAXN 1500
#define CUR(i) ((i)&1)
#define PRE(i) (((i)+1)&1)
using namespace std;
int main() {
	int i, j, k, a[2][MAXN];
	a[1][1] = 0;
	for(i = 2; i < MAXN; ++i)
		a[1][i] = INF;
	bool changed;
	i = 0;
	do {
		changed = false;
		for(int j = 0; j < MAXN; ++j)
			a[CUR(i)][j] = a[PRE(i)][j];
		for(int j = 1; j < MAXN; ++j) {
			if(j + 1 < MAXN && a[PRE(i)][j] + 1 < a[CUR(i)][j + 1]) {
				a[CUR(i)][j + 1] = a[PRE(i)][j] + 1;
				changed = true;
			}
			if(j - 1 >= 1 && a[PRE(i)][j] + 1 < a[CUR(i)][j - 1]) {
				a[CUR(i)][j - 1] = a[PRE(i)][j] + 1;
				changed = true;
			}
			if((j << 1) < MAXN && a[PRE(i)][j] + 1 < a[CUR(i)][j << 1]) {
				a[CUR(i)][j << 1] = a[PRE(i)][j] + 1;
				changed = true;
			}
		}
		++i;
	}
	while(changed);
	int N;
	while(scanf("%d", &N) != EOF) {
		if(N == 0)
			break;
		printf("%d\n", a[1][N]);
	}	
	return 0;
}
