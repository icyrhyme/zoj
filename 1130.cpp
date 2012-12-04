#include <iostream>
#include <cstdio>
#define CLR(a,b) ((a)&=(~(1<<(b))))
using namespace std;
int mem[16][1 << 16];
bool flag[1 << 16];
bool search(int len, int idx, int val) {
	mem[len][idx] = val;
	flag[val] = true;
	if(idx == (1 << len) - 1)
		return true;
	int newval = val;
	newval = CLR(newval, len - 1);
	newval <<= 1;
	if(!flag[newval])
		if(search(len, idx + 1, newval))
			return true;
	if(!flag[newval + 1])
		if(search(len, idx + 1, newval + 1))
			return true;
	flag[val] = false;
	return false;
}
int main() {
	for(int i = 1; i <= 15; ++i) {
		fill(flag, flag + (1 << i), false);
		search(i, 0, 0);
	}
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		if(n == 0 && k == 0)
			break;
		printf("%d\n", mem[n][k]);
	}
	return 0;
}
