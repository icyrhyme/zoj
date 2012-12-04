#include <iostream>
#include <cstdio>
#define MAXN 512
using namespace std;
int oimg[MAXN][MAXN], nimg[MAXN][MAXN];
int mat[3][3] = {0, 1, 0, 1, 2, 1, 0, 1, 0};
int main() {
	int n, csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &oimg[i][j]);
		printf("Case %d:\n", csnum);
		++csnum;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) {
				if(i == 0 || j == 0 || i == n - 1 || j == n -1) {
					printf("%d%c", oimg[i][j], (j == n - 1 ? '\n' : ' '));
					continue;
				}
				int val = 0;
				for(int ii = -1; ii <= 1; ++ii)
					for(int jj = -1; jj <= 1; ++jj) {
						val += oimg[i + ii][j + jj] << mat[ii + 1][jj + 1];
					}
				val >>= 4;
				printf("%d%c", val, (j == n - 1 ? '\n' : ' '));
			}
	}
	return 0;
}
