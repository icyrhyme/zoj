#include <cstdio>
#include <cmath>
#include <algorithm>
#define PI acos(-1.0)
using namespace std;
double dist(double x1, double y1, double x2, double y2) {
	double dx = x2 - x1;
	double dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}
int main() {
	double x1, y1, r1, x2, y2, r2;
	while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2) != EOF) {
		double d = dist(x1, y1, x2, y2);
		double a, b, ans = 0;
		if(r2 < r1) {
			swap(r1, r2);
			swap(x1, x2);
			swap(y1, y2);
		}
		if(r1 + r2 <= d) {
			printf("%.3lf\n", 0.0);
			continue;
		}
		else if(r2 - r1 >= d) {
			printf("%.3lf\n", PI * r1 * r1);
			continue;
		}
		if(d > r1 && d > r2) {
			a = ((r1 * r1 - r2 * r2) / d + d) / 2;
			b = (d - (r1 * r1 - r2 * r2) / d) / 2;
			double th = 2 * acos(a / r1);
			ans = th * r1 * r1 / 2 - r1 * r1 * sin(th) / 2;
			th = 2 * acos(b / r2);
			ans += th * r2 * r2 / 2 - r2 * r2 * sin(th) / 2;
		}
		else {
			b = (d + (r2 * r2 - r1 * r1) / d) / 2;
			a = ((r2 * r2 - r1 * r1) / d - d) / 2;
			double th = 2 * acos(a / r1);
			ans = PI * r1 * r1 - th * r1 * r1 / 2 + r1 * r1 * sin(th) / 2;
			th = 2 * acos(b / r2);
			ans += th * r2 * r2 / 2 - r2 * r2 * sin(th) / 2;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
