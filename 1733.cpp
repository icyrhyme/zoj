#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int main() {
	char s[MAXN], t[MAXN];
	while(scanf("%s%s", s, t) != EOF) {
		int dp[MAXN][MAXN];
		int slen = strlen(s);
		int tlen = strlen(t);
		for(int i = 0; i <= slen; ++i)
			for(int j = 0; j <= tlen; ++j) {
				dp[i][j] = 0;
			}
		for(int i = 1; i <= slen; ++i)
			for(int j = 1; j <= tlen; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if(s[i - 1] == t[j - 1])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		printf("%d\n", dp[slen][tlen]);
	}
	return 0;
}
