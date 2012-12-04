#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		vector<pair<int, int> > p;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			int y1, y2;
			scanf("%*d%d%d", &y1, &y2);
			p.push_back(make_pair(y1, -1));
			p.push_back(make_pair(y2, 1));
		}
		sort(p.begin(), p.end());
		int cnt = 0, ans = 0;
		vector<pair<int, int> >::iterator it;
		for(it = p.begin(); it != p.end(); ++it) {
			cnt -= it->second;
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
