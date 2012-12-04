#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#define MAXN 128
#define MAXM 128
using namespace std;
class Hungary {
	int n, m;
	vector<int> e[MAXN];
	bool vis[MAXN];
	bool _augment(int u) {
		if(vis[u])
			return false;
		vis[u] = true;
		vector<int>::iterator it;
		for(it = e[u].begin(); it != e[u].end(); ++it) {
			if(rmatch[*it] == -1 || _augment(rmatch[*it])) {
				match[u] = *it;
				rmatch[*it] = u;
				return true;
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
		int cnt = 0;
		fill(match, match + n, -1);
		fill(rmatch, rmatch + m, - 1);
		for(int i = 0; i < n; ++i) {
			fill(vis, vis + n, false);
			if(_augment(i))
				++cnt;
		}
		return cnt;
	}
};
template <class T>
class IDGen {
	map<T, int> mp;
	vector<T> v;
public:
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
			v.push_back(elem);
		}
		return mp[elem];
	}
	int getElem(int id) {
		return v[id];
	}
};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int main() {
	int cs;
	scanf("%d", &cs);
	int t = 1;
	while(cs--) {
		int a[16][16];
		int n = 0, m = 0;
		IDGen<pair<int, int> > g;
		for(int i = 0; i < 15; ++i)
			for(int j = 0; j < 15; ++j) {
				scanf("%d", &a[i][j]);
				if(a[i][j] == 1) {
					++m;
					g.getId(make_pair(i, j));
				}
				else if(a[i][j] > 0)
					++n;
			}
		Hungary h;
		h.init(n, m);
		for(int i = 0; i < 15; ++i) {
			for(int j = 0; j < 15; ++j) {
				if(a[i][j] <= 1)
					continue;
				for(int k = 0; k < 8; ++k) {
					int newi = i + dx[k];
					int newj = j + dy[k];
					if(newi >= 0 && newi < 15 && newj >= 0 && newj < 15 && a[newi][newj] == 1) {
						int u = a[i][j] / 2 - 1;
						int v = g.getId(make_pair(newi, newj));
						h.addEdge(u, v);
					}
				}
			}
		}
		int cnt = h.maxMatch();
		printf("Round #%d:\n", t);
		if(cnt != n)
			printf("No solution.\n");
		else {
			for(int i = 0, k = 0; i < 15; ++i)
				for(int j = 0; j < 15; ++j) {
					if(a[i][j] == 1) {
						a[i][j] = 2 * h.rmatch[k] + 1;
						++k;
					}
					printf("%d%c", a[i][j], (j == 14 ? '\n' : ' '));
				}
		}
		putchar('\n');
		++t;
	}
	return 0;
}
