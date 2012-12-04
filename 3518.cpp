#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <bitset>
#include <algorithm>
#define MAXN 100005
#define FI first
#define SE second
using namespace std;
int main() {
	int L, n1, n2;
	while(scanf("%d%d%d", &L, &n1, &n2) != EOF) {
		pair<int, int> a[MAXN], b[MAXN];
		set<int> s;
		for(int i = 0; i < n1; ++i) {
			scanf("%d%d", &a[i].FI, &a[i].SE);
			s.insert(a[i].FI - 1);
			s.insert(a[i].FI);
			s.insert(a[i].FI + 1);
			s.insert(a[i].SE - 1);
			s.insert(a[i].SE);
			s.insert(a[i].SE + 1);
		}
		for(int i = 0; i < n2; ++i) {
			scanf("%d%d", &b[i].FI, &b[i].SE);
			s.insert(b[i].FI - 1);
			s.insert(b[i].FI);
			s.insert(b[i].FI + 1);
			s.insert(b[i].SE - 1);
			s.insert(b[i].SE);
			s.insert(b[i].SE + 1);
		}
		vector<int> vi(s.begin(), s.end());
		bitset<3 * MAXN> bs;
		bs.reset();
		for(int i = 0; i < n1; ++i) {
			int begin, end;
			begin = lower_bound(vi.begin(), vi.end(), a[i].FI) - vi.begin();
			end = lower_bound(vi.begin(), vi.end(), a[i].SE) - vi.begin();
			for(int j = begin; j <= end; ++j)
				bs[j] = true;
		}
		for(int i = 0; i < n2; ++i) {
			int begin, end;
			begin = lower_bound(vi.begin(), vi.end(), b[i].FI) - vi.begin();
			end = lower_bound(vi.begin(), vi.end(), b[i].SE) - vi.begin();
			for(int j = begin; j <= end; ++j)
				bs[j] = !bs[j];
		}
		int ans = 0;
		for(int i = 0; i < vi.size(); ++i) {
			if(!bs[i]) 
				continue;
			int j;
			for(j = 0; i + j < vi.size() && bs[i + j]; ++j)
				;
			ans = max(ans, vi[i + j - 1] - vi[i] + 1);
			//printf("%d->%d\n", vi[i], vi[i + j - 1]);
			i = i + j - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
