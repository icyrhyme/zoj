#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXR 10
#define L_MSK 0xfff0
#define P_MSK 0xf
#define M_MOVE 0
#define M_SWITCH_ON 1
#define M_SWITCH_OFF 2
#define INIT_STATE make_state(0, (1 << 0))
using namespace std;
inline int make_state(int pos, int lstate) {
	return (lstate << 4) + pos;
}
inline int get_pos(int state) {
	return (state & P_MSK);
}
inline int get_lstate(int state) {
	return (state & L_MSK) >> 4;
}
struct move {
	int m, p;
};
move make_move(int m, int p) {
	move tmp;
	tmp.m = m;
	tmp.p = p;
	return tmp;
}
int main() {
	int r, d, s, csnum = 1;
	vector<int> dg[MAXR], sg[MAXR];
	while(scanf("%d%d%d", &r, &d, &s) != EOF) {
		if(r == 0 && d == 0 && s == 0)
			break;
		for(int i = 0; i < r; ++i) {
			dg[i].clear();
			sg[i].clear();
		}
		int u, v;
		for(int i = 0; i < d; ++i) {
			scanf("%d%d", &u, &v);
			--u, --v;
			dg[u].push_back(v);
			dg[v].push_back(u);
		}
		for(int i = 0; i < s; ++i) {
			scanf("%d%d", &u, &v);
			--u, --v;
			sg[u].push_back(v);
		}
		bool vis[1 << (MAXR + 4)];
		int pre[1 << (MAXR + 4)];
		move pmove[1 << (MAXR + 4)];
		memset(vis, false, sizeof(vis));
		int state = INIT_STATE;
		queue<int> q;
		q.push(state);
		vis[state] = true;
		while(!q.empty()) {
			state = q.front();
			q.pop();
			int pos = get_pos(state);
			int lstate = get_lstate(state);
			//printf("%d %d\n", pos, lstate);
			int np, nls;
			vector<int>::iterator it;
			//move
			for(it = dg[pos].begin(); it != dg[pos].end(); ++it) {
				if(lstate & (1 << *it)) {
					np = *it;
					int ns = make_state(np, lstate);
					if(!vis[ns]) {
						vis[ns] = true;
						q.push(ns);
						pre[ns] = state;
						pmove[ns] = make_move(M_MOVE, *it);
						//printf("-> %d %d\n", np, lstate);
					}
				}
			}
			//turn the switch
			for(it = sg[pos].begin(); it != sg[pos].end(); ++it) {
				if(*it != pos) {
					nls = lstate ^ (1 << *it);
					int ns = make_state(pos, nls);
					if(!vis[ns]) {
						vis[ns] = true;
						q.push(ns);
						pre[ns] = state;
						if(lstate & (1 << *it))
							pmove[ns] = make_move(M_SWITCH_OFF, *it);
						else
							pmove[ns] = make_move(M_SWITCH_ON, *it);
						//printf("-> %d %d\n", pos, nls);
					}
				}
			}
		}
		printf("Villa #%d\n", csnum);
		csnum++;
		int fs = make_state(r - 1, 1 << (r - 1));
		if(!vis[fs]) {
			printf("The problem cannot be solved.\n");
		}
		else {
			vector<move> vm;
			for(int i = fs; i != INIT_STATE; i = pre[i]) {
				vm.push_back(pmove[i]);
			}
			vector<move>::reverse_iterator it;
			printf("The problem can be solved in %d steps:\n", vm.size());
			for(it = vm.rbegin(); it != vm.rend(); ++it) {
				if(it->m == M_MOVE) {
					printf("- Move to room %d.\n", it->p + 1);
				}
				else if(it->m == M_SWITCH_ON) {
					printf("- Switch on light in room %d.\n", it->p + 1);
				}
				else if(it->m == M_SWITCH_OFF) {
					printf("- Switch off light in room %d.\n", it->p + 1);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
