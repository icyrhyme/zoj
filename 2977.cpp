#include <cstdio>
#include <cstring>
#define MAXN 16
#define MAXS (1<<(MAXN))
#define INF 1000000000
using namespace std;
int main() {
	int msks[MAXS], cnts[MAXS];
	for(int i = 0; i < MAXS; ++i) {
		int num = i, msk = 0, cnt = 0;
		for(int j = 0; num; ++j, num >>= 1) {
			if(num & 1) {
				if(j == 0)
					msk ^= 0x3;
				else
					msk ^= (0x7 << (j - 1));
				++cnt;
			}
		}
		msks[i] = msk;
		cnts[i] = cnt;
	}
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		char s[MAXN + 1];
		int mp[MAXN], work[MAXN];
		for(int i = 0; i < n; ++i) {
			scanf("%s", s);
			mp[i] = 0;
			for(int j = 0; j < m; ++j) {
				mp[i] <<= 1;
				if(s[j] == 'X')
					mp[i] |= 1;
			}
		}
		int msk, lim = (1 << m), cnt, ans = INF;
		for(int i = 0; i < lim; ++i) {
			memcpy(work, mp, sizeof(int) * n);
			msk = (msks[i] & (lim - 1));
			work[0] ^= msk;
			cnt = cnts[i];
			if(1 < n) {
				work[1] ^= i;
			}
			for(int j = 1; j < n; ++j) {
				msk = (msks[work[j - 1]] & (lim - 1));
				work[j] ^= msk;
				cnt += cnts[work[j - 1]];
				if(j + 1 < n)
					work[j + 1] ^= work[j - 1];
				work[j - 1] ^= work[j - 1];
			}
			if(work[n - 1] == 0 && cnt < ans) {
				ans = cnt;
			}
		}
		if(ans != INF)
			printf("You have to tap %d tiles.\n", ans);
		else
			printf("Damaged billboard.\n");
	}
	return 0;
}
