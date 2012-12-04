#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 40
using namespace std;
struct state {
	int x, y, z;
};
state make_state(int x, int y, int z) {
	state tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return tmp;
}
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int main() {
	int l, r, c;
	while(scanf("%d%d%d", &l, &r, &c) != EOF) {
		if(l == 0 && r == 0 && c == 0)
			break;
		char tmp[MAXN];
		char mp[MAXN][MAXN][MAXN];
		int d[MAXN][MAXN][MAXN];
		queue<state> q;
		memset(mp, '#', sizeof(mp));
		memset(d, -1, sizeof(d));
		int ex, ey, ez;
		for(int i = 0; i < l; ++i)
			for(int j = 0; j < r; ++j) {
				scanf("%s", tmp);
				for(int k = 0; k < c; ++k) {
					mp[i + 1][j + 1][k + 1] = tmp[k];
					if(mp[i + 1][j + 1][k + 1] == 'S') {
						q.push(make_state(i + 1, j + 1, k + 1));
						d[i + 1][j + 1][k + 1] = 0;
					}
					if(mp[i + 1][j + 1][k + 1] == 'E') {
						ex = i + 1;
						ey = j + 1;
						ez = k + 1;
					}
				}
			}
		while(!q.empty()) {
			state s = q.front();
			q.pop();
			for(int i = 0; i < 6; ++i) {
				int nx, ny, nz;
				nx = s.x + dx[i];
				ny = s.y + dy[i];
				nz = s.z + dz[i];
				if(mp[nx][ny][nz] != '#' && d[nx][ny][nz] == -1) {
					q.push(make_state(nx, ny, nz));
					d[nx][ny][nz] = d[s.x][s.y][s.z] + 1;
				}
			}
		}
		if(d[ex][ey][ez] == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", d[ex][ey][ez]);
	}
	return 0;
}
