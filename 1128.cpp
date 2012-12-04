#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000
using namespace std;
struct rect
{
	double x1, y1, x2, y2;
};
struct rects
{
	int sz;
	rect ra[MAXN];
	void init()
	{
		sz = 0;
	}
	void del(int idx)
	{
		ra[idx] = ra[--sz];
	}
	void add(double x1, double y1, double x2, double y2)
	{
		ra[sz].x1 = x1;
		ra[sz].y1 = y1;
		ra[sz].x2 = x2;
		ra[sz].y2 = y2;
		++sz;
	}
	void cut(int idx, double x1, double y1, double x2, double y2)
	{
		rect r = ra[idx];
		if(x1 >= r.x2 || x2 <= r.x1 || y1 >= r.y2 || y2 <= r.y1)
			return;
		double k1 = max(x1, r.x1), k2 = min(x2, r.x2);
		if(k1 > r.x1)
			add(r.x1, r.y1, k1, r.y2);
		if(k2 < r.x2)
			add(k2, r.y1, r.x2, r.y2);
		double k3 = max(y1, r.y1), k4 = min(y2, r.y2);
		if(k3 > r.y1)
			add(k1, r.y1, k2, k3);
		if(k4 < r.y2)
			add(k1, k4, k2, r.y2);
		del(idx);
	}
	void add_ol(double x1, double y1, double x2, double y2)
	{
		for(int i = 0; i < sz; ++i)
			cut(i, x1, y1, x2, y2);
		add(x1, y1, x2, y2);
	}
	double getAns()
	{
		double ans = 0;
		for(int i = 0; i < sz; ++i)
			ans += (ra[i].x2 - ra[i].x1) * (ra[i].y2 - ra[i].y1);
		return ans;
	}
	void print()
	{
		for(int i = 0; i < sz; ++i)
			printf("%lf %lf %lf %lf\n", ra[i].x1, ra[i].y1, ra[i].x2, ra[i].y2);
	}
};
int main()
{
	int n, cs = 1;
	rects rs;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		rs.init();
		for(int i = 0; i < n; ++i)
		{
			double x1, y1, x2, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			if(x1 > x2)
				swap(x1, x2);
			if(y1 > y2)
				swap(y1, y2);
			rs.add_ol(x1, y1, x2, y2);
		}
//		rs.print();
		printf("Test case #%d\n", cs++);
		printf("Total explored area: %.2lf\n\n", rs.getAns());
	}
	return 0;
}
