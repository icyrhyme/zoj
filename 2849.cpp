#include <iostream>
#include <cstdio>
#include <queue>
#define INF 1000000000
#define MAXN 512
using namespace std;
int a[MAXN][MAXN];
int cnt[MAXN * MAXN];
int vis[MAXN][MAXN];
struct state {
	int x, y, d, t;
	state() {}
	state(int x, int y, int d, int t):x(x), y(y), d(d), t(t) {}
	bool operator<(const state& o) const {
		if(d != o.d)
			return d > o.d;
		else
			return t > o.t;
	}
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		priority_queue<state, vector<state> > q;
		int maxt = -1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				vis[i][j] = INF;
				if(a[i][j] > 0) {
					q.push(state(i, j, 0, a[i][j]));
					vis[i][j] = a[i][j];
					maxt = max(maxt, a[i][j]);
					a[i][j] = -1;
				}
			}
		}
		while(!q.empty()) {
			state s = q.top();
			q.pop();
			if(a[s.x][s.y] < 0)
				a[s.x][s.y] = s.t;
			else
				continue;
			for(int i = 0; i < 4; ++i) {
				int nx, ny;
				nx = s.x + dx[i];
				ny = s.y + dy[i];
				if(min(nx, ny) >= 0 && nx < n && ny < m && a[nx][ny] < 0 && s.t < vis[nx][ny]) {
					q.push(state(nx, ny, -a[nx][ny], s.t));
				}
			}
		}
		for(int i = 0; i < maxt; ++i)
			cnt[i] = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				cnt[a[i][j] - 1]++;
			}
		int qn;
		scanf("%d", &qn);
		for(int i = 0; i < qn; ++i) {
			int x;
			scanf("%d", &x);
			printf("%d\n", cnt[x - 1]);
		}
	}
}
