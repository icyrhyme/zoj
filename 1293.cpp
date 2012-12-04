#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		n = (n + 1) / 2;
		n = n + (n + 1) / 2;
		n = (n + 61) / 62;
		n = (n + 29999) / 30000;
		printf("File #%d\n", csnum);
		printf("John needs %d floppies.\n\n", n);
		++csnum;
	}
	return 0;
}
