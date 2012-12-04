#include <iostream>
#include <vector>
#include <map>
#define MAXN 128
#define ABS(x) ((x)>0?(x):-(x))
using namespace std;
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		vector<pair<int, int> > vp;
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			vp.push_back(make_pair(u, i + 1));
			vp.push_back(make_pair(v, -i - 1));
		}
		sort(vp.begin(), vp.end());
		bool used[MAXN];
		int mm[MAXN];
		memset(used, false, sizeof(used));
		memset(mm, -1, sizeof(mm));
		for(int i = 0; i < vp.size(); ++i) {
			int a = vp[i].first, b = vp[i].second;
			int er;
			if(b < 0) {
				if(mm[-b] >= 0) {
					used[mm[-b]] = false;
				}
				continue;
			}
			for(er = 0; er < m; ++er)
				if(used[er] == false) {
					used[er] = true;
					mm[b] = er;
					break;
				}
		}
		for(int i = 1; i <= n; ++i)
			printf("%d\n", mm[i] + 1);
	}
	return 0;
}
