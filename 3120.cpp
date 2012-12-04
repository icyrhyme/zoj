#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAXN 32
using namespace std;
class StableMarriage {
	int wlst[MAXN][MAXN], mlst[MAXN][MAXN];
	int wrnk[MAXN][MAXN], mrnk[MAXN][MAXN];
	int n, match[MAXN], rmatch[MAXN];
public:
	void init(int n) {
		this->n = n;
	}
	void add(char sex, int p, int rnk, int sp) {
		if(sex == 'm') {
			wlst[p][rnk] = sp;
			wrnk[p][sp] = rnk;
		}
		else {
			mlst[p][rnk] = sp;
			mrnk[p][sp] = rnk;
		}
	}
	void stableMatch() {
		int work[MAXN];
		memset(match, -1, sizeof(int) * n);
		memset(rmatch, -1, sizeof(int) * n);
		memset(work, 0, sizeof(int) * n);
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
					match[m] = w;
					rmatch[w] = m;
					match[om] = -1;
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
};
template <class T>
class IDGen {
	map<T, int> mp;
	vector<T> v;
public:
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
			v.push_back(elem);
		}
		return mp[elem];
	}
	T getElem(int id) {
		return v[id];
	}
};
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		IDGen<char> mid, wid;
		char let[64];
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", let);
			mid.getId(let[0]);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%s", let);
			wid.getId(let[0]);
		}
		StableMarriage sm;
		sm.init(n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", let);
			int m = mid.getId(let[0]);
			for(int j = 2; let[j]; ++j) {
				int w = wid.getId(let[j]);
				sm.add('m', m, j - 2, w);
			}
		}
		for(int i = 0; i < n; ++i) {
			scanf("%s", let);
			int w = wid.getId(let[0]);
			for(int j = 2; let[j]; ++j) {
				int m = mid.getId(let[j]);
				sm.add('w', w, j - 2, m);
			}
		}
		sm.stableMatch();
		vector<pair<char, char> > vp;
		for(int i = 0; i < n; ++i) {
			char m, w;
			m = mid.getElem(i);
			w = wid.getElem(sm.getMatch(i));
			vp.push_back(make_pair(m, w));
		}
		sort(vp.begin(), vp.end());
		for(int i = 0; i < vp.size(); ++i) {
			printf("%c %c\n", vp[i].first, vp[i].second);
		}
		if(cs != 0)
			putchar('\n');
	}
}
