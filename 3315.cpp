#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
using namespace std;
#define MAXN 128
char map[MAXN][MAXN];
char mm[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, a, b, newn, newm;
void dfs(int x, int y) {
	vis[x][y] = true;
	if(x + 1 <= a && y <= b && !vis[x + 1][y] && mm[x + 1][y] != 'X')
		dfs(x + 1, y);
	if(x <= a && y + 1 <= b && !vis[x][y + 1] && mm[x][y + 1] != 'X')
		dfs(x, y + 1);
}
bool isOK() {
	for(int i = 0, j = 0; i < n && j < m; i += a, j += b)
		if(map[i][j] == 'X')
			return false;
	for(int i = 0; i <= a; ++i)
		for(int j = 0; j <= b; ++j)
			mm[i][j] = '.';
	for(int i = 0, j = 0; i < n && j < m; i += a, j += b) {
		int limi, limj;
		if(i + a < n && j + b < m) {
			limi = a;
			limj = b;
		}
		else {
			newn = limi = n - i - 1;
			newm = limj = m - j - 1;
		}
		for(int ii = 0; ii <= limi; ++ii)
			for(int jj = 0; jj <= limj; ++jj) {
				if(map[i + ii][j + jj] == '.')
					continue;
				mm[ii][jj] = map[i + ii][j + jj];
			}
	}
	if(newn == 0 && newm == 0) {
		newn = a;
		newm = b;
	}
	memset(vis, false, sizeof(vis));
	dfs(0, 0);
	if(vis[newn][newm] != true)
		return false;
	
	memset(vis, false, sizeof(vis));
	dfs(newn, newm);
	if(vis[a][b] != true)
		return false;

	return true;
}
int solve() {
	int cnt = 0;
	a = n - 1, b = m - 1;
	if(!isOK())
		return -1;
	for(int s = 2; s <= m + n - 2; ++s) {
		for(a = 1; a < min(n, s); ++a) {
			b = s - a;
			if(b >= m)
				continue;
			int ale = (n + a - 2) / a, ari = (n - 1) / a + 1;
			int ble = (m + b - 2) / b, bri = (m - 1) / b + 1;
			if(max(ale, ble) > min(ari, bri))
				continue;
			//printf("%d %d\n", a, b);
			//cnt++;
			if(isOK())
				return s;
		}
	}
	//printf("%d\n", cnt);
	return -1;
}
int main() {
	while(scanf("%d%d", &m, &n) != EOF) {
		for(int i = 0; i < n; ++i)
			scanf("%s", map[i]);
		printf("%d\n", solve());
	}
}
