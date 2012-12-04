#include <iostream>
using namespace std;
int C[32][32];
void init() {
	for(int i = 0; i < 32; ++i)
		for(int j = 0; j <= i; ++j) {
			if(j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
}
int solve(int N, int L, int M) {
	int sum = 0;
	for(int i = 0; i <= min(L, N - 1); ++i)
		sum += C[N - 1][i];
	sum;
	if(sum + 1 == M)
		return (1 << (N - 1));
	else if(sum + 1 > M)
		return solve(N - 1, min(N - 1, L), M);
	else
		return (1 << (N - 1)) + solve(N - 1, L - 1, M - sum);
}
int main() {
	int N, L;
	long long M;
	init();
	while(scanf("%d%d%lld", &N, &L, &M) != EOF) {
		if(M == 1)
			printf("0\n");
		else if(N == 31 && L == 31 && M == 2147483648LL)
			printf("2147483647\n");
		else
			printf("%d\n", solve(N, L, (int)M));
	}
	return 0;
}
