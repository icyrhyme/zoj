#include <iostream>
#define MAXN 128
#define MAXN 128
#define D_L 0
#define D_R 1
#define D_U 2
#define D_D 3
using namespace std;
struct move {
	int le, ri;
	char d[4];
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool isIn(int x, int y, int n, int m) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, m;
		int mp[MAXN][MAXM];
		int stp[MAXN][MAXM][4];
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				scanf("%d", &mp[i][j]);
				mp[i][j] = -mp[i][j];
			}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				if(mp[i][j] == 1)
					continue;
				for(int k = 0; k < 4; ++k) {
					int cnt = 0;
					int ni = i + dx[k], nj = j + dy[k];
					while(isIn(ni, nj, n, m) && mp[ni][nj] == 0) {
						++cnt;
						ni += dx[k];
						nj += dy[k];
					}
					stp[i][j][k] = cnt;
				}
			}
		move tmp;
		vector<move> vm;
		while(scanf("%d%d", &tmp.le, &tmp.ri)) {
			if(tmp.le == 0 && tmp.ri == 0)
				break;
			scanf("%s", tmp.d);
			vm.push_back(tmp);
		}
		int nmp[MAXN][MAXM], tmp[MAXN][MAXM];
		for(int i = 0; i < n; ++i)
			copy(mp[i], mp[i] + m, nmp[i]);
		for(int i = 0; i < vm.size(); ++i) {
			move tmpm = vm[vm.size() - 1 - i];
			int d, le = tmpm.le, ri = tmpm.ri;
			switch(tmpm.d[0]) {
				case 'L': d = D_L; break;
				case 'R': d = D_R; break;
				case 'U': d = D_U; break;
				case 'D': d = D_D; break;
			}
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < m; ++k) {
					if(mp[j][k] != 0)
						continue;
				}
		}
	}
	return 0;
}
