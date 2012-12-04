#include <cstdio>
#include <map>
#define MAXN 32
using namespace std;
void input(int av[], long long a[], int n, map<long long, int>& mpa) {
	for(int i = 0; i < n; ++i) {
		scanf("%d", &av[i]);
		int k;
		scanf("%d", &k);
		a[i] = 0LL;
		for(int j = 0; j < k; ++j) {
			int val;
			scanf("%d", &val);
			a[i] |= (1LL << (val - 1));
		}
	}
	for(int i = 0; i < (1 << n); ++i) {
		int num = i;
		long long msk = 0;
		int w = 0;
		for(int j = 0; j < n; ++j, num >>= 1) {
			if(num & 1) {
				msk ^= a[j];
				w += av[j];
			}
		}
		if(mpa.find(msk) == mpa.end()) {
			mpa[msk] = w;
		}
		else {
			mpa[msk] = max(mpa[msk], w);
		}
	}
}
int main() {
	int n, m;
	long long a[MAXN], b[MAXN];
	int av[MAXN], bv[MAXN];
	map<long long, int> mpa, mpb;
	while(scanf("%d", &m) != EOF) {
		n = m / 2;
		m -= n;
		mpa.clear();
		input(av, a, n, mpa);
		mpb.clear();
		input(bv, b, m, mpb);
		map<long long, int>::iterator it;
		int ans = -1;
		for(it = mpa.begin(); it != mpa.end(); ++it) {
			if(mpb.find(it->first) != mpb.end()) {
				ans = max(ans, it->second + mpb[it->first]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
