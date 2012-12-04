#include <cstdio>
#include <cstring>
#define MAXN 10000
using namespace std;
int main() {
	int cas, cnt[MAXN];
	scanf("%d", &cas);
	while(cas--) {
		int n;
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; ++i) {
			int id;
			scanf("%d", &id);
			++cnt[id];
		}
		int maxcnt = 0, ans;
		for(int i = 1001; i <= 9999; ++i)
			if(cnt[i] >= maxcnt) {
				maxcnt = cnt[i];
				ans = i;
			}
		printf("%d\n", ans);
	}
	return 0;
}
