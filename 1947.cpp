#include <cstdio>
#include <cstring>
#define MAXN 32
#define MAXE 32
using namespace std;
struct edge {
	int pn, nx;
	bool v;
	edge():v(false) {}
	edge(int pn, int nx, bool v): pn(pn), nx(nx), v(v) {}
};
int n, m, len;
int head[MAXN];
edge e[MAXE];
void dfs(int u, int lv) {
	if(lv > len)
		len = lv;
	for(int i = head[u]; i != -1; i = e[i].nx) {
		if(!e[i].v && !e[i ^ 1].v) {
			e[i ^ 1].v = e[i].v = true;
			dfs(e[i].pn, lv + 1);
			e[i ^ 1].v = e[i].v = false;
		}
	}
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0) {
		memset(head, -1, sizeof(int) * n);
		int u, v, cnt = 0;
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			e[cnt] = edge(v, head[u], false);
			head[u] = cnt++;
			e[cnt] = edge(u, head[v], false);
			head[v] = cnt++;
		}
		len = 0;
		for(int i = 0; i < n; ++i) {
			dfs(i, 0);
		}
		printf("%d\n", len);
	}
	return 0;
}
