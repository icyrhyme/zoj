#include <cstdio>
#include <algorithm>
#define MAXN 400005
#define MAXK 2050
#define INF 1000000000
using namespace std;
int main() {
	int type[MAXN], N, K, le[MAXK], ri[MAXK];
	while(scanf("%d%d", &N, &K) != EOF) {
		for(int i = 0; i < N; ++i) {
			scanf("%d", &type[i]);
			--type[i];
		}
		int tot = 0, cnt[MAXK];
		bool flag = true;
		for(int i = 0; i < K; ++i) {
			cnt[i] = 0;
			scanf("%d%d", &le[i], &ri[i]);
			if(le[i] > ri[i] || ri[i] < 0)
				flag = false;
			if(cnt[i] >= le[i])
				++tot;
		}
		if(!flag) {
			puts("-1");
			continue;
		}
		else if(tot == K) {
			puts("0");
			continue;
		}
		int ans = INF;
		for(int j = 0, i = 0; j < N; ++j) {
			++cnt[type[j]];
			if(cnt[type[j]] == le[type[j]])
				++tot;
			else if(cnt[type[j]] == ri[type[j]] + 1)
				--tot;
			while(i <= j && cnt[type[i]] > le[type[i]]) {
				--cnt[type[i]];
				if(cnt[type[i]] == ri[type[i]])
					++tot;
				++i;
			}
			if(tot == K)
				ans = min(ans, j - i + 1);
		}
		if(ans == INF)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}
