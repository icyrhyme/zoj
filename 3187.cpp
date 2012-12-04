#include <iostream>
#include <vector>
#define MAXN 128
#define MAXP 100000
#define INF 1000000000
using namespace std;
int getCost(int pn, int x, int y, int s1, int p1, int s2, int p2) {
	if(pn * x <= y)
		return 0;
	int need = pn * x - y;
	int a, b, lima, limb;
	lima = min(s2, (need + s1 - 1) / s1);
	limb = min(s1, (need + s2 - 1) / s2);
	int cost = INF;
	for(a = 0; a <= lima; ++a) {
		b = (need - a * s1 + s2 - 1) / s2;
		cost = min(cost, a * p1 + b * p2);
	}
	for(b = 0; b <= limb; ++b) {
		a = (need - b * s2 + s1 - 1) / s1;
		cost = min(cost, a * p1 + b * p2);
	}
	return cost;
}
int main() {
	int n, m;
	int x[MAXN], y[MAXN], s[2][MAXN], p[2][MAXN];
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; ++i)
			scanf("%d%d%d%d%d%d", &x[i], &y[i], &s[0][i], &p[0][i], &s[1][i], &p[1][i]);
		int le = 0, ri = m;
		while(le <= ri) {
			int mi = (le + ri) / 2;
			int money = 0;
			for(int i = 0; i < n; ++i)
				money += getCost(mi, x[i], y[i], s[0][i], p[0][i], s[1][i], p[1][i]);
			if(money > m)
				ri = mi - 1;
			else
				le = mi + 1;
		}
		printf("%d\n", ri);
	}
	return 0;
}
