#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define MAXN 10086
#define V first
#define I second
#define MP make_pair
#define PB push_back
using namespace std;
int n, m, dep, low[MAXN], vis[MAXN];
vector<pair<int, int> > g[MAXN];
vector<int> ans;
void dfs(int u, int e) {
	vis[u] = 1;
	low[u] = dep;
	for(vector<pair<int, int> >::iterator it = g[u].begin(); it != g[u].end(); ++it) {
		if(!vis[it->V]) {
			++dep;
			dfs(it->V, it->I);
			--dep;
			if(low[it->V] > dep) {
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
}
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			g[i].clear();
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
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
			printf("%d%c", ans[i] + 1, i == ans.size() - 1 ? '\n' : ' ');
		}
		if(cas > 0)
			puts("");
	}
	return 0;
}

