#include <cstdio>
using namespace std;
int extGcd(int a, int b, int &x, int &y) {
	int t, ret;
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	ret = extGcd(b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, m, x, y;
		scanf("%d%d", &a, &m);
		int d = extGcd(a, m, x, y);
		if(1 % d) {
			puts("Not Exist");
		}
		else {
			int e = (x + m) % m;
			if(e == 0)
				e = m;
			printf("%d\n", e);
		}
	}
	return 0;
}
