#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 128
#define MAXV 23
using namespace std;
int dp[MAXN][MAXV][MAXV][MAXV];
int getValue(char c) {
	if(c == 'A')
		return 1;
	else if(isdigit(c))
		return (c - '0');
	else 
		return 10;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		char cards[MAXN];
		for(int i = 0; i < n; ++i) {
			char tmp[2];
			scanf("%s", tmp);
			cards[i] = tmp[0];
		}
		memset(dp, -1, sizeof(dp[0]) * (n + 1));
		dp[0][0][0][0] = 0;
		bool flag;
		int res = -1;
		for(int i = 0; i < n; ++i) {
			flag = false;
			for(int a = 0; a <= 21; ++a)
				for(int b = 0; b <= 21; ++b)
					for(int c = 0; c <= 21; ++c) {
						if(dp[i][a][b][c] == -1)
							continue;
						flag = true;
						res = max(res, dp[i][a][b][c]);
						if(cards[i] == 'F') {
							if(a != 21 && dp[i][a][b][c] + 150 > dp[i + 1][0][b][c])
								dp[i + 1][0][b][c] = dp[i][a][b][c] + 150;
							if(b != 21 && dp[i][a][b][c] + 250 > dp[i + 1][a][0][c])
								dp[i + 1][a][0][c] = dp[i][a][b][c] + 250;
							if(c != 21 && dp[i][a][b][c] + 350 > dp[i + 1][a][b][0])
								dp[i + 1][a][b][0] = dp[i][a][b][c] + 350;
							continue;
						}
						int na, nb, nc, val = getValue(cards[i]), cur = dp[i][a][b][c];
						na = a + val;
						nb = b + val;
						nc = c + val;
						if(a == 21)
							;
						else if(na < 21) {
							dp[i + 1][na][b][c] = max(dp[i + 1][na][b][c], cur + 50);
						}
						else if(na == 21) {
							dp[i + 1][0][b][c] = max(dp[i + 1][0][b][c], cur + 150);
						}
						else {
							dp[i + 1][21][b][c] = max(dp[i + 1][21][b][c], cur + 50);
						}
						if(b == 21)
							;
						else if(nb < 21) {
							dp[i + 1][a][nb][c] = max(dp[i + 1][a][nb][c], cur + 50);
						}
						else if(nb == 21) {
							dp[i + 1][a][0][c] = max(dp[i + 1][a][0][c], cur + 250);
						}
						else {
							dp[i + 1][a][21][c] = max(dp[i + 1][a][21][c], cur + 50);
						}
						if(c == 21)
							;
						else if(nc < 21) {
							dp[i + 1][a][b][nc] = max(dp[i + 1][a][b][nc], cur + 50);
						}
						else if(nc == 21) {
							dp[i + 1][a][b][0] = max(dp[i + 1][a][b][0], cur + 350);
						}
						else {
							dp[i + 1][a][b][21] = max(dp[i + 1][a][b][21], cur + 50);
						}
					}
			if(!flag) {
				break;
			}
		}
		for(int a = 0; a <= 21; ++a)
			for(int b = 0; b <= 21; ++b)
				for(int c = 0; c <= 21; ++c) {
					res = max(res, dp[n][a][b][c]);
				}
		printf("%d\n", res);
	}
	return 0;
}
