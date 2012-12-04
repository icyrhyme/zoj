#include <iostream>
#include <vector>
#define MAXN 1121
using namespace std;
int dp[MAXN][187][15];
int main() {
	bool isPrime[MAXN];
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i < MAXN; ++i)
		if(isPrime[i])
			for(int j = i; j * i < MAXN; ++j)
				isPrime[j * i] = false;
	vector<int> primes;
	for(int i = 2; i < MAXN; ++i)
		if(isPrime[i])
			primes.push_back(i);
	
	memset(dp, 0, sizeof(dp));
	dp[primes[0]][0][1] = 1;
	for(int i = 0; i < primes.size(); ++i)
		dp[0][i][0] = 1;
	/*for(int i = 0; i < primes.size(); ++i)
		for(int j = i; j < primes.size(); ++j)
			dp[primes[i]][j][1] = 1;*/
	for(int i = 1; i < primes.size(); ++i)
		for(int j = 1; j < 15; ++j) {
			for(int k = 0; k < primes[i]; ++k)
				dp[k][i][j] += dp[k][i - 1][j];
			for(int k = primes[i]; k < MAXN; ++k)
				dp[k][i][j] += dp[k - primes[i]][i - 1][j - 1] + dp[k][i - 1][j];
		}
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		if(n == 0 && k == 0)
			break;
		printf("%d\n", dp[n][primes.size() - 1][k]);
	}
	return 0;
}
