#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a[1000005];
int main() {
	a[0] = 0;
	for(int i = 1; i <= 1000000; ++i)
		a[i] = a[i - 1] + 1.0 / i;
	int n;
	printf("%.8lf\n", log(2.73));
	while(scanf("%d", &n) != EOF) {
		if(n <= 1000000)
			printf("%.8lf\n", a[n]);
		else {
			double val = log(1.0 * n);
			val += 0.5772156649;
			val += 1.0 / (2.0 * n);
			val -= 1.0 / (12.0 * n * n);
			printf("%.8lf\n", val);
		}
	}
	return 0;
}
