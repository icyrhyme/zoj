#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 256
#define MAXE 3000
#define INF 1000000000
using namespace std;
class Dinic {
	int n, m, src, dst, head[MAXN], work[MAXN], d[MAXN];
	struct edge {
		int v, f, c, nxt;
		edge() {}
		edge(int v, int f, int c, int nxt): v(v), f(f), c(c), nxt(nxt) {}
	} e[MAXE];
	bool _bfs() {
		int q[MAXN], le, ri;
		le = 0, ri = 0;
		memset(d, -1, sizeof(int) * n);
		q[ri++] = src;
		d[src] = 0;
		while(le < ri) {
			for(int k = q[le++], i = head[k]; i != -1; i = e[i].nxt) {
				if(e[i].f < e[i].c && d[e[i].v] == -1) {
					q[ri++] = e[i].v;
					d[e[i].v] = d[k] + 1;
				}
			}
		}
		return (d[dst] != -1);
	}
	int _dfs(int u, int f) {
		if(u == dst)
			return f;
		for(int& i = work[u]; i != -1; i = e[i].nxt) {
			if(e[i].f < e[i].c && d[e[i].v] == d[u] + 1) {
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
	void init(int n, int src, int dst) {
		this->n = n;
		this->src = src;
		this->dst = dst;
		m = 0;
		memset(head, -1, sizeof(int) * n);
	}
	void addEdge(int u, int v, int c, int rc) {
		e[m] = edge(v, 0, c, head[u]);
		head[u] = m++;
		e[m] = edge(u, 0, rc, head[v]);
		head[v] = m++;
	}
	int maxFlow() {
		int ret = 0;
		while(_bfs()) {
			memcpy(work, head, sizeof(int) * n);
			while(true) {
				int delta = _dfs(src, INF);
				if(delta == 0)
					break;
				ret += delta;
			}
		}
		return ret;
	}
} dinic;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, m, deg[MAXN];
		scanf("%d%d", &n, &m);
		dinic.init(n + 2, n, n + 1);
		memset(deg, 0, sizeof(int) * n);
		for(int i = 0; i < m; ++i) {
			int u, v, t;
			scanf("%d%d%d", &u, &v, &t);
			--u, --v;
			--deg[u];
			++deg[v];
			if(t == 0)
				dinic.addEdge(u, v, 1, 0);
		}
		int isok = true;
		for(int i = 0; i < n; ++i) {
			if(deg[i] % 2 == 1) {
				isok = false;
				break;
			}
			else 
				deg[i] /= 2;
		}
		if(!isok) {
			printf("impossible\n");
			continue;
		}
		int fullFlow = 0;
		for(int i = 0; i < n; ++i) {
			if(deg[i] < 0) {
				dinic.addEdge(n, i, -deg[i], 0);
			}
			else if(deg[i] > 0) {
				fullFlow += deg[i];
				dinic.addEdge(i, n + 1, deg[i], 0);
			}
		}
		int ans = dinic.maxFlow();
		if(ans == fullFlow) {
			printf("possible\n");
		}
		else {
			printf("impossible\n");
		}
	}
}
