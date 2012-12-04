#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int len;
	while(scanf("%d", &len) != EOF) {
		if(len == 0)
			break;
		if(len <= 4)
			printf("10\n");
		else if(len % 8 <= 4) {
			if(len % 8 == 0)
				printf("%.0lf\n", len / 8 * 18 + (len % 8) * 2.4);
			else
				printf("%.1lf\n", len / 8 * 18 + (len % 8) * 2.4);
		}
		else
			printf("%d\n", len / 8 * 18 + 10 + (len % 8 - 4) * 2);
	}
	return 0;
}
