#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 256
using namespace std;
int arr[MAXN];
int n, K, mn;
double a, b, memo[MAXN][MAXN];
double magicMachine(int le, int ri) {
	if(le > ri)
		return 0;
	if(memo[le][ri] == -1.0) {
		memo[le][ri] = 0;
		if(le <= ri) {
			for(int i = le; i <= ri; ++i) {
				if(arr[i] == mn)
					memo[le][ri] += a;
				memo[le][ri] += magicMachine(le, i - 1) * b;
				memo[le][ri] += magicMachine(i + 1, ri) * (1 - a - b);
			}
			memo[le][ri] /= (ri - le + 1);
		}
	}
	return memo[le][ri];
}
double solve() {
	int newarr[MAXN];
	for(int i = 0; i < n; ++i)
		newarr[i] = arr[i];
	sort(newarr, newarr + n);
	int len = (unique(newarr, newarr + n) - newarr);
	if(len < K)
		return 0;
	mn = newarr[K - 1];
	for(int i = 0; i < n; ++i)
		fill(memo[i], memo[i] + n, -1.0); 
	return magicMachine(0, n - 1);
}
int main() {
	while(scanf("%d", &n) != EOF) {
		if(n < 0)
			break;
		for(int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		scanf("%d%lf%lf", &K, &a, &b);
		printf("%.3lf\n", solve());
	}
	return 0;
}
