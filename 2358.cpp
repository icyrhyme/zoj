#include <iostream>
#include <cstdio>
#define MAXN 10
using namespace std;
int main() {
	int fact[MAXN];
	fact[0] = 1;
	for(int i = 1; i <= 9; ++i)
		fact[i] = fact[i - 1] * i;
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n < 0)
			break;
		else if(n == 0) {
			printf("NO\n");
			continue;
		}
		int num = n;
		for(int i = 9; i >= 0; --i)
			if(num >= fact[i])
				num -= fact[i];
		if(num == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
