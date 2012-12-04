#include <iostream>
#include <hash_map>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cassert>
#define MAXN 1024
#define MAXL 32
#define INF 0x7fffffff
using namespace __gnu_cxx;
using namespace std;
class IDSet {
	struct cmp {
		bool operator() (const char* s1, const char* s2) const {
			return strcmp(s1, s2) == 0;
		}
	};
	hash_map<const char *, int, hash<const char*>, cmp> mp;
	char v[MAXN][MAXL];
	int sz;
public:
	IDSet() {
		sz = 0;
	}
	void clear() {
		sz = 0;
		mp.clear();
	}
	int size() {
		return sz;
	}
	int getId(const char *s) {
		if(mp.find(s) == mp.end()) {
			strcpy(v[sz], s);
			mp[v[sz]] = sz;
			sz++;
		}
		return mp[s];
	}
} ids;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, b;
		char tmp[MAXL];
		int p, q;
		vector<int> qs;
		vector<pair<int, int> > vp[MAXN];
		scanf("%d%d", &n, &b);
		for(int i = 0; i < n; ++i) {
			scanf("%s%*s", tmp);
			scanf("%d%d", &p, &q);
			//printf("%d %d\n", i, n);
			int id = ids.getId(tmp);
			vp[id].push_back(make_pair(p, q));
			qs.push_back(q);
		}
		sort(qs.begin(), qs.end());
		int le = 0, ri = qs.size() - 1, sz = ids.size();
		while(le <= ri) {
			int mi = (le + ri) / 2;
			int tq = qs[mi];
			int totcost = 0;
			for(int i = 0; i < sz; ++i) {
				int cost = INF;
				for(int j = 0; j < vp[i].size(); ++j) {
					if(vp[i][j].second >= tq && vp[i][j].first < cost)
						cost = vp[i][j].first;
				}
				if(cost == INF) {
					totcost = INF;
					break;
				}
				else {
					totcost += cost;
				}
			}
			if(totcost > b)
				ri = mi - 1;
			else
				le = mi + 1;
		}
		assert(ri >= 0);
		printf("%d\n", qs[ri]);
		ids.clear();
	}
	return 0;
}
