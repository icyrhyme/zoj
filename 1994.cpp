#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 256
#define MAXE 15000
#define MAXR 256
#define MAXC 32
#define INF 1000000000
using namespace std;
class NetworkFlow {
	int n, m, src, dst, head[MAXN], work[MAXN], d[MAXN], base[MAXN];
	struct edge {
		int v, f, b, c, nx;
		edge() {}
		edge(int v, int f, int b, int c, int nx): v(v), f(f), b(b), c(c), nx(nx) {}
	} e[MAXE];
	bool _bfs() {
		int q[MAXN], le, ri;
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
		int thisf;
		for(int& i = work[u]; i != -1; i = e[i].nx) {
			if(e[i].f < e[i].c && d[e[i].v] == d[u] + 1) {
				thisf = _dfs(e[i].v, min(f, e[i].c - e[i].f));
				if(thisf > 0) {
					e[i].f += thisf;
					e[i ^ 1].f -= thisf;
					return thisf;
				}
			}
		}
		return 0;
	}
public:
	void init(int n) {
		this->n = n + 2;
		this->src = n;
		this->dst = n + 1;
		m = 0;
		memset(head, -1, sizeof(int) * this->n);
		memset(base, 0, sizeof(int) * this->n);
	}
	void addEdge(int u, int v, int b, int c) {
		e[m] = edge(v, 0, b, c - b, head[u]);
		head[u] = m++;
		e[m] = edge(u, 0, 0, 0, head[v]);
		head[v] = m++;
		base[u] += b;
		base[v] -= b;
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
	bool feasibleFlow() {
		int fullFlow = 0;
		for(int i = 0; i < n - 2; ++i) {
			if(base[i] > 0) {
				addEdge(i, dst, 0, base[i]);
				fullFlow += base[i];
			}
			else if(base[i] < 0)
				addEdge(src, i, 0, -base[i]);
		}
		int ret = maxFlow();
		//printf("%d %d\n", ret, fullFlow);
		if(ret == fullFlow)
			return true;
		else
			return false;
	}
	int getFlow(int eid) {
		return e[eid * 2].b + e[eid * 2].f;
	}
} fn;
int main() {
	int cs, csnum = 1;
	int n, m;
	int rsum[MAXR], csum[MAXC];
	int lower[MAXR][MAXC], upper[MAXR][MAXC];
	scanf("%d", &cs);
	while(cs--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) {
			fill(lower[i], lower[i] + m, 0);
			fill(upper[i], upper[i] + m, INF);
			scanf("%d", &rsum[i]);
		}
		for(int j = 0; j < m; ++j)
			scanf("%d", &csum[j]);
		int cn, row, col, val, ibase, ilim, jbase, jlim;
		char ch;
		scanf("%d", &cn);
		bool isok = true;
		for(int k = 0; k < cn; ++k) {
			scanf("%d %d %c %d", &row, &col, &ch, &val);
			if(row == 0) {
				ibase = 0;
				ilim = n - 1;
			}
			else
				ibase = ilim = row - 1;
			if(col == 0) {
				jbase = 0;
				jlim = m - 1;
			}
			else
				jbase = jlim = col - 1;
			for(int i = ibase; i <= ilim; ++i)
				for(int j = jbase; j <= jlim; ++j) {
					switch(ch) {
						case '<': upper[i][j] = min(upper[i][j], val - 1); break;
						case '>': lower[i][j] = max(lower[i][j], val + 1); break;
						case '=':
							  upper[i][j] = min(upper[i][j], val);
							  lower[i][j] = max(lower[i][j], val);
							  break;
					}
					if(lower[i][j] > upper[i][j])
						isok = false;
				}
		}
		if(csnum > 1)
			putchar('\n');
		if(!isok) {
			printf("IMPOSSIBLE\n");
			++csnum;
			continue;
		}
		fn.init(n + m + 2);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				fn.addEdge(i, n + j, lower[i][j], upper[i][j]);
			}
		for(int i = 0; i < n; ++i)
			fn.addEdge(n + m, i, rsum[i], rsum[i]);
		for(int j = 0; j < m; ++j)
			fn.addEdge(n + j, n + m + 1, csum[j], csum[j]);
		fn.addEdge(n + m + 1, n + m, 0, INF);
		if(fn.feasibleFlow()) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j)
					printf("%d%c", fn.getFlow(i * m + j), j == m - 1 ? '\n' : ' ');
			}
		}
		else {
			printf("IMPOSSIBLE\n");
		}
		++csnum;
	}
	return 0;
}
