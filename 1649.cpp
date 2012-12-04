#include <iostream>
#include <queue>
#include <cstdio>
#include <cassert>
#define MAXN 1024
using namespace std;
struct state {
	int x, y, e;
};
state make_state(int x, int y, int e) {
	state s;
	s.x = x;
	s.y = y;
	s.e = e;
	return s;
}
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		char mp[MAXN][MAXN];
		int d[MAXN][MAXN][2];
		int ax, ay, rx, ry;
		queue<state> q;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < 2; ++k)
					d[i][j][k] = -1;
		for(int i = 0; i < n; ++i) {
			scanf("%s", mp[i]);
			for(int j = 0; j < m; ++j) {
				if(mp[i][j] == 'a') {
					ax = i;
					ay = j;
				}
				if(mp[i][j] == 'r') {
					q.push(make_state(i, j, 0));
					d[i][j][0] = 0;
				}
			}
		}
		assert(ax >= 0 && ax < n && ay >= 0 && ay < m);
		while(!q.empty()) {
			state s = q.front();
			q.pop();
			assert(s.x >= 0 && s.x < n && s.y >= 0 && s.y < m);
			assert(s.e == 0 || s.e == 1);
			if(s.x == ax && s.y == ay)
				break;
			if(s.e == 1) {
				if(d[s.x][s.y][0] == -1) {
					q.push(make_state(s.x, s.y, 0)); 
					d[s.x][s.y][0] = d[s.x][s.y][1] + 1;
				}
				continue;
			}
			for(int i = 0; i < 4; ++i) {
				int nx = s.x + dx[i];
				int ny = s.y + dy[i];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != '#') {
					assert(nx >= 0 && nx < n && ny >= 0 && ny < m);
					int e;
					if(mp[nx][ny] == 'x')
						e = 1;
					else
						e = 0;
					if(d[nx][ny][e] == -1) {
						q.push(make_state(nx, ny, e));
						d[nx][ny][e] = d[s.x][s.y][s.e] + 1;
					}
				}
			}
		}
		while(1);
		if(d[ax][ay][0] == -1)
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		else
			printf("%d\n", d[ax][ay][0]);
	}
	return 0;
}
