#include <cstdio>
#define MAXN 32
#define MAXR 10
#define MAXC 15
#define INF 1000000000
using namespace std;
class state {
	int gx, gy, mx, my;
	state(int gx, int gy, int mx, int my) {
		this->gx = gx;
		this->gy = gy;
		this->mx = mx;
		this->my = my;
	}
	bool operator<(const state& lhs, const state& rhs) const {
		pair<pair<int, int>, pair<int, int> > a, b;
		a = make_pair(make_pair(lhs.gx, lhs.gy), make_pair(lhs.mx, lhs.my));
		b = make_pair(make_pair(rhs.gx, rhs.gy), make_pair(rhs.mx, rhs.my));
		return (a < b);
	}
};
char mp[MAXN][MAXN];
int d[MAXR][MAXC][MAXR][MAXC];
int gao(int gx, int gy, int mx, int my) {
	memset(d, -1, sizeof(d));
	d[gx][gy][mx][my] = 0;
	priority_queue<pair<int, state> > q;
	state s(gx, gy, mx, my);
	q.push(make_pair(0, s));
	while(!q.empty()) {
	}
}
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		for(int i = 0; i < MAXR; ++i)
			scanf("%s", mp[i]);
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1, --y1, --x2, --y2;
		int ans = min(gao(x1, y1, x2, y2), gao(x2, y2, x1, y1));
		if(ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
