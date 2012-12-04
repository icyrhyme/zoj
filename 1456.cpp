#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define PI acos(-1.0)
#define MAXN 30005
#define EPS 1e-8
using namespace std;
double x[MAXN], y[MAXN];
bool cmp(pair<double, int> p1, pair<double, int> p2) {
	if(!(abs(p1.first - p2. first) < EPS))
		return p1.first < p2.first;
	else
		return p1.second > p2.second;
}
int main() {
	int n;
	double a;
	while(scanf("%d%lf", &n, &a) != EOF) {
		double tx, ty, c, r, alpha, delta, le, ri;
		vector<pair<double, int> > vp;
		for(int i = 0; i < n; ++i) {
			scanf("%lf", &x[i]);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%lf", &y[i]);
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			tx = x[i];
			ty = y[i];
			c = -tx * tx - ty * ty;
			r = (-1 + sqrt(1 - 4 * a * a * c)) / (2 * a * a);
			r = sqrt(r);
			alpha = atan2(ty, tx);
			delta = atan(1.0 / (a * r));
			le = alpha - delta, ri = alpha + delta;
			if(le < -PI)
				le += 2 * PI;
			if(ri > PI)
				ri -= 2 * PI;
			if(le > ri)
				++cnt;
			vp.push_back(make_pair(le, 1));
			vp.push_back(make_pair(ri, -1));
		}
		sort(vp.begin(), vp.end(), cmp);
		int maxcnt = cnt;
		vector<pair<double, int> >::iterator it;
		for(it = vp.begin(); it != vp.end(); ++it) {
			cnt += it->second;
			if(cnt > maxcnt)
				maxcnt = cnt;
		}
		printf("%d daze\n", maxcnt);
	}
	return 0;
}
