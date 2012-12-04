#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int MAXN = 362;
int aug(int n, const vector<int> list[], int *match, int *v, int now) {
	int t, ret = 0, r;
	v[now] = 1;
	for(r = 0; r < list[now].size(); ++r) {
		if(!v[t = list[now][r]]) {
			if(match[t] < 0) {
				match[now] = t;
				match[t] = now;
				ret = 1;
			}
			else {
				v[t] = 1;
				if(aug(n, list, match, v, match[t])) {
					match[now] = t;
					match[t] = now;
					ret = 1;
				}
			}
			if(ret) {
				break;
			}
		}
	}
	v[now] = 0;
	return ret;
}
int graphMatch(int n, const bool mat[][MAXN], int *match) {
	int v[MAXN], i, j;
	vector<int> list[MAXN];
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(mat[i][j]) {
				list[i].push_back(j);
			}
		}
	}
	for(i = 0; i < n; i++) {
		v[i] = 0, match[i] = -1;
	}
	for(i = 0, j = n; i < n && j >= 2;) {
		if(match[i] < 0 && aug(n, list, match, v, i)) {
			memset(v, 0, sizeof(v)), i = 0, j -= 2;
		}
		else {
			i++;
		}
	}
	for(i = j = 0; i < n; i++) {
		j += (match[i] >= 0);
	}
	return j / 2;
}
#define ABS(x) ((x)>0?(x):-(x))
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		vector<pair<int, int> > vp;
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			vp.push_back(make_pair(u, v));
		}
		int L;
		scanf("%d", &L);
		if(n % 2 != 0) {
			printf("NO\n");
			continue;
		}
		bool mat[MAXN][MAXN];
		memset(mat, false, sizeof(mat));
		for(int i = 0; i < vp.size(); ++i)
			for(int j = i + 1; j < vp.size(); ++j) {
				int dis = ABS(vp[i].first - vp[j].first);
				dis += ABS(vp[i].second - vp[j].second);
				if(dis <= L) {
					mat[i][j] = mat[j][i] = true;
				}
			}
		int match[MAXN];
		int ans = graphMatch(n, mat, match);
		if(ans * 2 < n)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
