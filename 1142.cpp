#include <iostream>
#include <cstdio>
#define MAXN 256
using namespace std;
char mp[MAXN][MAXN];
int n, m;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};
char bc[4] = {'/', '\\', '\\', '/'};
bool isok;
inline bool isGood(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}
int dfs(int x, int y) {
	int cnt = 1;
	mp[x][y] = 'X';
	for(int i = 0; i < 4; ++i) {
		int nx, ny, bx, by;
		nx = x + dx[i];
		ny = y + dy[i];
		if(x % 2 == 0) {
			bx = x;
			by = ny;
		}
		else {
			bx = nx;
			by = y;
		}
		if(!isGood(bx, by) || mp[bx][by] != bc[i] && !isGood(nx, ny)) {
			isok = false;
		}
		else if(mp[bx][by] != bc[i] && isGood(nx, ny) && mp[nx][ny] == ' ') {
			int val = dfs(nx, ny);
			cnt += val;
		}
	}
	return cnt;
}
int main() {
	int csnum = 1;
	while(scanf("%d%d", &m, &n) != EOF) {
		if(m == 0 && n == 0)
			break;
		getchar();
		n = 2 * n - 1;
		m = 2 * m - 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				mp[i][j] = ' ';
		char c;
		for(int i = 0; i < n; i += 2) {
			for(int j = 0; j < m; j += 2) {
				c = getchar();
				mp[i][j] = c;
			}
			getchar();
		}
		int ccnt = 0, cmax = -1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if((i + j) % 2 != 1 || mp[i][j] != ' ')
					continue;
				isok = true;
				int cnt = dfs(i, j);
				if(isok) {
					//printf("%d %d %d\n", i, j, cnt);
					++ccnt;
					cmax = max(cmax, cnt);
				}
			}
		printf("Maze #%d:\n", csnum);
		++csnum;
		if(ccnt > 0)
			printf("%d Cycles; the longest has length %d.\n", ccnt, cmax);
		else
			printf("There are no cycles.\n");
		putchar('\n');
	}
}
