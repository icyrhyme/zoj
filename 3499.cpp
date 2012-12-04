#include <cstdio>
#include <algorithm>
#define MAXN 512
using namespace std;
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		int n;
		scanf("%d", &n);
		double a[MAXN];
		for(int i = 0; i < n; ++i)
			scanf("%lf", a + i);
		sort(a, a + n);
		if(n % 2 == 1)
			printf("%.3lf\n", a[n / 2]);
		else
			printf("%.3lf\n", (a[n / 2] + a[(n - 1) / 2]) / 2);
	}
	return 0;
}
