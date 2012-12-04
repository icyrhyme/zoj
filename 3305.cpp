#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN (1<<16)
using namespace std;
bool a[MAXN];
int memo[MAXN];
int solve(int msk) {
	if(memo[msk] == -1) {
		memo[msk] = 0;
		for(int sub = msk; sub != 0; sub = (sub - 1) & msk) {
			if(a[sub])
				memo[msk] = max(memo[msk], solve(msk ^ sub) + 1);
		}
	}
	return memo[msk];
}
int main() {
	int N, M;
	while(scanf("%d%d", &N, &M) != EOF) {
		int K, idx, msk;
		memset(a, false, sizeof(a));
		memset(memo, -1, sizeof(memo));
		for(int i = 0; i < M; ++i) {
			scanf("%d", &K);
			msk = 0;
			for(int j = 0; j < K; ++j) {
				scanf("%d", &idx);
				--idx;
				msk |= (1 << idx);
			}
			a[msk] = true;
		}
		printf("%d\n", solve((1 << N) - 1));
	}
	return 0;
}
