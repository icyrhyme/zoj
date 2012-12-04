#include <iostream>
#include <cstdio>
#define MAXN 21
using namespace std;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char mat[MAXN][MAXN];
bool isok(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '\0')
		return true;
	else
		return false;
}
char decode(char ch) {
	return ch - 7;
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		getchar();
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				mat[i][j] = getchar();
			}
		int x = 0, y = 0, di = 0;
		for(int i = 0; i < n * m; ++i) {
			putchar(decode(mat[x][y]));
			mat[x][y] = '\0';
			if(!isok(x + dx[di], y + dy[di])) {
				++di;
				if(di == 4)
					di = 0;
			}
			x = x + dx[di];
			y = y + dy[di];
		}
		putchar('\n');
	}
	return 0;
}
