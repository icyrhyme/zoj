#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXR 21
#define MAXC 21
using namespace std;
struct state {
	int mx, my, bx, by;
};
state make_state(int mx, int my, int bx, int by) {
	state s;
	s.mx = mx;
	s.my = my;
	s.bx = bx;
	s.by = by;
	return s;
}
inline bool isIn(int x, int y, int n, int m) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ch[8] = {'e', 's', 'w', 'n', 'E', 'S', 'W', 'N'};
int main() {
	int r, c, csnum = 1;
	while(scanf("%d%d", &r, &c) != EOF) {
		if(r == 0 && c == 0)
			break;
		char mp[MAXR][MAXC];
		int mx, my, bx, by, tx, ty;
		for(int i = 0; i < r; ++i) {
			scanf("%s", mp[i]);
			for(int j = 0; j < c; ++j) {
				if(mp[i][j] == 'S') {
					mx = i;
					my = j;
					mp[i][j] = '.';
				}
				if(mp[i][j] == 'B') {
					bx = i;
					by = j;
					mp[i][j] = '.';
				}
				if(mp[i][j] == 'T') {
					tx = i;
					ty = j;
					mp[i][j] = '.';
				}
			}
		}
		int d[MAXR][MAXC][MAXR][MAXC];
		int pre[MAXR][MAXC][MAXR][MAXC];
		queue<state> q, p;
		memset(d, -1, sizeof(d));
		memset(pre, -1, sizeof(pre));
		d[mx][my][bx][by] = 0;
		q.push(make_state(mx, my, bx, by));
		bool found = false;
		while(1) {
			if(q.empty())
				break;
			while(!q.empty()) {
				state s = q.front();
				p.push(s);
				q.pop();
				if(s.bx == tx && s.by == ty) {
					found = true;
					mx = s.mx;
					my = s.my;
					break;
				}
				for(int i = 0; i < 4; ++i) {
					int nmx = s.mx + dx[i];
					int nmy = s.my + dy[i];
					if(isIn(nmx, nmy, r, c) && !(nmx == s.bx && nmy == s.by)
							&& mp[nmx][nmy] == '.' && d[nmx][nmy][s.bx][s.by] == -1) {
						q.push(make_state(nmx, nmy, s.bx, s.by));
						d[nmx][nmy][s.bx][s.by] = d[s.mx][s.my][s.bx][s.by];
						pre[nmx][nmy][s.bx][s.by] = i;
					}
				}
			}
			if(p.empty() || found)
				break;
			while(!p.empty()) {
				state s = p.front();
				p.pop();
				for(int i = 0; i < 4; ++i) {
					int nmx = s.mx + dx[i];
					int nmy = s.my + dy[i];
					if(isIn(nmx, nmy, r, c) && nmx == s.bx && nmy == s.by) {
						int nbx = s.bx + dx[i];
						int nby = s.by + dy[i];
						if(isIn(nbx, nby, r, c) && mp[nbx][nby] == '.' && d[nmx][nmy][nbx][nby] == -1) {
							q.push(make_state(nmx, nmy, nbx, nby));
							d[nmx][nmy][nbx][nby] = d[s.mx][s.my][s.bx][s.by] + 1;
							pre[nmx][nmy][nbx][nby] = i + 4;
						}
					}
				}
			}
		}
		printf("Maze #%d\n", csnum);
		csnum++;
		if(found) {
			vector<char> v;
			int step = d[mx][my][tx][ty];
			bx = tx, by = ty;
			for(int i = 0; pre[mx][my][bx][by] != -1; ++i) {
				int idx = pre[mx][my][bx][by];
				v.push_back(ch[idx]);
				if(idx < 4) {
					mx -= dx[idx];
					my -= dy[idx];
				}
				else {
					idx -= 4;
					mx -= dx[idx];
					my -= dy[idx];
					bx -= dx[idx];
					by -= dy[idx];
				}
			}
			for(int i = v.size() - 1; i >= 0; --i)
				putchar(v[i]);
			putchar('\n');
			putchar('\n');
		}
		else {
			printf("Impossible.\n\n");
		}
	}
}
