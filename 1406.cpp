#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 32
#define MAXL 4
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
		int ur, vr;
		ur = find(u);
		vr = find(v);
		if(ur != vr) {
			if(a[ur] > a[vr])
				swap(ur, vr);
			a[ur] += a[vr];
			a[vr] = ur;
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
	vector<edge> e;
	int n;
public:
	void init(int nn) {
		n = nn;
	}
	void addEdge(int u, int v, int w) {
		edge tmp;
		tmp.u = u;
		tmp.v = v;
		tmp.w = w;
		e.push_back(tmp);
	}
	int MST() {
		int ret = 0;
		sort(e.begin(), e.end());
		DisjointSet di;
		vector<edge>::iterator it;
		di.init(n);
		for(it = e.begin(); it != e.end(); ++it) {
			if(di.find(it->u) != di.find(it->v)) {
				di.setUnion(it->u, it->v);
				ret += it->w;
			}
		}
		return ret;
	}
};
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		char label[MAXL];
		int k, w;
		Kruskal kr;
		kr.init(n);
		for(int i = 0; i < n - 1; ++i) {
			scanf("%*s");
			scanf("%d", &k);
			for(int j = 0; j < k; ++j) {
				scanf("%s%d", label, &w);
				kr.addEdge(i, label[0] - 'A', w);
			}
		}
		printf("%d\n", kr.MST());
	}
	return 0;
}
