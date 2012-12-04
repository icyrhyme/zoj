#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#define MAXN 256
using namespace std;
int main() {
	int cas;
	pair<int, int> t[MAXN];
	scanf("%d", &cas);
	while(cas--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) 
			scanf("%d", &t[i].second);
		for(int i = 0; i < n; ++i)
			scanf("%d", &t[i].first);
		sort(t, t + n);
		int dp[MAXN];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; ++i) {
			for(int j = min(i, m - 1); j >= 0; --j)
				dp[j + 1] = max(dp[j + 1], dp[j] + t[i].second + j * t[i].first);
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}
