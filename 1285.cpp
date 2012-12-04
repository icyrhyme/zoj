#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32
#define INF 1000000000
using namespace std;
class IDGen {
	int sz;
	int data[26 * 26];
public:
	IDGen() {
		sz = 0;
		memset(data, -1, sizeof(data));
	}
	int getId(char s[]) {
		int hash = (s[0] - 'A') * 26 + s[1] - 'A';
		if(data[hash] == -1) {
			data[hash] = sz;
			++sz;
		}
		return data[hash];
	}
};
class Graph {
	int n;
	int mat[MAXN][MAXN];
public:
	void init(int nn) {
		n = nn;
		for(int i = 0; i < n; ++i)
			fill(mat[i], mat[i] + n, INF);
	}
	void addEdge(int u, int v) {
		mat[u][v] = mat[v][u] = 1;
	}
	void floyd() {
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j) {
					if(mat[i][k] + mat[k][j] < mat[i][j])
						mat[i][j] = mat[i][k] + mat[k][j];
				}
		return;
	}
	int getDist(int u, int v) {
		return mat[u][v];
	}
};
#define MAXL 4
int main() {
	int cs, csnum = 1;
	scanf("%d", &cs);
	puts("SHIPPING ROUTES OUTPUT\n");
	while(cs--) {
		int m, n, p;
		char str[MAXL];
		IDGen ids;
		scanf("%d%d%d", &m, &n, &p);
		for(int i = 0; i < m; ++i) {
			scanf("%s", str);
			ids.getId(str);
		}
		Graph g;
		g.init(m);
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%s", str);
			u = ids.getId(str);
			scanf("%s", str);
			v = ids.getId(str);
			g.addEdge(u, v);
		}
		g.floyd();
		printf("DATA SET %d\n\n", csnum);
		csnum++;
		for(int i = 0; i < p; ++i) {
			int u, v, c, dist;
			scanf("%d", &c);
			scanf("%s", str);
			u = ids.getId(str);
			scanf("%s", str);
			v = ids.getId(str);
			dist = g.getDist(u, v);
			if(dist == INF) {
				printf("NO SHIPMENT POSSIBLE\n");
			}
			else
				printf("$%d\n", dist * c * 100);
		}
		putchar('\n');
	}
	printf("END OF OUTPUT\n");
	return 0;
}
