#include <iostream>
#define MAXV 128
using namespace std;
int V, E, match[MAXV];
bool g[MAXV][MAXV], vis[MAXV];
//find a augmenting path
int havePath(int c)
{
	int j;
	for(j = 0; j < V; ++j)
		if(g[c][j] && !vis[j])
		{
			vis[j] = true;
			if(match[j] == -1 || havePath(match[j]))
			{
				match[j] = c;
				return 1;
			}
		}
	return 0;
}
int maxMatch()
{
	int cnt = 0;
	memset(match, -1, sizeof(match));
	for(int i = 0; i < V; ++i)
	{
		memset(vis, false, sizeof(vis));
		cnt += havePath(i);
	}
	return cnt;
}
int main()
{
	int cs;
	scanf("%d", &cs);
	while(cs--)
	{
		memset(g, false, sizeof(g));
		scanf("%d%d", &V, &E);
		for(int i = 0; i < E; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			g[u][v] = true;
		}
		printf("%d\n", V - maxMatch());
	}
	return 0;
}
