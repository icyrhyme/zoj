#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 1e50
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		double at = INF;
		for(int i = 0; i < n; ++i) {
			int v, t;
			scanf("%d%d", &v, &t);
			if(t < 0)
				continue;
			at = min(at, t + 4.5 * 3600 / v);
		}
		printf("%.0lf\n", ceil(at));
	}
	return 0;
}
