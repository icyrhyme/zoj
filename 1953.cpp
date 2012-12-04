#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cassert>
#define ST 0
#define UP 1
#define LE 2
#define DI 3
#define MAXN 128
using namespace std;
int main() {
	char a[MAXN], b[MAXN];
	while(scanf("%s%s", b, a) != EOF) {
		int dp[MAXN][MAXN], dir[MAXN][MAXN];
		int lena = strlen(a), lenb = strlen(b);
		memset(dp, -1, sizeof(dp));
		for(int i = 1; i <= lena; ++i) {
			dp[i][0] = 0;
			dir[i][0] = UP;
		}
		for(int i = 1; i <= lenb; ++i) {
			dp[0][i] = 0;
			dir[0][i] = LE;
		}
		dp[0][0] = 0;
		dir[0][0] = ST;
		for(int i = 1; i <= lena; ++i)
			for(int j = 1; j <= lenb; ++j) {
				if(dp[i - 1][j] > dp[i][j]) {
					dp[i][j] = dp[i - 1][j];
					dir[i][j] = UP;
				}
				if(dp[i][j - 1] > dp[i][j]) {
					dp[i][j] = dp[i][j - 1];
					dir[i][j] = LE;
				}
				if(a[i - 1] == b[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					dir[i][j] = DI;
				}
			}
		vector<char> vec;
		for(int i = lena, j = lenb; i != 0 || j != 0;) {
			if(dir[i][j] == UP) {
				vec.push_back(a[i - 1]);
				--i;
			}
			else if(dir[i][j] == LE) {
				vec.push_back(b[j - 1]);
				--j;
			}
			else if(dir[i][j] == DI) {
				vec.push_back(a[i - 1]);
				--i, --j;
			}
		}
		for(int i = vec.size() - 1; i >= 0; --i) {
			putchar(vec[i]);
		}
		putchar('\n');
	}
	return 0;
}
