/*
****************************
This is the example you  are
actually        considering.
****************************
This  is  the  example   you
are  actually   considering.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10001
#define MAXL 81
#define INF 1000000000
using namespace std;
char words[MAXN][MAXL];
int a[MAXN], dp[MAXN], pre[MAXN];
void update(int idx, int preidx, int cost) {
	if(dp[preidx] + cost <= dp[idx]) {
		//printf("update dp[%d] from dp[%d] with value %d.\n", idx, preidx, dp[preidx] + cost);
		dp[idx] = dp[preidx] + cost;
		pre[idx] = preidx;
	}
}
int main() {
	int w;
	char tmp[MAXL];
	while(scanf("%d", &w) != EOF) {
		if(w == 0)
			break;
		getchar();
		int sz;
		for(sz = 0; ; ++sz) {
			scanf("%[^ \n]", words[sz]);
			//puts(words[sz]);
			a[sz] = strlen(words[sz]);
			scanf("%[ \n]", tmp);
			int len = strlen(tmp);
			if(strstr(tmp, "\n\n") != NULL)
				break;
		}
		++sz;
		dp[sz] = 0;
		pre[sz] = -1;
		for(int i = sz - 1; i >= 0; --i) {
			dp[i] = INF;
			int sum = 0, cost, rem, quo;
			for(int j = i + 1, k = 0; j <= sz; ++j, ++k) {
				sum += a[j - 1];
				if(sum > w)
					break;
				if(k == 0) {
					if(sum < w)
						update(i, j, 500);
					else
						update(i, j, 0);
				}
				else {
					rem = (w - sum) % k;
					quo = (w - sum) / k;
					cost = (k - rem) * quo * quo + rem * (quo + 1) * (quo + 1);
					update(i, j, cost);
				}
				sum += 1;
			}
		}
		for(int i = 0; i != sz; i = pre[i]) {
			int wcnt = pre[i] - i;
			int sum = 0;
			for(int j = i; j < pre[i]; ++j) {
				sum += a[j];
			}
			if(wcnt == 1) {
				printf("%s\n", words[i]);
				continue;
			}
			int quo = (w - sum) / (wcnt - 1);
			int rem = (w - sum) % (wcnt - 1);
			for(int j = i, k = 0; j < pre[i]; ++j, ++k) {
				printf("%s", words[j]);
				int sp = 0;
				if(k < wcnt - 1 - rem) {
					sp = quo;
				}
				else if(k < wcnt - 1) {
					sp = quo + 1;
				}
				while(sp--)
					putchar(' ');
			}
			putchar('\n');
		}
		printf("\n");
		//printf("%d\n", dp[sz]);
	}
	return 0;
}
