#include <stdio.h>
#define MAXL 256
int dx[4] = {10, 0, -10, 0};
int dy[4] = {0, -10, 0, 10};
int main() {
	char cmd[MAXL];
	while(scanf("%s", cmd) != EOF) {
		int x = 300, y = 420, k = 0;
		int i;
		printf("300 420 moveto\n");
		for(i = 0; cmd[i]; ++i) {
			x += dx[k];
			y += dy[k];
			printf("%d %d lineto\n", x, y);
			if(cmd[i] == 'A') {
				++k;
				if(k >= 4)
					k -= 4;
			}
			else {
				--k;
				if(k < 0)
					k += 4;
			}
		}
		printf("%d %d lineto\n", x + dx[k], y + dy[k]);
		printf("stroke\n");
		printf("showpage\n");
	}
	return 0;
}
