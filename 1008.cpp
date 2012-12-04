#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#define MAXN 5
#define UP 0
#define RI 1
#define BO 2
#define LE 3
using namespace std;
struct board {
	int data[4];
	bool operator<(const board& o) const {
		for(int i = 0; i < 4; ++i)
			if(data[i] != o.data[i])
				return data[i] < o.data[i];
		return false;
	}
};
board ans[MAXN][MAXN];
int cnt[MAXN * MAXN];
board coll[MAXN * MAXN];
int n, sz;
inline bool isok(int x, int y, board b) {
	bool upflag = false, leflag = false;
	if(x == 0 || ans[x - 1][y].data[BO] == b.data[UP])
		upflag = true;
	if(y == 0 || ans[x][y - 1].data[RI] == b.data[LE])
		leflag = true;
	return (upflag && leflag);
}
bool search(int x, int y) {
	if(x == n)
		return true;
	for(int i = 0; i < sz; ++i) {
		if(cnt[i] > 0 && isok(x, y, coll[i])) {
			--cnt[i];
			ans[x][y] = coll[i];
			if(y + 1 == n) {
				if(search(x + 1, 0))
					return true;
			}
			else {
				if(search(x, y + 1))
					return true;
			}
			++cnt[i];
		}
	}
	return false;
}
int main() {
	int csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		map<board, int> mp;
		for(int i = 0; i < n * n; ++i) {
			board tmp;
			for(int j = 0; j < 4; ++j) {
				scanf("%d", &tmp.data[j]);
			}
			if(mp.find(tmp) == mp.end())
				mp[tmp] = 1;
			else
				++mp[tmp];
		}
		sz = mp.size();
		map<board, int>::iterator it;
		int i;
		for(it = mp.begin(), i = 0; it != mp.end(); ++it, ++i) {
			cnt[i] = it->second;
			coll[i] = it->first;
		}
		if(csnum != 1)
			printf("\n");
		if(search(0, 0))
			printf("Game %d: Possible\n", csnum);
		else
			printf("Game %d: Impossible\n", csnum);
		++csnum;
	}
	return 0;
}
