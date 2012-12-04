#include <iostream>
#define LL long long
#define MAXN 128
#define MOD 1000000007
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		LL C[MAXN], CC[MAXN], B[MAXN][MAXN], P[MAXN][MAXN], XP[MAXN][MAXN], X[MAXN];
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) {
			scanf("%lld", &C[i]);
			for(int j = 0; j < m; ++j)
				scanf("%lld", &P[i][j]);
		}
		int Q;
		scanf("%d", &Q);
		while(Q--) {
			for(int i = 0; i < m; ++i)
				scanf("%lld", &X[i]);
			for(int i = 0; i < m; ++i) {
				XP[i][0] = 1;
				for(int j = 1; j < MAXN; ++j) {
					XP[i][j] = XP[i][j - 1] * X[i] % MOD;
				}
			}
			for(int i = 0; i < n; ++i)
				B[i][m] = 1;
			for(int i = 0; i < n; ++i)
				for(int j = m - 1; j >= 0; --j)
					B[i][j] = B[i][j + 1] * XP[j][P[i][j]] % MOD;
			for(int j = 0; j < n; ++j)
				CC[j] = C[j];
			for(int i = 0; i < m; ++i) {
				LL ans = 0;
				for(int j = 0; j < n; ++j) {
					if(P[j][i] > 0)
						ans += CC[j] * P[j][i] % MOD * XP[i][P[j][i] - 1] % MOD * B[j][i + 1] % MOD;
					CC[j] = CC[j] * XP[i][P[j][i]] % MOD;
				}
				printf("%lld%c", ans, (i == m - 1 ? '\n' : ' '));
			}
		}
		if(T != 0)
			printf("\n");
	}
	return 0;
}
