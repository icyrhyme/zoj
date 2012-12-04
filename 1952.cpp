#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define MAXL 64
#define MAXN 256
using namespace std;
template <class T>
class IDSet {
	map<T, int> mp;
public:
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
		}
		return mp[elem];
	}
};
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		char stru[MAXL], strv[MAXL];
		vector<int> e[MAXN], ew[MAXN];
		vector<int> ws;
		IDSet<string> ids;
		int u, v, w;
		for(int i = 0; i < n; ++i) {
			e[i].clear();
			ew[i].clear();
		}
		for(int i = 0; i < m; ++i) {
			scanf("%s%s%d", stru, strv, &w);
			u = ids.getId((string)stru);
			v = ids.getId((string)strv);
			e[u].push_back(v);
			ew[u].push_back(w);
			e[v].push_back(u);
			ew[v].push_back(w);
			ws.push_back(w);
		}
		int s, t;
		scanf("%s%s", stru, strv);
		s = ids.getId((string)stru);
		t = ids.getId((string)strv);
		sort(ws.begin(), ws.end());
		ws.erase(unique(ws.begin(), ws.end()), ws.end());
		int le = 0, ri = ws.size() - 1;
		bool vis[MAXN];
		while(le <= ri) {
			int mi = (le + ri) >> 1;
			w = ws[mi];
			fill(vis, vis + n, false);
			stack<int> stk;
			stk.push(s);
			while(!stk.empty()) {
				u = stk.top();
				stk.pop();
				if(!vis[u]) {
					vis[u] = true;
					for(int i = 0; i < e[u].size(); ++i) {
						if(ew[u][i] >= w)
							stk.push(e[u][i]);
					}
				}
			}
			if(vis[t])
				le = mi + 1;
			else
				ri = mi - 1;
		}
		printf("Scenario #%d\n", csnum);
		csnum++;
		printf("%d tons\n\n", ws[ri]);
	}
	return 0;
}
