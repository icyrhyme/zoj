#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
	int n;
	int csnum = 1;
	while(scanf("%d", &n) != EOF && n != 0) {
		vector<int> v;
		for(int i = 0; i < 10000; ++i)
			v.push_back(i);
		for(int i = 0; i < n; ++i) {
			vector<int> nv;
			int y, a, b;
			scanf("%d%d%d", &y, &a, &b);
			for(int j = 0; j < v.size(); ++j) {
				if(v[j] >= a && (v[j] - a) % (b - a) == (y - a)) {
					nv.push_back(v[j]);
					//printf("%d\n", v[j]);
				}
			}
			v = nv;
		}
		printf("Case #%d:\n", csnum);
		++csnum;
		if(v.size() == 0) {
			printf("Unknown bugs detected.\n");
		}
		else {
			printf("The actual year is %d.\n", v[0]);
		}
		printf("\n");
	}
	return 0;
}
