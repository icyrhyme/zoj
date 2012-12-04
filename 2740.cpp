#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1024
using namespace std;
int n, m;
vector<int> e[MAXN];
bool vis[MAXN];
int dfs(int u) {
	int ret = 0;
	if(!vis[u]) {
		vis[u] = true;
		ret = 1;
		vector<int>::iterator it;
		for(it = e[u].begin(); it != e[u].end(); ++it) {
			ret += dfs(*it);
		}
	}
	return ret;
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; ++i) {
			e[i].clear();
		}
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(m != n - 1) {
			printf("No\n");
			continue;
		}
		fill(vis, vis + n, false);
		int sz = dfs(0);
		if(sz == n) {
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}
