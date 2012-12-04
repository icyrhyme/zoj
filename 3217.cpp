#include <iostream>
#include <vector>
#define MAXLEN 65535
#define MAXN 1024
#define ERROR -1
#define LL long long
#define MOD 1000000007
#define DEBUG
using namespace std;
char treeStr[MAXLEN];
vector<int> tree[MAXN];
int N, pos, cnt[MAXN];
LL C[MAXN][MAXN], ans[MAXN];
void DFS(int id) {
	tree[id].clear();
	cnt[id] = 1;
	++pos;
	++N;
	while(true) {
		if(treeStr[pos] == '(') {
			if(treeStr[pos + 1] == ')') {
				pos += 2;
				continue;
			}
			int child = N;
			DFS(child);
			tree[id].push_back(child);
			cnt[id] += cnt[child];
			++pos;
		}
		else
			return;
	}
}

void DP(int id) {
	int sz = tree[id].size();
	if(sz == 0) {
		ans[id] = 1;
		return;
	}
	for(int i = 0; i < sz; ++i)
		DP(tree[id][i]);
	LL ret = 1;
	int rem = cnt[id] - 1;
	for(int i = 0; i < sz; ++i) {
		ret = (ret * C[rem][cnt[tree[id][i]]]) % MOD * ans[tree[id][i]] % MOD;
		rem -= cnt[tree[id][i]];
	}
	ans[id] = ret;
}
int main() {
	for(int i = 0; i < MAXN; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0 || i == j)
				C[i][j] = 1;
			else {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
				if(C[i][j] >= MOD)
					C[i][j] -= MOD;
			}
		}
	}
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		scanf("%s", treeStr);
		pos = 0;
		N = 0;
		DFS(N);
		/*
		for(int i = 0; i < N; ++i) {
			printf("%d: ", i);
			for(int j = 0; j < tree[i].size(); ++j)
				printf("%d ", tree[i][j]);
			printf("\n");
		}
		*/
		DP(0);
		printf("%lld\n", ans[0]);
	}
	return 0;
}
