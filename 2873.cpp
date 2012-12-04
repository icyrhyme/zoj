#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define LIM 1000000000000000000LL
using namespace std;
vector<long long> v;
int fact[4] = {2, 3, 5, 7};
void search(int idx, long long val) {
	if(idx == 4) {
		v.push_back(val);
		return;
	}
	for(int i = 0; val <= LIM; val *= fact[idx]) {
		search(idx + 1, val);
	}
}
int main() {
	search(0, 1);
	sort(v.begin(), v.end());
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", v[n - 1]);
	}
	return 0;
}
