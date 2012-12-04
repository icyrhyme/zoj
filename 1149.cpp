#include <iostream>
#define MAXN 150000
using namespace std;
bool dp[MAXN];
int lim, a[MAXN];
void CompletePack(int c)
{
	for(int i = c; i <= lim; ++i)
		dp[i] |= dp[i - c];
}
void ZeroOnePack(int c)
{
	for(int i = lim; i >= c; --i)
		dp[i] |= dp[i - c];
}
void MultiplePack(int c, int amt)
{
	if(c * amt >= lim)
	{
		CompletePack(c);
		return;
	}
	int k = 1;
	while(k < amt)
	{
		ZeroOnePack(k * c);
		amt -= k;
		k <<= 1;
	}
	ZeroOnePack(amt * c);
}
int main()
{
	int cs = 1;
	while(1)
	{
		for(int i = 0; i < 6; ++i)
			scanf("%d", &a[i]);
		if(!(a[0] || a[1] || a[2] || a[3] || a[4] || a[5]))
			break;
		lim = a[0] + 2 * a[1] + 3 * a[2] + 4 * a[3] + 5 * a[4] + 6 * a[5];
		printf("Collection #%d:\n", cs++);
		if(lim % 2 == 1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		lim /= 2;
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		for(int i = 0; i < 6; ++i)
			MultiplePack(i + 1, a[i]);
		if(dp[lim])
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
	return 0;
}
