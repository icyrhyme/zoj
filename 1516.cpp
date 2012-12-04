#include <iostream>
#include <vector>
#include <cstdio>
#define MAXN 128
#define MAXM 128
using namespace std;
class Hungary {
	vector<int> e[MAXN];
	int n, m;
	bool vis[MAXN];
	bool _augment(int u) {
		if(!vis[u]) {
			vis[u] = true;
			vector<int>::iterator it;
			for(it = e[u].begin(); it != e[u].end(); ++it) {
				if(rmatch[*it] == -1 || _augment(rmatch[*it])) {
					match[u] = *it;
					rmatch[*it] = u;
					return true;
				}
			}
		}
		return false;
	}
public:
	int match[MAXN], rmatch[MAXM];
	void init(int nn, int mm) {
		n = nn;
		m = mm;
		for(int i = 0; i < n; ++i)
			e[i].clear();
	}
	void addEdge(int u, int v) {
		e[u].push_back(v);
	}
	int maxMatch() {
		fill(match, match + n, -1);
		fill(rmatch, rmatch + m, -1);
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			fill(vis, vis + n, false);
			if(_augment(i))
				++cnt;
		}
		return cnt;
	}
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		int k;
		int land[MAXN][MAXM];
		scanf("%d", &k);
		for(int i = 0; i < n; ++i)
			fill(land[i], land[i] + m, 0);
		for(int i = 0; i < k; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			land[x][y] = -1;
		}
		int bid = 0, wid = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if(land[i][j] == -1)
					continue;
				if((i + j) % 2 == 0) {
					land[i][j] = bid;
					bid++;
				}
				else {
					land[i][j] = wid;
					wid++;
				}
			}
		Hungary h;
		h.init(bid, wid);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				for(int k = 0; k < 4; ++k) {
					if(land[i][j] == -1 || (i + j) % 2 != 0)
						continue;
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(ni >= 0 && ni < n && nj >= 0 && nj < m && land[ni][nj] >= 0)
						h.addEdge(land[i][j], land[ni][nj]);
				}
			}
		printf("%d\n", h.maxMatch());
	}
	return 0;
}
