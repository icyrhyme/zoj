#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXL 20000
#define SETB(a,b) ((a)|=(1<<(b)))
using namespace std;
int main() {
	char str[MAXL];
	while(1) {
		vector<int> a, b;
		int ret;
		while((ret = scanf("%s", str)) != EOF) {
			if(strcmp(str, ".") == 0)
				break;
			int av = 0, bv = 0;
			for(int i = 0; str[i] != ';'; i += 2) {
				if(str[i] == '+') {
					SETB(av, str[i + 1] - 'A');
				}
				else {
					SETB(bv, str[i + 1] - 'A');
				}
			}
			a.push_back(av);
			b.push_back(bv);
		}
		if(ret != 1)
			break;
		int sz = a.size(), ans = -1;
		for(int i = 0; i < (1 << 16); ++i) {
			int cnt = 0;
			for(int j = 0; j < sz; ++j) {
				if((i & a[j]) || ((~i) & b[j]))
					++cnt;
			}
			if(cnt == sz) {
				ans = i;
				break;
			}
		}
		if(ans == -1)
			printf("No pizza can satisfy these requests.\n");
		else {
			printf("Toppings: ");
			for(int i = 0; ans; ++i, ans >>= 1) {
				if(ans & 0x1)
					putchar('A' + i);
			}
			putchar('\n');
		}
	}
	return 0;
}
