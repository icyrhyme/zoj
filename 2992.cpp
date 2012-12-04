#include <cstdio>
#include <algorithm>
#define MAXL 200
using namespace std;
int main() {
	int cs, csnum = 1;
	scanf("%d", &cs);
	getchar();
	while(cs--) {
		char s[MAXL];
		gets(s);
		int cnt = 0, h = 0;
		for(int i = 0; s[i]; ++i) {
			if(s[i] == '[')
				++cnt;
			else if(s[i] == ']')
				--cnt;
			h = max(cnt, h);
		}
		printf("%d %lld\n", csnum, (1LL << h));
		++csnum;
	}
	return 0;
}
