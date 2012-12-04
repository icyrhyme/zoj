#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define INF 1000000000
#define MAXN 51
#define MAXW MAXN*450
using namespace std;
bool dp[MAXN][MAXW];
int a[MAXN * 2];
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for(int i = 0; i <= n / 2; ++i)
			fill(dp[i], dp[i] + MAXW, false);
		dp[0][0] = true;
		int w;
		for(int i = 1; i <= n; ++i) {
			w = a[i - 1];
			for(int j = min(i, n / 2); j > 0; --j) {
				for(int k = 0; k + w <= sum; ++k)
					dp[j][k + w] = dp[j][k + w] || dp[j - 1][k];
			}
		}
		int diff = INF, ans = -1;
		for(int i = 0; i <= sum; ++i) {
			if(dp[n / 2][i] && abs(sum - 2 * i) < diff) {
				ans = i;
				diff = abs(sum - 2 * i);
			}
		}
		int a = ans, b = sum - ans;
		if(a > b)
			swap(a, b);
		printf("%d %d\n", a, b);
	}
	return 0;
}
