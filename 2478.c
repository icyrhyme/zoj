#include <stdio.h>
#include <string.h>
#define MAXL 128
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		char s[MAXL];
		scanf("%s", &s);
		int len = strlen(s), i;
		for(i = 0; i < len; ) {
			int cnt = 0, j;
			for(j = i; j < len && s[j] == s[i]; ++j)
				++cnt;
			if(cnt > 1)
				printf("%d%c", cnt, s[i]);
			else
				putchar(s[i]);
			i = j;
		}
		putchar('\n');
	}
	return 0;
}
