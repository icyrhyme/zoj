#include <iostream>
#include <cstdio>
#include <map>
#define MAXN 50005
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int a[MAXN];
		map<int, int> mm;
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i) {
			int key = a[i] - i;
			if(mm.find(key) == mm.end())
				mm[key] = 1;
			else
				++mm[key];
		}
		map<int, int>::iterator it;
		int ie, c;
		for(it = mm.begin(); it != mm.end(); ++it) {
			if(it == mm.begin()) {
				ie = it->first;
				c = it->second;
				continue;
			}
			if(it->second > c) {
				ie = it->first;
				c = it->second;
			}
		}
		printf("%d\n", n - c);
		for(int i = 0; i < n; ++i) {
			printf("%d%c", ie + i, (i == n - 1 ? '\n' : ' '));
		}
	}
	return 0;
}
