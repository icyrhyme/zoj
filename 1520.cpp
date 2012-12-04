#include <iostream>
#include <vector>
#define MAXC 1024
using namespace std;
int main()
{
	int M, L;
	while(scanf("%d%d", &M, &L) != EOF)
	{
		if(M == 0 && L == 0)
			break;
		bool dp[MAXC];
		vector<int> vi;
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		int n, sum = 0, last[MAXC];
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			int w;
			scanf("%d", &w);
			vi.push_back(w);
			sum += w;
			for(int j = M; j >= w; --j)
				if(!dp[j] && dp[j - w])
				{
					dp[j] |= dp[j - w];
					last[j] = i; 
				}
		}
		int i, j;
		for(j = M; j >= 0; --j)
			if(dp[j])
				break;
		int msum = 0;
		vector<int> ans;
		while(j > 0)
		{
			ans.push_back(last[j]);
			msum += vi[last[j]];
			j -= vi[last[j]];
		}
		if(sum - msum > L)
			printf("Impossible to distribute\n");
		else
		{
			sort(ans.begin(), ans.end());
			printf("%d", ans.size());
			for(int i = 0; i < ans.size(); ++i)
				printf(" %d", ans[i] + 1);
			printf("\n");
		}
	}
	return 0;
}
