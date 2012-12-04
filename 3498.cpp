#include <cstdio>
using namespace std;
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		int n, cnt = 0;
		scanf("%d", &n);
		while(n > 0) {
			n /= 2;
			++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
