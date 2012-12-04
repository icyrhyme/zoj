#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXL 4
#define EPS 1e-8
#define C(a) (abs(a)<EPS?0:a)
using namespace std;
const double sq = sqrt(0.5);
void update(double& x, double& y, int step, char str[]) {
	int len = strlen(str);
	if(len == 1) {
		switch(str[0]) {
			case 'N': y += step; break;
			case 'E': x += step; break;
			case 'S': y -= step; break;
			case 'W': x -= step; break;
		}
	}
	else {
		switch(str[0]) {
			case 'N': y += sq * step; break;
			case 'S': y -= sq * step; break;
		}
		switch(str[1]) {
			case 'E': x += sq * step; break;
			case 'W': x -= sq * step; break;
		}
	}
}
int main() {
	int n, csnum = 1, ret;
	while((ret = scanf("%d", &n)) == 1) {
		char str[MAXL], c;
		double x = 0, y = 0;
		scanf("%[^.,]", str);
		update(x, y, n, str);
		c = getchar();
		while(c != '.') {
			scanf("%d", &n);
			scanf("%[^.,]", str);
			update(x, y, n, str);
			c = getchar();
		}
		printf("Map #%d\n", csnum);
		csnum++;
		printf("The treasure is located at (%.3lf,%.3lf).\n", C(x), C(y));
		printf("The distance to the treasure is %.3lf.\n\n", C(sqrt(x * x + y * y)));
	}
	scanf("%*s");
	return 0;
}
