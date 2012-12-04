#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#define MAXN 2510
#define L second
#define R first
using namespace std;
int main() {
	int n, m;
	pair<int, int> so[MAXN];
	multiset<int> w;
	while(scanf("%d%d", &n, &m) != EOF) {
		w.clear();
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &so[i].L, &so[i].R);
		for(int i = 0; i < m; ++i) {
			int tmp;
			scanf("%d", &tmp);
			w.insert(tmp);
		}
		sort(so, so + n);
		multiset<int>::iterator it;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			it = w.lower_bound(so[i].L);
			if(it != w.end() && *it <= so[i].R) {
				++ans;
				w.erase(it);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
