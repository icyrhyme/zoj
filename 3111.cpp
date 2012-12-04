#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define MAXN 62
#define MAXV 2000
using namespace std;
class Hungary {
	vector<int> e[MAXV];
	int match[MAXV], rmatch[MAXV], m, n;
	bool vis[MAXV];
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
	void init(int nn, int mm) {
		n = nn;
		m = mm;
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
			if(_augment(i)) {
				++cnt;
			}
		}
		return cnt;
	}
};
template<class T>
class IDGen {
	map<T, int> mp;
public:
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
		}
		return mp[elem];
	}
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		char b[MAXN][MAXN];
		int lcnt = 0, rcnt = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%s", b[i]);
			for(int j = 0; j < m; ++j) {
				if(b[i][j] == '.')
					continue;
				if((i + j) % 2 == 0)
					++lcnt;
				else
					++rcnt;
			}
		}
		if(lcnt != rcnt) {
			printf("Case %d: Impossible\n", csnum);
			++csnum;
			continue;
		}
		IDGen<pair<int, int> > le, ri;
		Hungary h;
		h.init(lcnt, rcnt);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if((i + j) % 2 != 0 || b[i][j] == '.')
					continue;
				int u, v;
				u = le.getId(make_pair(i, j));
				for(int k = 0; k < 4; ++k) {
					int nx, ny;
					nx = i + dx[k];
					ny = j + dy[k];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && b[nx][ny] == '#') {
						v = ri.getId(make_pair(nx, ny));
						h.addEdge(u, v);
					}
				}
			}
		int res = h.maxMatch();
		if(res == lcnt) {
			printf("Case %d: Possible\n", csnum);
		}
		else {
			printf("Case %d: Impossible\n", csnum);
		}
		csnum++;
	}
	return 0;
}
