#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10005
#define MAXC 128
using namespace std;
struct Rect
{
	int x1, y1, x2, y2, c;
};
struct Rects
{
	int sz;
	Rect ra[MAXN];
	void init()
	{
		sz = 0;
	}
	void _add(int x1, int y1, int x2, int y2, int c)
	{
		ra[sz].x1 = x1;
		ra[sz].x2 = x2;
		ra[sz].y1 = y1;
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
	void add(int x1, int y1, int x2, int y2, int c) 
	{
		for(int i = 0; i < sz; ++i)
			cut(i, x1, y1, x2, y2, c);
		_add(x1, y1, x2, y2, c);
	}
};
int main()
{
	int H, W, cs = 1;
	Rects rs;
	while(scanf("%d%d", &H, &W) != EOF)
	{
		if(H == 0 && W == 0)
			break;
		int n;
		scanf("%d", &n);
		rs.init();
		for(int i = 0; i < n; ++i)
		{
			int x1, y1, x2, y2, c;
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
			rs.add(x1, y1, x2, y2, c);
		}
		int area[MAXC];
		memset(area, 0, sizeof(area));
		for(int i = 0; i < rs.sz; ++i)
		{
			Rect r = rs.ra[i];
			area[r.c] += (r.x2 - r.x1) * (r.y2 - r.y1);
		}
		if(cs != 1)
			printf("\n");
		printf("Case %d:\n", cs++);
		int cnt = 0;
		for(int i = 0; i < MAXC; ++i)
			if(area[i])
			{
				printf("%d %d\n", i, area[i]);
				++cnt;
			}
		if(cnt > 1)
			printf("There are %d colors left on the wall.\n", cnt);
		else
			printf("There is 1 color left on the wall.\n");
	}
	return 0;
}
