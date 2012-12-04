const int MAXN = 60010;
const int MAXM = 200010;
const int INF = 2147483647;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef int T;

class Edge {
public:
	int pnt, nxt;
	
	T cap;
	
	Edge() {}
	
	Edge(int pnt, int nxt, T cap): pnt(pnt), nxt(nxt), cap(cap)  {}
};

class Dinic {
public:
	int N, M, source, sink, start[MAXN];
	
	T value[MAXN];
	
	bool mark[MAXN];
	
	Edge edge[MAXM << 1];
	
	inline void init(int s, int t, int n) {
		N = n;
		M = 0;
		source = s;
		sink = t;
		memset(start, 0xFF, sizeof(int) * N);
	}
	
	inline void addEdge(int x, int y, T z) {
//		printf("%d %d %d\n", x, y, z);
		edge[M] = Edge(y, start[x], z);
		start[x] = M++;
		edge[M] = Edge(x, start[y], 0);
		start[y] = M++;
	}
	
	int level[MAXN];
	
	inline void BFS() {
		int open, closed, L[MAXN];
		memset(level, 0xFF, sizeof(int) * N);
		level[source] = 0;
		L[0] = source;
		open = -1;
		closed = 0;
		int now;
		while (open < closed && level[sink] == -1) {
			now = L[++open];
			int i = start[now];
			while (i != -1) {
				if (edge[i].cap && level[edge[i].pnt] == -1) {
					level[edge[i].pnt] = level[now] + 1;
					L[++closed] = edge[i].pnt;
				}
				i = edge[i].nxt;
			}
		}
	}
	
	int startnow[MAXN];
	
	T maxflow() {
		int last[MAXN];
		T ret = 0, delta;
		while (true) {
			BFS();
			if (level[sink] == -1) break;
			memset(value, 0, sizeof(int) * N);
			value[source] = INF;
			for (int i = 0; i < N; i++) mark[i] = true;
			memcpy(startnow, start, sizeof(int) * N);
			int now = source;
			while (true) {
				int i = startnow[now];
				while (i != -1) {
					if (edge[i].cap && level[now] + 1 == level[edge[i].pnt] && mark[edge[i].pnt]) {
						last[edge[i].pnt] = i;
						value[edge[i].pnt] = min(edge[i].cap, value[now]);
						startnow[now] = i;
						now = edge[i].pnt;
						break;
					}
					i = edge[i].nxt;
				}
				if (i == -1) {
					mark[now] = false;
					if (now == source) break;
					now = edge[last[now] ^ 1].pnt;
				} else if (now == sink) {
					delta = value[sink];
					ret += delta;
					int i = sink, tmp;
					while (i != source) {
						value[i] -= delta;
						edge[last[i]].cap -= delta;
						tmp = last[i] ^ 1;
						if (value[i] == 0) now = edge[tmp].pnt;
						edge[tmp].cap += delta;
						i = edge[tmp].pnt;
					}
				}
			}
		}
		return ret;
	}
} dinic;

#define MAXR 256
#define MAXC 32
#define INF 0x7fffffff
int n, m;
int rsum[MAXR], csum[MAXC];
int lower[MAXR][MAXC], upper[MAXR][MAXC];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		int rtot = 0, ctot = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &rsum[i]);
			rtot += rsum[i];
		}
		for(int i = 0; i < m; ++i) {
			scanf("%d", &csum[i]);
			ctot += csum[i];
		}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				lower[i][j] = 0;
				upper[i][j] = INF;
			}
		int c;
		scanf("%d", &c);
		for(int k = 0; k < c; ++k) {
			char op[2];
			int x, y, val;
			scanf("%d%d%s%d", &x, &y, op, &val);
			assert(val < 1000000000);
			int xmin = x - 1, xmax = x - 1;
			int ymin = y - 1, ymax = y - 1;
			if(x == 0) {
				xmin = 0;
				xmax = n - 1;
			}
			if(y == 0) {
				ymin = 0;
				ymax = m - 1;
			}
			for(int i = xmin; i <= xmax; ++i)
				for(int j = ymin; j <= ymax; ++j) {
					switch(op[0]) {
						case '>':
							lower[i][j] = max(lower[i][j], val + 1);
							break;
						case '<':
							upper[i][j] = min(upper[i][j], val - 1);
							break;
						case '=':
							upper[i][j] = min(upper[i][j], val);
							lower[i][j] = max(lower[i][j], val);
							break;
					}
				}
		}
		bool flag = false;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if(lower[i][j] > upper[i][j])
					flag = true;
			}
		if(rtot != ctot || flag) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		dinic.init(0, n + m + 1, n + m + 2);
		flag = false;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				rsum[i] -= lower[i][j];
				csum[j] -= lower[i][j];
				if(rsum[i] < 0 || csum[j] < 0)
					flag = true;
				dinic.addEdge(i + 1, n + j + 1, upper[i][j] - lower[i][j]);
			}
		int tot = 0;
		for(int i = 0; i < n; ++i) {
			tot += rsum[i];
			dinic.addEdge(0, i + 1, rsum[i]);
		}
		for(int j = 0; j < m; ++j)
			dinic.addEdge(n + j + 1, n + m + 1, csum[j]);
		int flow = dinic.maxflow();
		int ans[MAXR][MAXC];
		for(int i = 1; i <= n; ++i) {
			int j = dinic.start[i];
			while(j != -1) {
//				printf("(%d %d) ", dinic.edge[j].pnt, dinic.edge[j].cap);
				if(dinic.edge[j].pnt > 1) {
					int v = dinic.edge[j].pnt - n - 1;
					ans[i - 1][v] = upper[i - 1][v] - dinic.edge[j].cap;
//					printf("%d %d\n", i - 1, v);
				}
				j = dinic.edge[j].nxt;
			}
//			printf("\n");
		}
		flag = false;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if(ans[i][j] >= lower[i][j] && ans[i][j] <= upper[i][j])
					;
				else
					flag = true;
			}
		if(flow != tot || flag)
			printf("IMPOSSIBLE\n");
		else
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < m; ++j) {
					printf("%d", ans[i][j]);
					if(j == m - 1)
						putchar('\n');
					else
						putchar(' ');
				}
		if(T != 0)
			printf("\n");
	}
	return 0;
}
