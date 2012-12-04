#include <cstdio>
#include <cstring>
#define MAXC 10005
using namespace std;
int P, T[4];
int dp[MAXC], ans[MAXC][4], map[4] = {1, 5, 10, 25};
void ZeroOnePack(int idx, int amt)
{
	int w = amt * map[idx], v = amt;
	for(int i = P; i >= w; --i)
		if(dp[i - w] >= 0 && dp[i - w] + v > dp[i])
		{
			dp[i] = dp[i - w] + v;
			memcpy(ans[i], ans[i - w], 4 * sizeof(int));
			ans[i][idx] += v;
		}
}
void CompletePack(int idx)
{
	int w = map[idx], v = 1;
	for(int i = w; i <= P; ++i)
		if(dp[i - w] >= 0 && dp[i - w] + v > dp[i])
		{
			dp[i] = dp[i - w] + v;
			memcpy(ans[i], ans[i - w], 4 * sizeof(int));
			ans[i][idx] += v;
		}
}
void MultiplePack(int idx)
{
	if(map[idx] * T[idx] >= P)
	{
		CompletePack(idx);
		return;
	}
	int k = 1, rem = T[idx];
	while(k < rem)
	{
		ZeroOnePack(idx, k);
		rem -= k;
		k <<= 1;
	}
	ZeroOnePack(idx, rem);
}
int main()
{
	while(scanf("%d%d%d%d%d", &P, &T[0], &T[1], &T[2], &T[3]) != EOF)
	{
		if(!T[0] && !T[1] && !T[2] && !T[3] && !P)
			break;
		memset(dp, -1, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		dp[0] = 0;
		for(int i = 0; i < 4; ++i)
			MultiplePack(i);
		if(dp[P] < 0)
			printf("Charlie cannot buy coffee.\n");
		else
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", ans[P][0], ans[P][1], ans[P][2], ans[P][3]);
	}
	return 0;
}
