#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 1024
using namespace std;
class StableMarriage {
	int wlst[MAXN][MAXN];
	int mrnk[MAXN][MAXN];
	int n, match[MAXN], rmatch[MAXN], work[MAXN];
public:
	void init(int n) {
		this->n = n;
	}
	void add(char sex, int p, int rnk, int op) {
		if(sex == 'm') {
			wlst[p][rnk] = op;
		}
		else {
			mrnk[p][op] = rnk;
		}
	}
	void stableMatch() {
		memset(work, 0, sizeof(int) * n);
		memset(match, -1, sizeof(int) * n);
		memset(rmatch, -1, sizeof(int) * n);
		queue<int> q;
		for(int i = 0; i < n; ++i)
			q.push(i);
		while(!q.empty()) {
			int m = q.front();
			q.pop();
			int w = wlst[m][work[m]++];
			if(rmatch[w] == -1) {
				match[m] = w;
				rmatch[w] = m;
			}
			else {
				int om = rmatch[w];
				if(mrnk[w][m] < mrnk[w][om]) {
					match[om] = -1;
					match[m] = w;
					rmatch[w] = m;
					q.push(om);
				}
				else {
					q.push(m);
				}
			}
		}
	}
	int getMatch(int m) {
		return match[m];
	}
} sm;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, p;
		scanf("%d", &n);
		sm.init(n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &p);
				--p;
				sm.add('m', i, j, p);
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &p);
				--p;
				sm.add('w', i, j, p);
			}
		}
		sm.stableMatch();
		for(int i = 0; i < n; ++i) {
			printf("%d\n", sm.getMatch(i) + 1);
		}
	}
}
