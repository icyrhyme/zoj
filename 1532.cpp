#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 128
#define MAXE 1280
#define INF 0x7fffffff
using namespace std;
int m, n, l;
class Dinic {
	struct edge {
		int u, v, f, c, nx;
		edge() {}
		edge(int u, int v, int f, int c, int nx): u(u), v(v), f(f), c(c), nx(nx) {}
	} e[MAXE];
	int n, m, src, dst, head[MAXN], work[MAXN], d[MAXN];
	bool _bfs() {
		static int q[MAXN], le, ri;
		le = ri = 0;
		memset(d, -1, sizeof(int) * n);
		q[ri++] = src;
		d[src] = 0;
		while(le < ri) {
			for(int k = q[le++], i = head[k]; i != -1; i = e[i].nx) {
				if(e[i].f < e[i].c && d[e[i].v] == -1) {
					d[e[i].v] = d[k] + 1;
					q[ri++] = e[i].v;
				}
			}
		}
		return (d[dst] != -1);
	}
	int _dfs(int u, int f) {
		if(u == dst)
			return f;
		int minf;
		for(int& i = work[u]; i != -1; i = e[i].nx) {
			if(e[i].f < e[i].c && d[e[i].v] == d[u] + 1) {
				minf = _dfs(e[i].v, min(f, e[i].c - e[i].f));
				if(minf > 0) {
					e[i].f += minf;
					e[i ^ 1].f -= minf;
					return minf;
				}
			}
		}
		return 0;
	}
	void _rdfs(int u) {
		if(d[u] == -1) {
			d[u] = 1;
			for(int i = head[u]; i != -1; i = e[i].nx) {
				if(e[i ^ 1].f < e[i ^ i].c) {
					_rdfs(e[i].v);
				}
			}
		}
	}
public:
	void init(int n, int src, int dst) {
		this->n = n;
		this->src = src;
		this->dst = dst;
		m = 0;
		memset(head, -1, sizeof(int) * n);
	}
	void addEdge(int u, int v, int c) {
		//printf("%d %d %d\n", u, v, c);
		e[m] = edge(u, v, 0, c, head[u]);
		head[u] = m++;
		e[m] = edge(v, u, 0, 0, head[v]);
		head[v] = m++;
	}
	int maxFlow() {
		int ret = 0, delta;
		while(_bfs()) {
			memcpy(work, head, sizeof(int) * n);
			while(true) {
				delta = _dfs(src, INF);
				if(delta == 0)
					break;
				ret += delta;
			}
		}
		for(int i = 0; i < n; ++i)
			if(d[i] >= 0)
				d[i] = 0;
		_rdfs(dst);
		vector<int> ans;
		for(int i = 0; i < 2 * l; i += 2) {
			if(d[e[i].u] == 0 && d[e[i].v] == 1)
				ans.push_back(i >> 1);
		}
		for(int i = 0; i < ans.size(); ++i) {
			printf("%d%c", ans[i] + 1, (i == ans.size() - 1 ? '\n' : ' '));
		}
		if(ans.size() == 0)
			putchar('\n');
		return ret;
	}
} dinic;
int main() {
	while(scanf("%d%d%d", &n, &m, &l) != EOF) {
		if(n == 0)
			break;
		dinic.init(n + m + 2, n + m + 1, 0);
		for(int i = 0; i < l; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			dinic.addEdge(u, v, c);
		}
		for(int i = 1; i <= n; ++i) {
			dinic.addEdge(n + m + 1, i, INF);
		}
		dinic.maxFlow();
	}
	return 0;
}
