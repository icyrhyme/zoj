#include <iostream>
#include <cstdio>
#include <cmath>
#define EPS 1e-2
#define INIT_STEP 20000
#define MAXN 128
#define INF 1e30
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
double calc(double x, double y, int px[], int py[], int n) {
	double sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += hypot(px[i] - x, py[i] - y);
	}
	return sum;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int px[MAXN], py[MAXN];
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &px[i], &py[i]);
		}
		double step = INIT_STEP, ans = INF, newans;
		double x = 0, y = 0, nx, ny;
		while(true) {
			int i;
			double ret;
			for(i = 0; i < 4; ++i) {
				nx = x + dx[i] * step;
				ny = y + dy[i] * step;
				newans = calc(nx, ny, px, py, n);
				if(newans < ans) {
					break;
				}
			}
			if(i == 4)
				step /= 2;
			else {
				if(fabs(ans - newans) < EPS && fabs(step) < EPS)
					break;
				ans = newans;
				x = nx;
				y = ny;
			}
		}
		printf("%d\n", (int)(ans + 0.5));
	}
	return 0;
}
