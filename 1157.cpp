#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#define MAXN 410
#define MAXL 32
using namespace std;
class Hungary {
	int n, m;
	vector<int> e[MAXN];
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
	int match[MAXN], rmatch[MAXN];
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
template<class T>
class IDGen {
	map<T, int> mp;
	vector<T> v;
public:
	int size() {
		return v.size();
	}
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
			v.push_back(elem);
		}
		return mp[elem];
	}
	T getElem(int id) {
		return v[id];
	}
};
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, m, k;
		IDGen<string> ids;
		scanf("%d", &n);
		int from[MAXN], to[MAXN];
		char tmp[MAXL];
		for(int i = 0; i < n; ++i) {
			scanf("%s", tmp);
			from[i] = ids.getId((string)tmp);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			scanf("%*s%s", tmp);
			to[i] = ids.getId((string)tmp);
		}
		scanf("%d", &k);
		bool g[MAXN][MAXN];
		for(int i = 0; i < MAXN; ++i) {
			fill(g[i], g[i] + MAXN, false); 
			g[i][i] = true;
		}
		for(int i = 0; i < k; ++i) {
			int u, v;
			scanf("%s", tmp);
			u = ids.getId((string)tmp);
			scanf("%s", tmp);
			v = ids.getId((string)tmp);
			g[v][u] = true;
		}
		int sz = ids.size();
		for(int kk = 0; kk < sz; ++kk)
			for(int i = 0; i < sz; ++i) {
				if(!g[i][kk])
					continue;
				for(int j = 0; j < sz; ++j) {
					if(g[i][kk] && g[kk][j])
						g[i][j] = true;
				}
			}
		Hungary h;
		h.init(n, m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if(g[from[i]][to[j]]) {
					h.addEdge(i, j);
				}
			}
		printf("%d\n", m - h.maxMatch());
		if(cs != 0)
			putchar('\n');
	}
	return 0;
}

