#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool op(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second != p2.second)
		return (p1.second < p2.second);
	else
		return (p1.first > p2.first);
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		vector<pair<int, int> > vp;
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			vp.push_back(make_pair(u, v));
		}
		sort(vp.begin(), vp.end(), op);
		int end = -1, cnt = 0;
		for(int i = 0; i < vp.size(); ++i) {
			if(vp[i].first >= end) {
				end = vp[i].second;
				++cnt;
			}
		}
		printf("%d\n", n - cnt);
	}
	return 0;
}
