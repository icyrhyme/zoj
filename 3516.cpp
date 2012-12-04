#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 10005
using namespace std;
vector<int> e[MAXN];
int v[MAXN][3];
void gao(int u) {
	int temp[6];
	for(vector<int>::iterator i = e[u].begin(); i != e[u].end(); ++i) {
		gao(*i);
		merge(v[u], v[u] + 3, v[*i], v[*i] + 3, temp);
		copy(temp + 3, temp + 6, v[u]);
	}
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			e[i].clear();
			fill(v[i], v[i] + 3, -1);
		}
		for(int i = 0; i < n; ++i) {
			if(i != 0) {
				int p;
				scanf("%d", &p);
				e[p].push_back(i);
			}
			scanf("%d", &v[i][2]);
		}
		gao(0);
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			int u;
			scanf("%d", &u);
			if(v[u][0] == -1)
				printf("-1\n");
			else
				printf("%d %d %d\n", v[u][2], v[u][1], v[u][0]);
		}
	}
	return 0;
}
