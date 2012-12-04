#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAXN 1024
using namespace std;
class DisjointSet {
	int n, v[MAXN];
public:
	void init(int nn) {
		n = nn;
		fill(v, v + n, -1);
	}
	int find(int e) {
		if(v[e] < 0)
			return e;
		else
			return (v[e] = find(v[e]));
	}
	void setUnion(int le, int ri) {
		int lr = find(le), rr = find(ri);
		if(v[lr] > v[rr])
			swap(lr, rr);
		v[lr] += v[rr];
		v[rr] = lr;
	}
};
class Kruskal {
	struct edge {
		int u, v, w;
		bool operator<(const edge& o) const {
			return w < o.w;
		}
	};
	int n;
	vector<edge> e;
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
		DisjointSet ds;
		ds.init(n);
		sort(e.begin(), e.end());
		vector<edge>::iterator it;
		int ret = 0;
		for(it = e.begin(); it != e.end(); ++it) {
			if(ds.find(it->u) != ds.find(it->v)) {
				ds.setUnion(it->u, it->v);
				ret += it->w;
			}
		}
		return ret;
	}
};
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		scanf("%d", &n);
		int vw[MAXN];
		for(int i = 0; i < n; ++i)
			scanf("%d", &vw[i]);
		int temp;
		Kruskal kr;
		kr.init(n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &temp);
				if(j > i) {
					kr.addEdge(i, j, vw[i] + vw[j] + temp);
				}
			}
		}
		printf("%d\n", kr.MST());
	}
	return 0;
}
