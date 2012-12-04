#include <cstdio>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d", n);
		double fx, fy, px, py, tx, ty;
		scanf("%lf%lf", &px, &py);
		fx = px, fy = py;
		for(int i = 1; i < n; ++i) {
			scanf("%lf%lf", &tx, &ty);
			printf(" %.6lf %.6lf", (px + tx) / 2, (py + ty) / 2);
			px = tx, py = ty;
		}
		printf(" %.6lf %.6lf\n", (px + fx) / 2, (py + fy) / 2);
	}
	return 0;
}
