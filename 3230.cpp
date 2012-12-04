#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>
#define MAXN 100005
using namespace std;
struct prob
{
	int a, b;
	bool operator<(const prob& o)const
	{
		return b < o.b;
	}
};
bool lt_a(const prob& op1, const prob& op2)
{
	return op1.a < op2.a;
}
int main()
{
	int n, m, p;
	while(scanf("%d%d%d", &n, &m, &p) != EOF)
	{
		int power = p;
		assert(n <= 100000);
		assert(m <= n);
		prob pa[MAXN];
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &pa[i].a, &pa[i].b);
		sort(pa, pa + n, lt_a);
		priority_queue<prob> pq;
		for(int i = 0, j = 0; i < m; ++i)
		{
			for(; j < n && pa[j].a <= power; ++j)
				pq.push(pa[j]);
			if(pq.empty())
				break;
			prob tmp = pq.top();
			power += tmp.b;
			pq.pop();
		}
		printf("%d\n", power);
	}
	return 0;
}
