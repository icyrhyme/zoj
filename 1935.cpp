#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 128
#define INF 1000000000
using namespace std;
int main() {
	int n;
	vector<int> e[MAXN];
	int w[MAXN];
	while(scanf("%d", &n) != EOF) {
		if(n == -1)
			break;
		for(int i = 0; i < n; ++i) {
			e[i].clear();
			int k;
			scanf("%d", &w[i]);
			w[i] = -w[i];
			scanf("%d", &k);
			for(int j = 0; j < k; ++j) {
				int v;
				scanf("%d", &v);
				--v;
				e[i].push_back(v);
			}
		}
		int d[MAXN], cnt[MAXN];
		bool inq[MAXN];
		queue<int> q;
		vector<int>::iterator it;
		fill(d, d + n, INF);
		fill(cnt, cnt + n, 0);
		fill(inq, inq + n, false);
		d[0] = -100;
		q.push(0);
		++cnt[0];
		inq[0] = true;
		bool haveCircle = false;
		int u;
		while(!q.empty()) {
			u = q.front();
			q.pop();
			inq[u] = false;
			if(cnt[u] == n) {
				haveCircle = true;
				break;
			}
			for(it = e[u].begin(); it != e[u].end(); ++it) {
				if(d[u] + w[*it] < d[*it]) {
					d[*it] = d[u] + w[*it];
					//printf("%d->%d: %d+%d<%d\n", u, *it, d[u], w[*it], d[*it]);
					if(!inq[*it] && d[*it] < 0) {
						q.push(*it);
						inq[*it] = true;
						++cnt[*it];
					}
				}
			}
		}
		if(haveCircle) {
			while(!q.empty())
				q.pop();
			d[u] = -INF;
			q.push(u);
			while(!q.empty()) {
				u = q.front();
				q.pop();
				for(it = e[u].begin(); it != e[u].end(); ++it) {
					if(d[*it] != -INF) {
						d[*it] = -INF;
						q.push(*it);
					}
				}
			}
		}
		if(d[n - 1] < 0)
			printf("winnable\n");
		else
			printf("hopeless\n");
	}
	return 0;
}
