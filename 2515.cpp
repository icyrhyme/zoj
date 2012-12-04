#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#define MAXN 1024
using namespace std;
struct point {
	int x, y, z;
	bool operator<(const point& p) const {
		if(x != p.x)
			return x < p.x;
		else if(y != p.y)
			return y < p.y;
		else
			return z < p.z;
	}
};
point make_point(int x, int y, int z) {
	point p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}
template <class T>
class IdGen {
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
	int size() {
		return mp.size();
	}
	T getElem(int id) {
		return v[id];
	}
};
vector<int> ng[MAXN];
bool vis[MAXN];
int gsz;
void dfs(int u) {
	if(!vis[u]) {
		vis[u] = true;
		for(int i = 0; i < ng[u].size(); ++i)
			dfs(ng[u][i]);
	}
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		point p;
		IdGen<point> ids;
		vector<int> g[MAXN];
		int maxh = -1;
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d%d%d", &p.x, &p.y, &p.z);
			maxh = max(maxh, p.z);
			u = ids.getId(p);
			scanf("%d%d%d", &p.x, &p.y, &p.z);
			maxh = max(maxh, p.z);
			v = ids.getId(p);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int le = 0, ri = maxh;
		int m;
		vector<int> dst;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%d", &p.x, &p.y, &p.z);
			dst.push_back(ids.getId(p));
		}
		while(le <= ri) {
			int mi = (le + ri) / 2;
			gsz = ids.size();
			for(int i = 0; i < gsz; ++i) {
				ng[i].clear();
				p = ids.getElem(i);
				if(p.z > mi)
					continue;
				for(int j = 0; j < g[i].size(); ++j) {
					p = ids.getElem(g[i][j]);
					if(p.z > mi)
						continue;
					ng[i].push_back(g[i][j]);
				}
			}
			fill(vis, vis + gsz, false);
			int src = ids.getId(make_point(0, 0, 0));
			dfs(src);
			int isok = true;
			for(int i = 0; i < dst.size(); ++i) {
				if(!vis[dst[i]]) {
					isok = false;
					break;
				}
			}
			if(isok)
				ri = mi - 1;
			else
				le = mi + 1;
		}
		printf("%d\n", le);
	}
	return 0;
}
