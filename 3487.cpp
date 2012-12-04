#include <cstdio>
using namespace std;
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		int n;
		scanf("%d", &n);
		if(n / 10 % 10 != 1) {
			printf("%d", n);
			switch(n % 10) {
				case 1: puts("st"); break;
				case 2: puts("nd"); break;
				case 3: puts("rd"); break;
				default: puts("th"); break;
			}
		}
		else
			printf("%dth\n", n);
	}
	return 0;
}
