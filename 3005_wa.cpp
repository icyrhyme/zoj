#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 512
using namespace std;
struct Rect
{
	int x1, y1, x2, y2, c;
};
struct Rects
{
	int sz, ccnt, dcnt[MAXN];
	Rect ra[MAXN * MAXN];
	bool g[MAXN][MAXN];
	void init()
	{
		ccnt = sz = 0;
		memset(g, false, sizeof(g));
		memset(dcnt, 0, sizeof(dcnt));
	}
	void _add(int x1, int y1, int x2, int y2, int c)
	{
		ra[sz].x1 = x1;
		ra[sz].y1 = y1;
		ra[sz].x2 = x2;
		ra[sz].y2 = y2;
		ra[sz].c = c;
		++sz;
	}
	void del(int idx)
	{
		ra[idx] = ra[--sz];
	}
	void cut(int idx, int x1, int y1, int x2, int y2, int c)
	{
		Rect r = ra[idx];
		if(x1 >= r.x2 || x2 <= r.x1 || y1 >= r.y2 || y2 <= r.y1)
			return;
		if(!g[r.c][c])
		{
			g[r.c][c] = true;
			++dcnt[r.c];
		}
		int k1, k2, k3, k4;
		k1 = max(x1, r.x1), k2 = min(x2, r.x2);
		if(k1 > r.x1)
			_add(r.x1, r.y1, k1, r.y2, r.c);
		if(k2 < r.x2)
			_add(k2, r.y1, r.x2, r.y2, r.c);
		k3 = max(y1, r.y1), k4 = min(y2, r.y2);
		if(k3 > r.y1)
			_add(k1, r.y1, k2, k3, r.c);
		if(k4 < r.y2)
			_add(k1, k4, k2, r.y2, r.c);
		del(idx);
	}
	void add(int x1, int y1, int x2, int y2)
	{
		for(int i = 0; i < sz; ++i)
			cut(i, x1, y1, x2, y2, ccnt);
		_add(x1, y1, x2, y2, ccnt);
		++ccnt;
	}
	void findDefeat(int c)
	{
		printf("%d", dcnt[c]);
		for(int i = 0; dcnt[c] && i < ccnt; ++i)
			if(g[c][i])
				printf(" %d", i + 1);
		printf("\n");
	}
};

int main()
{
	int n, m;
	Rects rs;
	while(scanf("%d", &n) != EOF)
	{
		rs.init();
		for(int i = 0; i < n; ++i)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			rs.add(x1, y1, x2, y2);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
		{
			int c;
			scanf("%d", &c);
			rs.findDefeat(c - 1);
		}
		printf("\n");
	}
	return 0;
}
