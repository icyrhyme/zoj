#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <set>
#define eps 1e-8
#define MAXN 2048
using namespace std;
const double EPS = 1e-8;

struct Point {
	double x, y;
	bool operator<(const Point& o)const
	{
		if(x != o.x)
			return x < o.x;
		else
			return y < o.y;
	}
};

inline bool zero(double x) {
	return ((x > 0 ? x : -x) < EPS);
}

//ÆËãcross product (P1 - P0)x(P2 - P0)
inline double xmult(const Point & p1, const Point & p2, const Point & p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int cmp(const void * a, const void * b) {
	Point *p1 = (Point *) a, *p2 = (Point *)b;
	return zero(p1->y - p2->y) ? (p1->x > p2->x + EPS ? 1 : -1) : (p1->y > p2->y + EPS ? 1 : -1);
}

int graham(int n, Point p[], Point ch[], bool flag[], bool maxsize = false) {
	const double e1 = maxsize ? EPS : -EPS;
	int i, j, k;
	if (n < 3) {
		for(i = 0; i < n; i++) {
			ch[i]=p[i];
		}
		return n;
	}
	qsort(p, n, sizeof(p[0]), cmp);
	ch[0] = p[0];
	ch[1] = p[1];
	flag [0] = true;
	flag [1] = true;
	for (i = j = 2; i < n; ch[j++] = p[i], flag[i++] = true) {
		while (j > 1 && xmult(ch[j - 2], p[i], ch[j - 1]) > e1) {
			j--;
		}
	}
	ch[k = j++] = p[n - 2];
	flag[n - 2] = true;
	for (i = n - 3; i > 0; ch[j++] = p[i], flag[i--] = true) {
		while (j > k && xmult(ch[j - 2], p[i], ch[j - 1]) > e1) {
			j--;
		}
	}
	while (j > k && xmult(ch[j - 2], ch[0], ch[j - 1]) > e1) {
		j--;
	}
	return j;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		Point pa[MAXN];
		Point convex[MAXN];
		bool flag[MAXN];
		for(int i = 0; i < n; ++i)
		{
			int tmpx, tmpy;
			scanf("%d%d", &tmpx, &tmpy);
			pa[i].x = (double)tmpx;
			pa[i].y = (double)tmpy;
		}
		int pcnt = n, ccnt = 0;
		while(pcnt >= 3)
		{
			memset(flag, false, sizeof(flag));
			int covcnt = graham(pcnt, pa, convex, flag);
			set<Point> s;
			for(int i = 0; i < covcnt; ++i)
				s.insert(convex[i]);
			Point temp[MAXN];
			for(int i = 0, j = 0; i < pcnt; ++i)
				if(s.find(pa[i]) == s.end())
					temp[j++] = pa[i];
			pcnt -= covcnt;
			for(int i = 0; i < pcnt; ++i)
				pa[i] = temp[i];
			ccnt++;
		}
		printf("%d\n", ccnt);
	}
	return 0;
}
