#include <cstdio>
using namespace std;
int main() {
	double a, b, c, d, e, f;
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
		if(a * c == 0)
			puts("parabola");
		else if(a * c < 0)
			puts("hyperbola");
		else if(a == c)
			puts("circle");
		else
			puts("ellipse");
	}
	return 0;
}
