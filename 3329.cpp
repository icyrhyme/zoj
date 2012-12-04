#include <iostream>
#define MAXN 512
using namespace std;
int n, K1, K2, K3, a, b, c;
double mata[MAXN][MAXN], vecb[MAXN];
double solve()
{
	memset(mata, 0, sizeof(mata));
	for(int i = 0; i <= n; ++i)
		vecb[i] = 1.0;
	for(int i = 0; i <= n; ++i)
	{
		mata[i][i] += 1;
		for(int ii = 1; ii <= K1; ++ii)
			for(int jj = 1; jj <= K2; ++jj)
				for(int kk = 1; kk <= K3; ++kk)
				{
					if(ii == a && jj == b && kk == c)
					{
						mata[i][0] -= 1.0 / (K1 * K2 * K3);
						continue;
					}
					int sum = i + ii + jj + kk;
					if(sum <= n)
						mata[i][sum] -= 1.0 / (K1 * K2 * K3);
				}
	}
	for(int i = n; i > 0; --i)
	{
		for(int j = i - 1; j >= 0; --j)
		{
			double mm = mata[j][i];
			mata[j][i] = 0;
			mata[j][0] -= mm * mata[i][0];
			vecb[j] -= mm * vecb[i];
		}
	}
	return vecb[0] / mata[0][0];
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d", &n, &K1, &K2, &K3, &a, &b, &c);
		memset(mata, 0, sizeof(mata));
		printf("%.15lf\n", solve());
	}
	return 0;
}
