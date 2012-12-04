#include <stdio.h>
#include <math.h>
#define MAXN 1024
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		int i, j, k;
		double cost[MAXN], avg = 0;
		for(i = 0; i < n; ++i) {
			scanf("%lf", &cost[i]);
			avg += cost[i];
		}
		avg /= n;
		double res = 0;
		for(i = 0; i < n; ++i) {
			if(cost[i] < avg)
				res += (avg - cost[i]);
		}
		printf("%.2lf\n", floor(res * 100.0) / 100);
	}
	return 0;
}
