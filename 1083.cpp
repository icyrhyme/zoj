#include <iostream>
#define MAXN 32
using namespace std;
class Bimap {
	int ctoi[32];
	int itoc[32];
	int sz;
public:
	void init() {
		sz = 0;
		fill(ctoi, ctoi + 32, -1);
		fill(itoc, itoc + 32, -1);
	}
	int size() {
		return sz;
	}
	int getId(char c) {
		if(ctoi[c - 'A'] == -1) {
			ctoi[c - 'A'] = sz;
			itoc[sz] = c - 'A';
			++sz;
		}
		return ctoi[c - 'A'];
	}
	char getElem(int id) {
		return itoc[id] + 'A';
	}
};
class TopologicalSorter {
	int n;
	bool g[MAXN][MAXN];
	int ideg[MAXN];
public:
	void init(int nn) {
		n = nn;
		fill(ideg, ideg + n, 0);
		for(int i = 0; i < n; ++i)
			fill(g[i], g[i] + n, false);
	}
	void addEdge(int u, int v) {
		if(!g[u][v]) {
			g[u][v] = true;
			++ideg[v];
		}
	}
};
int main() {
	int h, w;
	char mm[MAXN][MAXN];
	while(scanf("%d%d", &h, &w) != EOF) {
		Bimap ids;
		for(int i = 0; i < h; ++i) {
			scanf("%s", mm[i]);
			for(int j = 0; j < w; ++j)
				if(mm[i][j] != '.')
					ids.getId(mm[i][j]);
		}
		TopologicalSorter ts;
		ts.init(ids.size());
		for(int i = 0; i < ids.size(); ++i) {
			char c = ids.getElem(i);
			int minx = INF, maxx = -1, miny = INF, maxy = -1;
			for(int j = 0; j < h; ++j)
				for(int k = 0; k < w; ++k) {
					if(mm[j][k] == c) {
						minx = min(minx, j);
						maxx = max(maxx, j);
						miny = min(miny, k);
						maxy = max(maxy, k);
					}
				}
			for(int j = minx; j <= maxx; ++j) {
				if(mm[j][miny] != c)
					ts.addEdge(ids.getId(mm[j][miny]), i);
				if(mm[j][maxy] != c)
					ts.addEdge(ids.getId(mm[j][maxy]), i);
			}
			for(int j = miny; j <= maxy; ++j) {
				if(mm[minx][j] != c)
					ts.addEdge(ids.getId(mm[minx][j]), i);
				if(mm[maxx][j] != c)
					ts.addEdge(ids.getId(mm[maxx][j]), j);
			}
		}
	}
	return 0;
}
