#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7fffffff
#define MAXN 256
#define MAXM 100005
using namespace std;
class Dinic {
	int n, m, src, dst, head[MAXN], d[MAXN], work[MAXN];
	struct edge {
		int v, f, c, nxt;
		edge() {}
		edge(int v, int f, int c, int nxt): v(v), f(f), c(c), nxt(nxt) {
		}
	} e[MAXM];
	bool _bfs() {
		static int q[MAXN], le, ri;
		le = ri = 0;
		memset(d, -1, sizeof(int) * n);
		q[ri++] = src;
		d[src] = 0;
		while(le < ri) {
			for(int k = q[le++], i = head[k]; i >= 0; i = e[i].nxt) {
				if(e[i].f < e[i].c && d[e[i].v] < 0) {
					d[e[i].v] = d[k] + 1;
					q[ri++] = e[i].v;
				}
			}
		}
		return (d[dst] >= 0);
	}
	int _dfs(int u, int f) {
		if(u == dst)
			return f;
		for(int& i = work[u]; i >= 0; i = e[i].nxt) {
			if(e[i].f < e[i].c && d[u] + 1 == d[e[i].v]) {
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
		memset(head, -1, sizeof(head));
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
	int getFlow(int idx) {
		return e[2 * idx].f;
	}
} dinic;
int main() {
	int cs;
	int n, m, d[MAXN], b[MAXM];
	scanf("%d", &cs);
	while(cs--) {
		scanf("%d%d", &n, &m);
		dinic.init(n + 2, n, n + 1);
		fill(d, d + n, 0);
		for(int i = 0; i < m; ++i) {
			int u, v, c;
			scanf("%d%d%d%d", &u, &v, &b[i], &c);
			--u, --v;
			d[u] += b[i];
			d[v] -= b[i];
			dinic.addEdge(u, v, c - b[i], 0);
		}
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			if(d[i] > 0) {
				dinic.addEdge(i, n + 1, d[i], 0);
				sum += d[i];
			}
			else if(d[i] < 0)
				dinic.addEdge(n, i, -d[i], 0);
		}
		int ret = dinic.maxFlow();
		if(ret != sum) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
			for(int i = 0; i < m; ++i)
				printf("%d\n", b[i] + dinic.getFlow(i));
		}
		if(cs != 0)
			putchar('\n');
	}
}
