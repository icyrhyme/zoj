#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
double dist(pair<double, double> a, pair<double, double> b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		vector<pair<double, double> > vp(n);
		double x = 0, y = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%lf%lf", &vp[i].first, &vp[i].second);
			x += vp[i].first;
			y += vp[i].second;
		}
		x /= n;
		y /= n;
		double p = 1, maxd;
		for(int i = 0; i < 10000; ++i) {
			maxd = 0;
			int idx = 0;
			for(int j = 0; j < n; ++j) {
				if(dist(make_pair(x, y), vp[j]) > maxd) {
					maxd = dist(make_pair(x, y), vp[j]);
					idx = j;
				}
			}
			x += (vp[idx].first - x) * p;
			y += (vp[idx].second - y) * p;
			p *= 0.993;
		}
		printf("%.2lf %.2lf %.2lf\n", x, y, maxd);
	}
	return 0;
}
