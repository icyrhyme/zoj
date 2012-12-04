#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		int h = 0;
		for(int i = 0; i < n; ++i) {
			int r;
			scanf("%d", &r);
			if(n - r >= h) {
				h = n - r + 1;
			}
			else {
				++h;
			}
		}
		printf("%d\n", h - n);
	}
	return 0;
}
