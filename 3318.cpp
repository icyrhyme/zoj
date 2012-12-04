#include <iostream>
#include <queue>
#define MAXN 32
#define INF 1000000000
using namespace std;
int n, m, s, t;
bool map[MAXN][MAXN][MAXN];
int sp[MAXN][MAXN];
bool cmap[MAXN][MAXN];
int ShortestPath() {
	int len[MAXN];
	memset(len, -1, sizeof(len));
	len[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int ele = q.front();
		q.pop();
		for(int i = 0; i < n; ++i)
			if(cmap[ele][i] && len[i] == -1) {
				q.push(i);
				len[i] = len[ele] + 1;
			}
	}
	return len[t];
}
int solve() {
	memset(sp, -1, sizeof(sp));
	for(int i = 0; i < m; ++i) {
		memset(cmap, true, sizeof(cmap));
		for(int j = i; j < m; ++j) {
			for(int k = 0; k < n; ++k)
				for(int ii = 0; ii < n; ++ii)
					cmap[k][ii] = (cmap[k][ii] && map[j][k][ii]);
			sp[i][j] = ShortestPath();
			if(sp[i][j] == -1)
				break;
		}
	}
	int dp[MAXN];
	for(int i = 0; i <= m; ++i)
		dp[i] = INF;
	dp[0] = 0;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= i; ++j) {
			if(sp[j - 1][i - 1] != -1) {
				dp[i] = min(dp[i], dp[j - 1] + sp[j - 1][i - 1] * (i - j + 1) + (j == 1 ? 0 : 1));
			}
		}
	return dp[m];
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &n, &m, &s, &t);
		--s, --t;
		memset(map, false, sizeof(map));
		for(int i = 0; i < m; ++i) {
			int R;
			scanf("%d", &R);
			for(int j = 0; j < R; ++j) {
				int u, v;
				scanf("%d%d", &u, &v);
				--u, --v;
				map[i][u][v] = map[i][v][u] = true;
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}
