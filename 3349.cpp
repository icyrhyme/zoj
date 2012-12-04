#include <cstdio>
#include <algorithm>
#define MAXN 100006
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)^1)
#define M(x,y) ((x+y)>>1)
using namespace std;
struct segTreeNode {
	int le, ri, val;
} st[3 * MAXN];
void init(int le, int ri, int x = 1) {
	st[x].le = le;
	st[x].ri = ri;
	st[x].val = 0;
	if(le == ri)
		return;
	int m = M(le, ri);
	init(le, m, L(x));
	init(m + 1, ri, R(x));
}
void update(int idx, int val, int x = 1) {
	if(st[x].le == idx && st[x].ri == idx) {
		st[x].val = val;
		return;
	}
	int m = M(st[x].le, st[x].ri);
	if(idx <= m)
		update(idx, val, L(x));
	else
		update(idx, val, R(x));
	st[x].val = max(st[L(x)].val, st[R(x)].val);
}
int query(int le, int ri, int x = 1) {
	if(le > ri)
		return 0;
	if(st[x].le == le && st[x].ri == ri) {
		return st[x].val;
	}
	int m = M(st[x].le, st[x].ri);
	if(ri <= m)
		return query(le, ri, L(x));
	else if(le > m)
		return query(le, ri, R(x));
	else {
		return max(query(le, m, L(x)), query(m + 1, ri, R(x)));
	}
}
int main() {
	int n, d, a[MAXN], b[MAXN];
	while(scanf("%d%d", &n, &d) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		init(0, n - 1);
		for(int i = 0; i < n; ++i) {
			int le = lower_bound(b, b + n, a[i] - d) - b;
			int ri = upper_bound(b, b + n, a[i] + d) - b - 1;
			int nval = query(le, ri);
			//printf("%d %d %d %d\n", le, ri, i, nval);
			update(lower_bound(b, b + n, a[i]) - b, nval + 1);
		}
		printf("%d\n", query(0, n - 1));
	}
	return 0;
}
