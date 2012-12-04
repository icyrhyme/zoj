#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <cstdio>
#include <cassert>
#define MAXN 32
using namespace std;
struct mat {
	int n;
	bool data[MAXN][MAXN];
	void copy(const mat& that) {
		n = that.n;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				data[i][j] = that.data[i][j];
	}
} pat[MAXN];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
void init() {
	for(int i = 0; i < 32; ++i) {
		int p = i;
		for(int j = 0; j < 5; ++j, p >>= 1)
			if(p & 1) {
				pat[i].data[1 + dx[j]][1 + dy[j]] = true;
			}
			else {
				pat[i].data[1 + dx[j]][1 + dy[j]] = false;
			}
	}
}
bool canBeSub(mat& a, int x, int y, mat& b) {
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			if(a.data[x - 1 + i][y - 1 + j] == false
			&& b.data[i][j] == true)
				return false;
	return true;
}

void add(mat& a, int x, int y, mat& b) {
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			a.data[x - 1 + i][y - 1 + j] |= b.data[i][j];
}
bool directSub(mat& c, mat& a, mat& b) {
	c.n = a.n - 2;
	mat subm;
	subm.n = a.n;
	memset(subm.data, false, sizeof(subm.data));
	for(int i = 1; i < a.n - 1; ++i) {
		for(int j = 1; j < a.n - 1; ++j)
			if(canBeSub(a, i, j, b)) {
				c.data[i - 1][j - 1] = true;
				add(subm, i, j, b);
			}
			else {
				c.data[i - 1][j - 1] = false;
			}
	}
	for(int i = 0; i < a.n; ++i)
		for(int j = 0; j < a.n; ++j)
			if(subm.data[i][j] != a.data[i][j])
				return false;
	return true;
}
vector<int> convert(mat& m) {
	vector<int> ret;
	for(int i = 0; i < m.n; ++i) {
		int elem = 0;
		for(int j = 0; j < m.n; ++j) {
			elem <<= 1;
			if(m.data[i][j])
				elem |= 1;
		}
		ret.push_back(elem);
	}
	return ret;
}
bool isOK(mat m) {
	vector<mat> vm, vmnew;
	set<vector<int> > sv;
	vm.push_back(m);
	mat newm;
	for(int i = 0; i < 32; ++i) {
		pat[i].data[0][0] = m.data[0][0];
		pat[i].data[0][2] = m.data[0][m.n - 1];
		pat[i].data[2][0] = m.data[m.n - 1][0];
		pat[i].data[2][2] = m.data[m.n - 1][m.n - 1];
	}
	for(int i = m.n; i > 3; i -= 2) {
		while(!vm.empty()) {
			m.copy(vm.back());
			vm.pop_back();
			for(int j = 0; j < 32; ++j) {
				if(!directSub(newm, m, pat[j]))
					continue;
				vector<int> vv = convert(newm);
				if(sv.find(vv) == sv.end()) {
					sv.insert(vv);
					vmnew.push_back(newm);
				}
			}
		}
		vm = vmnew;
		vmnew.clear();
		sv.clear();
	}
	if(vm.empty())
		return false;
	else
		return true;
}
int main() {
	init();
	int n;
	int cs = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		char txt[MAXN];
		mat m;
		m.n = n;
		for(int i = 0; i < n; ++i) {
			scanf("%s", txt);
			for(int j = 0; j < n; ++j)
				if(txt[j] == '0')
					m.data[i][j] = false;
				else
					m.data[i][j] = true;
		}
		printf("Instance %d:\n", cs);
		cs++;
		if(n < 3 || n % 2 != 1) {
			printf("No\n");
			continue;
		}
		if(n == 3 || isOK(m))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
