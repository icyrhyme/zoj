#include <cstdio>
using namespace std;
inline int adjust(int x) {
	if(x < 0)
		return x + 40;
	else
		return x;
}
int calc(int p, int a, int b, int c) {
	int ret = 0, delta;
	ret += adjust(p - a);
	ret += adjust(b - a);
	ret += adjust(b - c);
	ret = ret * 360 / 40;
	ret += 360 * 3;
	return ret;
}
int main() {
	int p, a, b, c;
	while(true) {
		scanf("%d%d%d%d", &p, &a, &b, &c);
		if(p == 0 && a == 0 && b == 0 && c == 0)
			break;
		printf("%d\n", calc(p, a, b, c));
	}
	return 0;
}
