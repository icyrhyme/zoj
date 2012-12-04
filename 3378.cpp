#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define PB push_back
#define V first
#define I second
#define MAXN 10086
using namespace std;
int n, m, low[MAXN], vis[MAXN], dep;
vector<pair<int, int> > g[MAXN];
vector<int> ans;
int dfs(int u, int e) {
	vis[u] = 1;
	low[u] = dep;
	vector<pair<int, int> >::iterator it;
	int ret = 0;
	for(it = g[u].begin(); it != g[u].end(); ++it) {
		if(!vis[it->V]) {
			++dep;
			int flag = dfs(it->V, it->I);
			ret |= flag;
			--dep;
			if(low[it->V] > dep && flag) {
				ans.PB(it->I);
			}
			if(low[it->V] < low[u]) {
				low[u] = low[it->V];
			}
		}
		else if(it->I != e && low[it->V] < low[u]) {
			low[u] = low[it->V];
		}
	}
	return (ret || (u == n - 1));
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i)
			g[i].clear();
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(u == v)
				continue;
			g[u].PB(MP(v, i));
			g[v].PB(MP(u, i));
		}
		memset(vis, 0, sizeof(int) * n);
		ans.clear();
		dep = 0;
		dfs(0, -1);
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); ++i) {
			printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
		}
		if(ans.size() == 0)
			puts("");
	}
	return 0;
}
