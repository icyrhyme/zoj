#include <iostream>
#define MAXN 128
#define LL long long
#define MOD 10000007
using namespace std;
char g[MAXN][MAXN];
int ind[MAXN], outd[MAXN], dp[MAXN][MAXN], N;
bool vis[MAXN];
void init() {
	dp[0][0] = 1;
	for(int i = 1; i < MAXN; ++i)
		dp[0][i] = (LL)dp[0][i - 1] * i % MOD;
	for(int j = 0; j < MAXN; ++j)
		dp[1][j] = (LL)dp[0][j] * j % MOD;
	for(int i = 2; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) {
			dp[i][j] = (int)((LL)dp[i - 2][j + 1] * (i - 1) % MOD);
			dp[i][j] = (int)(((LL)dp[i - 1][j] * j + dp[i][j]) % MOD);
		}
}
bool input() {
	scanf("%d", &N);
	if(N == 0)
		return false;
	for(int i = 0; i < N; ++i)
		scanf("%s", g[i]);
	return true;
}
#define DOT 0
#define LINE 1
int compType(int c) {
	vis[c] = true;
	int mind = ind[c] + outd[c];
	for(int i = 0; i < N; ++i) {
		if(g[c][i] == 'N' || vis[i] == true)
			continue;
		int temp = compType(i);
		mind = min(mind, temp);
	}
	return mind;
}
int solve() {
	memset(ind, 0, sizeof(ind));
	memset(outd, 0, sizeof(outd));
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(g[i][j] == 'Y') {
				++outd[i];
				++ind[j];
			}
		}
	}
	for(int i = 0; i < N; ++i)
		if(ind[i] > 1 || outd[i] > 1)
			return 0;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(g[i][j] == 'Y')
				g[j][i] = 'Y';
	memset(vis, false, sizeof(vis));
	int lcnt, dcnt = lcnt = 0;
	for(int i = 0; i < N; ++i) {
		if(vis[i])
			continue;
		int type = compType(i);
		if(type == LINE)
			++lcnt;
		else if(type == DOT)
			++dcnt;
	}
	return dp[dcnt][lcnt];
}
int main() {
	init();
	while(input()) {
		printf("%d\n", solve());
	}
	return 0;
}
