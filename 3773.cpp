#include <iostream>
#include <cmath>
using namespace std;
#include <cstdio>
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		double W, H;
		double px[8], py[8];
		scanf("%lf%lf", &W, &H);
		for(int i = 0; i < 4; ++i)
			scanf("%lf%lf", &px[i], &py[i]);
		double a, b, c, d, e, f;
		e = px[0];
		a = (px[1] - e) / W;
		c = (px[3] - e) / H;
		f = py[0];
		b = (py[1] - f) / W;
		d = (py[3] - f) / H;
		double x = (-e * (d - 1) + f * c) / ((a - 1) * (d - 1) - b * c);
		double y = (-e * b + f * (a - 1)) / (b * c - (d - 1) * (a - 1));
		printf("%.2lf %.2lf\n", x, y);
	}
	return 0;
}
