#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#define INF 1000000000
#define MAXN 128
#define MAXM 22010
using namespace std;
class Dinic {
	int n, m, head[MAXN], level[MAXN], s, t, work[MAXN];
	struct edge {
		int v, c, f, nxt;
		edge() {}
		edge(int v, int c, int f, int nxt): v(v), c(c), f(f), nxt(nxt) {}
	} e[MAXM];
	bool _bfs() {
		static int q[MAXN];
		memset(level, -1, sizeof(int) * n);
		int le = 0, ri = 0;
		q[ri++] = s;
		level[s] = 0;
		while(le < ri) {
			for(int k = q[le++], i = head[k]; i != -1; i = e[i].nxt) {
				if(e[i].f < e[i].c && level[e[i].v] == -1) {
					level[e[i].v] = level[k] + 1;
					q[ri++] = e[i].v;
				}
			}
		}
		return (level[t] != -1);
	}
	int _dfs(int u, int f) {
		if(u == t)
			return f;
		for(int& i = work[u]; i != -1; i = e[i].nxt) {
			if(e[i].f < e[i].c && level[u] + 1 == level[e[i].v]) {
				int minf = _dfs(e[i].v, min(f, e[i].c - e[i].f));
				if(minf > 0) {
					e[i].f += minf;
					e[i ^ 1].f -= minf;
					return minf;
				}
			}
		}
		return 0;
	}
public:
	void init(int nn, int src, int dst) {
		n = nn;
		s = src;
		t = dst;
		m = 0;
		memset(head, -1, sizeof(int) * n);
	}
	void addEdge(int u, int v, int c, int rc) {
		assert(u < n);
		assert(v < n);
		e[m] = edge(v, c, 0, head[u]);
		head[u] = m++;
		e[m] = edge(u, rc, 0, head[v]);
		head[v] = m++;
		assert(m < MAXM);
	}
	int maxFlow() {
		int ret = 0;
		while(_bfs()) {
			memcpy(work, head, sizeof(int) * n);
			while(true) {
				int delta = _dfs(s, INF);
				if(delta == 0)
					break;
				ret += delta;
			}
		}
		return ret;
	}
} dinic;
#define MAXL 20
int main() {
	int n, np, nc, m, csnum = 1;
	while(scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF) {
		dinic.init(n + 2, n, n + 1);
		char str[MAXL];
		for(int i = 0; i < m; ++i) {
			int u, v, c;
			scanf("%s", str);
			sscanf(str, "(%d,%d)%d", &u, &v, &c);
			dinic.addEdge(u, v, c, 0);
		}
		for(int i = 0; i < np; ++i) {
			int v, c;
			scanf("%s", str);
			sscanf(str, "(%d)%d", &v, &c);
			dinic.addEdge(n, v, c, 0);
		}
		for(int i = 0; i < nc; ++i) {
			int u, c;
			scanf("%s", str);
			sscanf(str, "(%d)%d", &u, &c);
			dinic.addEdge(u, n + 1, c, 0);
		}
		printf("%d\n", dinic.maxFlow());
		++csnum;
	}
	return 0;
}
