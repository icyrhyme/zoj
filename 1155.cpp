#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#define MAXL 18
#define MAXT 9
#define MAXS (1<<MAXL)
using namespace std;
/*
test set:
1
1
15
1 2
1 3
2 3
2 4
2 5
4 5
3 5
3 6
5 6
4 7
4 8
7 8
5 8
5 9
8 9
 */
int tri[9][3][2] = {
	{{1, 2}, {2, 3}, {1, 3}},
	{{2, 4}, {4, 5}, {2, 5}},
	{{2, 3}, {2, 5}, {3, 5}},
	{{3, 5}, {5, 6}, {3, 6}},
	{{4, 7}, {7, 8}, {4, 8}},
	{{4, 5}, {4, 8}, {5, 8}},
	{{5, 8}, {8, 9}, {5, 9}},
	{{5, 6}, {5, 9}, {6, 9}},
	{{6, 9}, {9, 10}, {6, 10}},
};
template<class T>
class bimap {
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
int win[MAXS][MAXT + 1];
bimap<pair<int, int> > bm;
vector<int> tri_msk;
int solve(int s, int tri, int trio) {
	if(win[s][tri] != -1)
		return win[s][tri];

	if(tri >= 5)
		win[s][tri] = 1;
	if(s == MAXS - 1 && tri < 5)
		win[s][tri] = 0;
	if(win[s][tri] != -1)
		return win[s][tri];

	win[s][tri] = 1;
	for(int i = 0; i < MAXL; ++i) {
		if(s & (1 << i))
			continue;
		int found = 0;
		for(int j = 0; j < tri_msk.size(); ++j) {
			if((tri_msk[j] & (1 << i)) && (tri_msk[j] & (s | (1 << i))) == tri_msk[j])
				++found;
		}
		if(found) {
			//pair<int, int> p = bm.getElem(i);
			//printf("(%d, %d)", p.first, p.second);
			if(solve(s | (1 << i), tri + found, trio)) {
				win[s][tri] = 1;
				return win[s][tri];
			}
		}
		else {
			//pair<int, int> p = bm.getElem(i);
			//printf("(%d, %d)", p.first, p.second);
			win[s][tri] &= solve(s | (1 << i), trio, tri);
		}
	}
	win[s][tri] = !win[s][tri];
	return win[s][tri];
}
int main() {
	int cs;
	for(int i = 0; i < 9; ++i) {
		int msk = 0;
		for(int j = 0; j < 3; ++j) {
			int id = bm.getId(make_pair(tri[i][j][0], tri[i][j][1]));
			msk = (msk | (1 << id));
		}
		tri_msk.push_back(msk);
	}
	memset(win, -1, sizeof(win));
	scanf("%d", &cs);
	//cs = 1;
	while(cs--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			int m;
			scanf("%d", &m);
			int msk = 0;
			int turn = 1;
			int tria = 0, trib = 0;
			for(int j = 0; j < m; ++j) {
				int u, v;
				scanf("%d%d", &u, &v);
				int id = bm.getId(make_pair(u, v));
				bool occur = false;
				for(int k = 0; k < tri_msk.size(); ++k) {
					if((tri_msk[k] & (1 << id)) && (tri_msk[k] & (msk | (1 << id))) == tri_msk[k]) {
						if(turn)
							++tria;
						else
							++trib;
						occur = true;
					}
				}
				if(!occur)
					turn = !turn;
				msk = (msk | (1 << id));
			}
			int res;
			if(turn) {
				//printf("aturn:%d %d %d\n", msk, tria, trib);
				res = solve(msk, tria, trib);
			}
			else {
				//printf("bturn:%d %d %d\n", msk, trib, tria);
				res = solve(msk, trib, tria);
				res = !res;
			}
			printf("Game %d: %c wins.\n", i + 1, (res ? 'A' : 'B'));
		}
		if(cs != 0)
			putchar('\n');
	}
	return 0;
}
