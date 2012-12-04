#include <iostream>
#define MAXN 20
using namespace std;
int main() {
	int n;
	int wait[MAXN], wn = 0;
	fill(wait, wait + MAXN, -1);
	while(scanf("%d", &n) != EOF) {
		if(n == 99)
			break;
		++wn;
		wait[n - 1] = n - 1;
	}
	vector<int> v;
	while(scanf("%d", &n) != EOF) {
		v.push_back(n - 1);
	}
	int lim = min(wn, v.size());
	for(int i = 0; i < lim; ++i) {
		int j = v[i];
		int cnt = 0;
		while(wait[j] == -1) {
			--j;
			if(j < 0)
				j += MAXN;
			++cnt;
		}
	}
	return 0;
}
