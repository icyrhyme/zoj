#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXL 16
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		char s[MAXL], res[MAXL];
		gets(s);
		memset(res, 0, sizeof(res));
		for(int i = 0; i < 2 * n - 1; ++i) {
			gets(s);
			for(int j = 0; j < 7; ++j)
				res[j] ^= s[j];
		}
		printf("%s\n", res);
	}
	return 0;
}
