#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> g[16];
int deg[16], m, n;
bool vis[16];
void dfs(int c) {
	vis[c] = true;
	for(int i = 0; i < g[c].size(); ++i)
		if(!vis[g[c][i]])
			dfs(g[c][i]);
}
bool isOK() {
	for(int i = 0; i < n; ++i)
		if(deg[i] != 2 || !vis[i])
			return false;
	return true;
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i)
			g[i].clear();
		memset(deg, 0, sizeof(deg));
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--v, --u;
			g[u].push_back(v);
			g[v].push_back(u);
			++deg[u], ++deg[v];
		}
		dfs(0);
		if(isOK())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
