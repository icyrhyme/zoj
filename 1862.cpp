#include <iostream>
#include <cstdio>
#define MAXN 12
using namespace std;
int di[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int main() {
	int n, csnum = 1;
	char mine[MAXN][MAXN];
	char mp[MAXN][MAXN];
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i)
			scanf("%s", mine[i]);
		for(int i = 0; i < n; ++i)
			scanf("%s", mp[i]);
		bool flag = false;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(mp[i][j] != 'x')
					continue;
				if(mine[i][j] == '*')
					flag = true;
				int cnt = 0;
				for(int k = 0; k < 8; ++k) {
					int ni = i + di[k];
					int nj = j + dj[k];
					if(ni >= 0 && ni < n && nj >= 0 && nj < n && mine[ni][nj] == '*')
						++cnt;
				}
				mp[i][j] = '0' + cnt;
			}
		}
		if(flag) {
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j) {
					if(mine[i][j] == '*')
						mp[i][j] = '*';
				}
		}
		if(csnum != 1)
			printf("\n");
		csnum++;
		for(int i = 0; i < n; ++i)
			printf("%s\n", mp[i]);
	}
	return 0;
}
