#include <iostream>
#include <vector>
#include <cassert>
#define MAXN 128
using namespace std;
bool g[MAXN][MAXN];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		memset(g, false, sizeof(g));
		scanf("%d", &n);
		for(int i = 0; i < n * (n - 1) / 2; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			g[u][v] = true;
		}
		int head, tail, pre[MAXN];
		head = tail = 0, pre[0] = -1;
		for(int i = 1; i < n; ++i) {
			if(g[head][i]) {
				pre[i] = head;
				head = i;
				continue;
			}
			else if(g[i][tail]) {
				pre[tail] = i;
				tail = i;
				pre[tail] = -1;
				continue;
			}
			int j;
			for(j = head; pre[j] != -1; j = pre[j])
				if(g[pre[j]][i] && g[i][j]) {
					pre[i] = pre[j];
					pre[j] = i;
					break;
				}
		}
		vector<int> ans;
		for(int i = head; i >= 0; i = pre[i]) {
			ans.push_back(i);
		}
		assert(ans.size() == n);
		for(int i = ans.size() - 1; i >= 0; --i) {
			printf("%d", ans[i] + 1);
			if(i == 0)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
