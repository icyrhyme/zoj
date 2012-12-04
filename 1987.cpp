#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 40
using namespace std;
long long msk[MAXN];
long long ans[MAXN];
int sz;
int count_bit(long long n) {
	int ret = 0;
	while(n) {
		++ret;
		n &= (n - 1);
	}
	return ret;
}
bool dfs(int i, int j, int k, long long m) {
	if(j == k && count_bit(m) >= k)
		return true;
	if(i == sz || count_bit(m) < k)
		return false;
	return dfs(i + 1, j + 1, k, m & msk[ans[i]]) || dfs(i + 1, j, k, m);
}
bool isok(int k) {
	sz = 0;
	for(int i = 0; i < MAXN; ++i) {
		if(count_bit(msk[i]) >= k)
			ans[sz++] = i;
	}
	if(sz < k || !dfs(0, 0, k, (1LL << MAXN) - 1))
		return false;
	else
		return true;
}
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		fill(msk, msk + MAXN, 0LL);
		int m, u, v;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			--u, --v;
			msk[u] |= (1LL << v);
		}
		for(int i = (int)sqrt(1.0 * m); i >= 1; --i) {
			if(isok(i)) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
