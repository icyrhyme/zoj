#include <iostream>
#define MAXM 128
#define MAXN 100005
#define INF 1000000000
using namespace std;
int main() {
	int M, N;
	int lst[MAXM], prod[MAXN];
	double pri[MAXN];
	double opt[MAXM];
	while(scanf("%d%d", &M, &N) != EOF) {
		if(M == 0 && N == 0)
			break;
		for(int i = 0; i < M; ++i)
			scanf("%d", &lst[i]);
		for(int i = 0; i < N; ++i)
			scanf("%d%lf", &prod[i], &pri[i]);
		for(int i = 0; i <= M; ++i)
			opt[i] = INF;
		opt[0] = 0;
		for(int i = 0; i < N; ++i)
			for(int j = M; j >= 1; --j) {
				if(prod[i] == lst[j - 1])
					opt[j] = min(opt[j], opt[j - 1] + pri[i]);
			}
		if(opt[M] != INF)
			printf("%.2lf\n", opt[M]);
		else
			printf("Impossible\n");
	}
	return 0;
}
