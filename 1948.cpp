#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <cassert>
#define MAXL 16
#define MAXID 1000000
#define MAXT 1000
#define make_triple(a,b,c) make_pair(a,make_pair(b,c))
#define FIRST first
#define SECOND second.first
#define THIRD second.second
using namespace std;
int tn[MAXID];
int ptc[MAXT];
int tt[MAXT];
int main() {
	int csnum = 1, n, id;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		memset(tn, -1, sizeof(tn));
		memset(ptc, 0, sizeof(int) * n);
		for(int i = 0; i < n; ++i) {
			int k;
			scanf("%d", &k);
			while(k--) {
				scanf("%d", &id);
				assert(tn[id] == -1);
				tn[id] = i;
			}
		}
		char cmd[MAXL];
		int pts = 0, tts = 0, tid;
		priority_queue<pair<int, pair<int, int> > > q;
		printf("Scenario #%d\n", csnum);
		csnum++;
		while(true) {
			scanf("%s", cmd);
			if(cmd[0] == 'S')
				break;
			else if(cmd[0] == 'E') {
				scanf("%d", &id);
				tid = tn[id];
				if(ptc[tid]++ == 0) {
					tt[tid] = tts++;
				}
				//printf("Eq %d %d %d %d\n", tid, -tt[tid], -pts, id);
				q.push(make_triple(-tt[tid], -(pts++), id));
			}
			else {
				pair<int, pair<int, int> > tr;
				tr = q.top();
				q.pop();
				id = tr.THIRD;
				printf("%d\n", id);
				tid = tn[id];
				ptc[tid]--;
			}
		}
		putchar('\n');
	}
	return 0;
}
