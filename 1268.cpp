#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define MAXN 50000
using namespace std;
template <class T> class IDGen {
	map<T, int> mp;
public:
	int size() {
		return mp.size();
	}
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
		}
		return mp[elem];
	}
};
vector<int> e[MAXN];
int indeg[MAXN], n;
bool vis[MAXN], isok;
void dfs(int u) {
	if(!vis[u]) {
		vis[u] = true;
		vector<int>::iterator it;
		for(it = e[u].begin(); it != e[u].end() && isok; ++it) {
			dfs(*it);
		}
	}
	else {
		isok = false;
	}
}
bool isATree() {
	fill(indeg, indeg + n, 0);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < e[i].size(); ++j)
			++indeg[e[i][j]];
	}
	int root = -1, cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; ++i) {
		if(indeg[i] == 0) {
			root = i;
			cnt0++;
		}
		else {
			cnt1++;
		}
	}
	if(cnt0 != 1 || cnt1 != n - 1)
		return false;
	fill(vis, vis + n, false);
	isok = true;
	dfs(root);
	if(!isok)
		return false;
	for(int i = 0; i < n; ++i)
		if(!vis[i])
			return false;
	return true;
}
int main() {
	int a, b, csnum = 1;
	while(scanf("%d%d", &a, &b) != EOF) {
		if(a == -1 && b == -1)
			break;
		else if(a == 0 && b == 0) {
			printf("Case %d is a tree.\n", csnum);
			++csnum;
			continue;
		}
		for(int i = 0; i < MAXN; ++i)
			e[i].clear();
		IDGen<int> ids;
		int u, v;
		u = ids.getId(a);
		v = ids.getId(b);
		e[u].push_back(v);
		while(scanf("%d%d", &a, &b) != EOF) {
			if(a == 0 && b == 0)
				break;
			u = ids.getId(a);
			v = ids.getId(b);
			e[u].push_back(v);
		}
		n = ids.size();
		if(isATree()) {
			printf("Case %d is a tree.\n", csnum);
		}
		else {
			printf("Case %d is not a tree.\n", csnum);
		}
		csnum++;
	}
}
