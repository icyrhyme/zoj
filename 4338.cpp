#include <cstdio>
#define LL long long
#define MAXN 22
using namespace std;
LL dp[MAXN];
LL s2id(int n, char p, char* s) {
	if(*s == '\0') {
		return 0;
	} else {
		LL ret = 0;
		for(char i = '0'; i < *s; ++i) {
			if(i == p)
				continue;
			ret += dp[n - 1];
		}
		ret += s2id(n - 1, *s, s + 1);
		return ret;
	}
}
void id2s(int n, LL id, char p, char* s) {
	if(id == 0) {
		*s = '\0';
	} else {
		int i;
		for(i = '0'; id >= dp[n - 1]; ++i) {
			if(i == p)
				continue;
			id -= dp[n - 1];
		}
		*s = i;
		id2s(n - 1, id, *s, s + 1);
	}
}
int main() {
	LL k;
	int n;
	char a[MAXL], b[MAXL];
	dp[0] = 1;
	for(int i = 1; i < MAXN; ++i)
		dp[i] = dp[i - 1] * 3;
	for(int i = 1; i < MAXN; ++i)
		dp[i] += dp[i - 1];
	while(scanf("%d%lld", &n, &k) != EOF) {
		scanf("%s", b);
		long long id = s2id(n, '0', b) - k;
		id2s(n, id, '0', b);
		puts(b);
	}
	return 0;
}
