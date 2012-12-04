 #include <iostream>
using namespace std;
#define MAXN 50005
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)^1)
#define M(x,y) (((x)+(y))>>1)
struct SegTreeNode {
	int le, ri;
	long long sum, val;
	bool isSame;
} st[3 * MAXN];
int a[MAXN];
int n, m;
void init(int le, int ri, int x = 1)
{
	st[x].le = le;
	st[x].ri = ri;
	st[x].isSame = false;
	if(le == ri) {
		st[x].sum = st[x].val = a[le];
		st[x].isSame = true;
		return;
	}
	init(le, M(le, ri), L(x));
	init(M(le, ri) + 1, ri, R(x));
	st[x].sum = st[L(x)].sum + st[R(x)].sum;
}

void update(int le, int ri, int val, int x = 1)
{
	if(st[x].le != st[x].ri && st[x].isSame)
	{
		st[L(x)].val = st[R(x)].val = st[x].val;
		st[L(x)].isSame = st[R(x)].isSame = true;
		st[L(x)].sum = (st[L(x)].ri - st[L(x)].le + 1) * st[L(x)].val;
		st[R(x)].sum = (st[R(x)].ri - st[R(x)].le + 1) * st[R(x)].val;
	}
	if(st[x].le == le && st[x].ri == ri)
	{
		st[x].val = val;
		st[x].isSame = true;
		st[x].sum = (st[x].ri - st[x].le + 1) * st[x].val;
		return;
	}
	int m = M(st[x].le, st[x].ri);
	if(ri <= m)
		update(le, ri, val, L(x));
	else if(le > m)
		update(le, ri, val, R(x));
	else
	{
		update(le, m, val, L(x));
		update(m + 1, ri, val, R(x));
	}
	st[x].isSame = false;
	st[x].sum = st[L(x)].sum + st[R(x)].sum;
}
long long query(int le, int ri, int x = 1)
{
	if(st[x].le != st[x].ri && st[x].isSame)
	{
		st[L(x)].val = st[R(x)].val = st[x].val;
		st[L(x)].isSame = st[R(x)].isSame = true;
		st[L(x)].sum = (st[L(x)].ri - st[L(x)].le + 1) * st[L(x)].val;
		st[R(x)].sum = (st[R(x)].ri - st[R(x)].le + 1) * st[R(x)].val;
	}
	if(st[x].le == le && st[x].ri == ri)
	{
		return st[x].sum;
	}
	int m = M(st[x].le, st[x].ri);
	if(ri <= m)
		return query(le, ri, L(x));
	else if(le > m)
		return query(le, ri, R(x));
	else
		return query(le, m, L(x)) + query(m + 1, ri, R(x));
}
inline long long floor_div(long long a, long long b);
inline long long ceil_div(long long a, long long b)
{
	if(a >= 0)
		return (a + b - 1) / b;
	else
		return -floor_div(-a, b);
}
inline long long floor_div(long long a, long long b)
{
	if(a >= 0)
		return a / b;
	else
		return -ceil_div(-a, b);
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		long long sum = 0;
		for(int i = 0; i < n; ++i)
			sum += a[i];
		init(0, n - 1);
		for(int i = 0; i < m; ++i)
		{
			int le, ri;
			scanf("%d%d", &le, &ri);
			--le, --ri;
			long long curSum = query(0, n - 1);
			long long segSum = query(le, ri);
			long long val;
			if(curSum <= sum)
				val = ceil_div(segSum, ri - le + 1);
			else
				val = floor_div(segSum, ri - le + 1);
			update(le, ri, (int)val);
		}
		for(int i = 0; i < n; ++i)
			printf("%lld%c", query(i, i), (i == n - 1 ? '\n' : ' '));
		printf("\n");
	}
	return 0;
}

