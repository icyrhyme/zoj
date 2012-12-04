#include <cstdio>
#define MAXL 32
using namespace std;
int main() {
	int n;
	char b[MAXL], g[MAXL], x[MAXL];
	scanf("%d", &n);
	while(n--) {
		scanf("%s%s%s", b, g, x);
		printf("%s will survive\n", g);
	}
	return 0;
}
