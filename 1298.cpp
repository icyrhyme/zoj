#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#define MAXN 512
#define INF 1e100
using namespace std;
class Dijkstra {
	struct edge {
		int v;
		double w;
	};
	edge _makeEdge(int vv, double ww) {
		edge tmp;
		tmp.v = vv;
		tmp.w = ww;
		return tmp;
	}
	int n;
	vector<edge> e[MAXN];
public:
	double d[MAXN];
	int pre[MAXN];
	void init(int nn) {
		n = nn;
		for(int i = 0; i < n; ++i)
			e[i].clear();
	}
	void addEdge(int u, int v, double w) {
		e[u].push_back(_makeEdge(v, w));
	}
	void shortestPaths(int s) {
		bool vis[MAXN];
		fill(d, d + n, INF);
		fill(pre, pre + n, -1);
		fill(vis, vis + n, false);
		d[s] = 0;
		for(int i = 0; i < n; ++i) {
			double mind = INF;
			int mini = -1;
			for(int j = 0; j < n; ++j) {
				if(!vis[j] && d[j] < mind) {
					mind = d[j];
					mini = j;
				}
			}
			vis[mini] = true;
			vector<edge>::iterator it;
			for(it = e[mini].begin(); it != e[mini].end(); ++it) {
				if(d[mini] + it->w < d[it->v]) {
					d[it->v] = d[mini] + it->w;
					pre[it->v] = mini;
				}
			}
		}
		//for(int i = 0; i < n; ++i)
		//	printf("%lf%c", d[i], (i == n - 1 ? '\n' : ' '));
	}
	double solve(pair<int, int>& p) {
		double maxt = -1;
		for(int i = 0; i < n; ++i) {
			assert(d[i] >= 0);
			if(d[i] > maxt) {
				maxt = d[i];
				p.first = i;
				p.second = -1;
			}
		}
		for(int i = 0; i < n; ++i) {
			vector<edge>::iterator it;
			for(it = e[i].begin(); it != e[i].end(); ++it) {
				int u = i, v = it->v, w = it->w;
				if(d[u] > d[v])
					swap(u, v);
				if(pre[u] != v && pre[v] != u) {
					double thist = d[u] + (w - (d[u] - d[v])) / 2.0;
					if(thist > maxt) {
						maxt = thist; 
						p.first = u;
						p.second = v;
						if(u > v)
							swap(p.first, p.second);
					}
				}
			}
		}
		return maxt;
	}
};
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		assert(n < 512);
		Dijkstra di;
		di.init(n);
		for(int i = 0; i < m; ++i) {
			int u, v;
			double w;
			scanf("%d%d%lf", &u, &v, &w);
			--u, --v;
			di.addEdge(u, v, w);
		}
		di.shortestPaths(0);
		printf("System #%d\n", csnum);
		++csnum;
		pair<int, int> p;
		double t = di.solve(p);
		printf("The last domino falls after %.1lf seconds, ", t);
		if(p.second == -1) {
			printf("at key domino %d.\n", p.first + 1);
		}
		else {
			printf("between key dominoes %d and %d.\n", p.first + 1, p.second + 1);
		}
		putchar('\n');
	}
	return 0;
}
