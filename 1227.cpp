#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#define MAXN 41
using namespace std;
int bd[MAXN][4];
bool vis[MAXN][MAXN][MAXN][MAXN];
int n, ans, maxans;
int v[4];
class myset {
	bool data[24];
	int sz;
public:
	int size() {
		return sz;
	}
	void clear() {
		memset(data, false, sizeof(data));
		sz = 0;
	}
	bool find(int val) {
		return data[val];
	}
	void insert(int val) {
		data[val] = true;
		++sz;
	}
	void erase(int val) {
		data[val] = false;
		--sz;
	}
};
myset s;
void search() {
	if(!vis[v[0]][v[1]][v[2]][v[3]]) {
		vis[v[0]][v[1]][v[2]][v[3]] = true;
		maxans = max(maxans, ans);
		if(s.size() == 5)
			return;
		for(int i = 0; i < 4; ++i) {
			if(v[i] < n) {
				if(!s.find(bd[v[i]][i])) {
					s.insert(bd[v[i]][i]);
				}
				else {
					s.erase(bd[v[i]][i]);
					++ans;
				}
				++v[i];
				search();
				--v[i];
				if(!s.find(bd[v[i]][i])) {
					s.insert(bd[v[i]][i]);
					--ans;
				}
				else {
					s.erase(bd[v[i]][i]);
				}
			}
		}
	}
}
int main() {
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 4; ++j)
				scanf("%d", &bd[i][j]);
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j)
				for(int k = 0; k <= n; ++k)
					fill(vis[i][j][k], vis[i][j][k] + n + 1, false);
		//memset(vis, false, sizeof(vis));
		maxans = ans = 0;
		s.clear();
		for(int i = 0; i < 4; ++i)
			v[i] = 0;
		search();
		printf("%d\n", maxans);
	}
	return 0;
}
