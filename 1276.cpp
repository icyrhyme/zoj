#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#define MAXN 16
#define INF 1000000000
#define FI first
#define SE second
using namespace std;
int rec[MAXN][MAXN];
int print(int le, int ri) {
	if(le == ri)  {
		printf("A%d", le + 1);
	}
	else {
		int k = rec[le][ri];
		putchar('(');
		print(le, k);
		printf(" x ");
		print(k + 1, ri);
		putchar(')');
	}
}
int main() {
	int n, csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		vector<pair<int, int> > vp(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &vp[i].FI, &vp[i].SE);
		}
		int dp[MAXN][MAXN];
		for(int i = 0; i < n; ++i)
			dp[i][i] = 0;
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j + i < n; ++j) {
				dp[j][j + i] = INF;
				for(int k = j; k < j + i; ++k) {
					int newval = dp[j][k] + dp[k + 1][j + i];
					newval += vp[j].FI * vp[k].SE * vp[j + i].SE;
					if(newval < dp[j][j + i]) {
						dp[j][j + i] = newval;
						rec[j][j + i] = k;
					}
				}
			}
		}
		printf("Case %d: ", csnum);
		csnum++;
		print(0, n - 1);
		putchar('\n');
	}
	return 0;
}
