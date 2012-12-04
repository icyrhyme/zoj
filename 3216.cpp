#include <iostream>
#include <cstring>
#define MAXN 32 
#define MOD 1000000007
#define LL long long
using namespace std;
void matrix_multi(int c[][MAXN], int a[][MAXN], int b[][MAXN], int a_n, int b_m, int a_m) {
	int temp[MAXN][MAXN];
	memset(temp, 0, sizeof(temp));
	for(int i = 0; i < a_n; ++i)
		for(int j = 0; j < b_m; ++j)
			for(int k = 0; k < a_m; ++k) {
				temp[i][j] = ((LL)temp[i][j] + (LL)a[i][k] * b[k][j]) % MOD;
			}
	for(int i = 0; i < a_n; ++i)
		for(int j = 0; j < b_m; ++j)
			c[i][j] = temp[i][j];
}

void matrix_exp(int c[][MAXN], int a[][MAXN], int n, int power) {
	int res[MAXN][MAXN], temp[MAXN][MAXN];
	memset(res, 0, sizeof(res));
	for(int i = 0; i < n; ++i)
		res[i][i] = 1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			temp[i][j] = a[i][j];
	for(; power; power >>= 1) {
		if((power & 1) != 0) {
			matrix_multi(res, res, temp, n, n, n);
		}
		matrix_multi(temp, temp, temp, n, n, n);
	}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			c[i][j] = res[i][j];
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if(n < k) {
			printf("0\n");
			continue;
		}
		int vec[1][MAXN], a[MAXN][MAXN];
		memset(vec, 0, sizeof(vec));
		memset(a, 0, sizeof(a));
		vec[0][k - 1] = 1;
		for(int i = 0; i < k - 1; ++i) {
			a[i + 1][i] = 1;
		}
		a[0][k - 1] += 1;
		a[k - 1][k - 1] += 1;
		matrix_exp(a, a, k, n - k);
		matrix_multi(vec, vec, a, 1, k, k);
		printf("%d\n", vec[0][k - 1]);
	}
	return 0;
}

