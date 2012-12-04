#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXM 1500000000
#define MAXL 32
using namespace std;
int main() {
	int p[MAXL];
	p[0] = 1;
	for(int i = 1; p[i - 1] <= MAXM / 3; ++i)
		p[i] = p[i - 1] * 3;
	int m;
	while(scanf("%d", &m) != EOF) {
		--m;
		vector<int> v, a, b;
		while(m > 0) {
			v.push_back(m % 3);
			m /= 3;
		}
		reverse(v.begin(), v.end());
		for(int i = 0; i < v.size(); ++i) {
			if(v[i] == 0)
				a.push_back(p[i]);
			else if(v[i] == 2)
				b.push_back(p[i]);
		}
		b.push_back(p[v.size()]);
		if(a.size() == 0)
			printf("-1\n");
		else
			for(int i = 0; i < a.size(); ++i)
				printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');
		if(b.size() == 0)
			printf("-1\n");
		else
			for(int i = 0; i < b.size(); ++i)
				printf("%d%c", b[i], i == b.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
