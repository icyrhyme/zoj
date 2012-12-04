#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXH 64
#define MAXW 64
using namespace std;
char img[MAXH][MAXW];
int comp[MAXH][MAXW];
int w, h;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs1(int x, int y, int cn) {
	comp[x][y] = cn;
	for(int i = 0; i < 4; ++i) {
		int nx, ny;
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && img[nx][ny] != '.' && comp[nx][ny] == -1)
			dfs1(nx, ny, cn);
	}
}
void dfs2(int x, int y) {
	img[x][y] = '*';
	for(int i = 0; i < 4; ++i) {
		int nx, ny;
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && img[nx][ny] == 'X')
			dfs2(nx, ny);
	}
}
int main() {
	int csnum = 1;
	while(scanf("%d%d", &w, &h) != EOF) {
		if(w == 0 && h == 0)
			break;
		for(int i = 0; i < h; ++i) {
			scanf("%s", img[i]);
			fill(comp[i], comp[i] + w, -1);
		}
		int cn = 0;
		for(int i = 0; i < h; ++i)
			for(int j = 0; j < w; ++j) {
				if(img[i][j] != '.' && comp[i][j] == -1) {
					dfs1(i, j, cn);
					cn++;
				}
			}
		vector<int> cnt(cn, 0);
		for(int i = 0; i < h; ++i)
			for(int j = 0; j < w; ++j) {
				if(img[i][j] == 'X') {
					dfs2(i, j);
					cnt[comp[i][j]]++;
				}
			}
		sort(cnt.begin(), cnt.end());
		printf("Throw %d\n", csnum);
		csnum++;
		for(int i = 0; i < cnt.size(); ++i) {
			printf("%d%c", cnt[i], (i == cnt.size() - 1 ? '\n' : ' '));
		}
		putchar('\n');
	}
	return 0;
}
