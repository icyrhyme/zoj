#include <iostream>
#define MAXR 128
using namespace std;
int main() {
	int r;
	while(scanf("%d", &r) != EOF) {
		int pn, qn;
		int pfunc[MAXR], qfunc[MAXR];
		for(int i = 0; i < r; ++i)
			pfunc[i] = qfunc[i] = 0;
		scanf("%d", &pn);
		for(int i = 0; i <= pn; ++i) {
			int c;
			scanf("%d", &c);
			for(int j = 0; j < r; ++j) {
				pfunc[j] = pfunc[j] * j + c;
			}
		}
		scanf("%d", &qn);
		for(int i = 0; i <= qn; ++i) {
			int c;
			scanf("%d", &c);
			for(int j = 0; j < r; ++j) {
				qfunc[j] = qfunc[j] * j + c;
			}
		}
		int vis[MAXR], pc[MAXR], qc[MAXR];
		int cid = 0;
		fill(vis, vis + r, false);
		fill(pc, pc + r, -1);
		for(int i = 0; i < r; ++i) {
			if(vis[i])
				continue;
			int j;
			for(j = i; !vis[j]; j = pfunc[j]) {
				vis[j] = true;
			}
			for(; pc[j] == -1; j = pfunc[j])
				pc[j] = cid;
			++cid;
		}
		cid = 0;
		fill(vis, vis + r, false);
		fill(qc, qc + r, -1);
		for(int i = 0; i < r; ++i) {
			if(vis[i])
				continue;
			int j;
			for(j = i; !vis[j]; j = qfunc[j]) {
				vis[j] = true;
			}
			for(; qc[j] == -1; j = qfunc[j])
				qc[j] = cid;
			++cid;
		}
	}
}
