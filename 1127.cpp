#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define MAXN 32
using namespace std;
int main() {
	int n, m;
	char tmp[2];
	while(scanf("%d%s%d", &n, tmp, &m) != EOF) {
		vector<int> ord;
		ord.push_back(tmp[0] - 'A');
		vector<int> e[MAXN];
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%s", tmp);
			u = tmp[0] - 'A';
			scanf("%s", tmp);
			v = tmp[0] - 'A';
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i = 0; i < m - 1; ++i) {
			queue<int> q;
			int dis[MAXN];
			fill(dis, dis + n, -1);
			for(int j = 0; j < ord.size(); ++j) {
				q.push(ord[j]);
				dis[ord[j]] = 0;
			}
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				vector<int>::iterator vit;
				for(vit = e[u].begin(); vit != e[u].end(); ++vit) {
					if(dis[*vit] == -1) {
						dis[*vit] = dis[u] + 1;
						q.push(*vit);
					}
				}
			}
			int far = 0;
			for(int j = 1; j < n; ++j)
				if(dis[j] > dis[far])
					far = j;
			ord.push_back(far);
		}
		puts("Program 8 by team X");
		for(int i = 0; i < ord.size(); ++i)
			printf("%c%c", ord[i] + 'A', (i == ord.size() - 1 ? '\n' : ' '));
		puts("End of program 8 by team X");
	}
}
