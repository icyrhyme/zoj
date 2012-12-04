#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 34
#define MAXM (1<<17)
#define INF 0x7fffffff
using namespace std;
int n, a[2][MAXN], sum[2][MAXM];
void dfs_0(int idx, int t, int s)
{
	if(idx == n / 2)
	{
		sum[0][t] = s;
		return;
	}
	dfs_0(idx + 1, t << 1, s);
	dfs_0(idx + 1, (t << 1) ^ 1, s + a[0][idx]);
}
void dfs_1(int idx, int t, int s)
{
	if(idx == n - n / 2)
	{
		sum[1][t] = s;
		return;
	}
	dfs_1(idx + 1, t << 1, s);
	dfs_1(idx + 1, (t << 1) ^ 1, s + a[1][idx]);
}
int main()
{
	int cs;
	scanf("%d", &cs);
	while(cs--)
	{
		int total = 0;
		scanf("%d", &n);
		for(int i = 0; i < n / 2; ++i)
		{
			scanf("%d", &a[0][i]);
			total += a[0][i];
		}
		for(int i = 0; i < n - n / 2; ++i)
		{
			scanf("%d", &a[1][i]);
			total += a[1][i];
		}
		int half = total / 2;
		dfs_0(0, 0, 0);
		dfs_1(0, 0, 0);
		sort(sum[0], sum[0] + (1 << (n / 2)));
		sort(sum[1], sum[1] + (1 << (n - n / 2)));
		int ans = INF;
		for(int i = 0; i < (1 << (n / 2)); ++i)
		{
			int x = half - sum[0][i];
			if(x < 0)
				continue;
			int le = 0, ri = (1 << (n - n / 2));
			while(le <= ri)
			{
				int mid = (le + ri) / 2;
				if(sum[1][mid] > x)
					ri = mid - 1;
				else if(sum[1][mid] < x)
					le = mid + 1;
				else
				{
					le = ri = mid;
					++le;
					break;
				}
			}
			ans = min(ans, total - 2 * (sum[0][i] + sum[1][ri]));
		}
		printf("%d\n", ans);
	}
	return 0;
}
