#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 64
#define INF 1000000000
using namespace std;
class DisjointSet {
	int a[MAXN];
	int n;
public:
	void init(int nn) {
		n = nn;
		fill(a, a + n, -1);
	}
	int find(int x) {
		if(a[x] < 0)
			return x;
		else
			return (a[x] = find(a[x]));
	}
	void setUnion(int u, int v) {
		int ru = find(u);
		int rv = find(v);
		if(ru != rv) {
			if(a[ru] > a[rv]) {
				swap(ru, rv);
			}
			a[ru] += a[rv];
			a[rv] = ru;
		}
	}
};
class Kruskal {
	struct edge {
		int u, v, w;
		bool operator<(const edge& o) const {
			return w < o.w;
		}
	};
	int c[MAXN][MAXN];
	int n;
public:
	void init(int nn) {
		n = nn;
		for(int i = 0; i < n; ++i)
			fill(c[i], c[i] + n, INF);
	}
	void addEdge(int u, int v, int w) {
		if(u > v)
			swap(u, v);
		if(c[u][v] > w)
			c[u][v] = w;
	}
	int MST() {
		vector<edge> e;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j) {
				if(c[i][j] == INF)
					continue;
				edge tmp;
				tmp.u = i;
				tmp.v = j;
				tmp.w = c[i][j];
				e.push_back(tmp);
			}
		sort(e.begin(), e.end());
		DisjointSet di;
		di.init(n);
		vector<edge>::iterator it;
		int ret = 0;
		for(it = e.begin(); it != e.end(); ++it) {
			if(di.find(it->u) != di.find(it->v)) {
				ret += it->w;
				di.setUnion(it->u, it->v);
			}
		}
		return ret;
	}
};
int main() {
	int n, m;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		scanf("%d", &m);
		if(m == 0) {
			puts("0");
			continue;
		}
		Kruskal kr;
		kr.init(n);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			--u, --v;
			kr.addEdge(u, v, w);
		}
		printf("%d\n", kr.MST());
	}
	return 0;
}
