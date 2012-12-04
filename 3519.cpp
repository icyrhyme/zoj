#include <cstdio>
#include <algorithm>
#define MAXN 512
using namespace std;
int main() {
	int n, x;
	while(scanf("%d%d", &n, &x) != EOF) {
		int a[MAXN];
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int* it = upper_bound(a, a + n, x);
		int cnt = it - a;
		for(; it != a + n; ++it) {
			if(*it > x)
				x += 2;
			else
				cnt += 1;
		}
		printf("%d\n", x + cnt);
	}
	return 0;
}
