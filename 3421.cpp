#include <cstdio>
#include <algorithm>
#define MAXN 10005
#define INF 6000
using namespace std;
int n;
double a[MAXN], b[MAXN], c[MAXN];
double f(double x) {
	double ans = a[0] * x * x + b[0] * x + c[0];
	for(int i = 1; i < n; ++i)
		ans = max(ans, a[i] * x * x + b[i] * x + c[i]);
	return ans;
}
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%lf%lf%lf", a + i, b + i, c + i);
		}
		double le = 0, ri = 1000;
		while(ri - le > 1e-9) {
			//printf("%lf %lf\n", le, ri);
			double lemi = (2 * le + ri) / 3;
			double rimi = (le + 2 * ri) / 3;
			if(f(lemi) < f(rimi))
				ri = rimi;
			else
				le = lemi;
		}
		printf("%.4lf\n", f(le));
	}
	return 0;
}
