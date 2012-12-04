#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 1024
#define MAXM MAXN
using namespace std;
class Hungary {
	vector<int> e[MAXN];
	int n, m, match[MAXN], rmatch[MAXM];
	bool vis[MAXN];
	bool _augment(int u) {
		if(!vis[u]) {
			vis[u] = true;
			vector<int>::iterator it;
			for(it = e[u].begin(); it != e[u].end(); ++it) {
				if(rmatch[*it] == -1 || _augment(rmatch[*it])) {
					match[u] = *it;
					rmatch[*it] = u;
					return true;
				}
			}
		}
		return false;
	}
public:
	void init(int n, int m) {
		this->n = n;
		this->m = m;
		for(int i = 0; i < n; ++i)
			e[i].clear();
	}
	void addEdge(int u, int v) {
		e[u].push_back(v);
	}
	int maxMatch() {
		fill(match, match + n, -1);
		fill(rmatch, rmatch + m, -1);
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			fill(vis, vis + n, false);
			if(_augment(i))
				++cnt;
		}
		return cnt;
	}
} h;
int code[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
int main() {
	bool re[10][10];
	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j) {
			if(i == j) {
				re[i][j] = false;
				continue;
			}
			if((code[i] & (~code[j])) == code[i] - code[j])
				re[i][j] = true;
			else
				re[i][j] = false;
		}
	int n;
	while(scanf("%d", &n) != EOF) {
		int a[MAXN];
		h.init(n, n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j)
				if(re[a[i]][a[j]]) {
					h.addEdge(i, j);
				}
		printf("%d\n", n - h.maxMatch());
	}
	return 0;
}
