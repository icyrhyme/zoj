#include <iostream>
#include <cstdio>
#define MAXN 22
using namespace std;
bool isok(bool face[3][MAXN][MAXN], bool newface[3][MAXN][MAXN], int n) {
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				if(face[i][j][k] != newface[i][j][k])
					return false;
	return true;
}
int main() {
	int n;
	bool face[3][MAXN][MAXN], newface[3][MAXN][MAXN];
	char tmp[MAXN];
	int t = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < n; ++j) {
				scanf("%s", tmp);
				for(int k = 0; tmp[k]; ++k) {
					if(tmp[k] == 'X')
						face[i][j][k] = true;
					else
						face[i][j][k] = false;
					newface[i][j][k] = false;
				}
			}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k) {
					bool val = (face[0][i][j] && face[1][j][k] && face[2][i][k]);
					newface[0][i][j] |= val;
					newface[1][j][k] |= val;
					newface[2][i][k] |= val;
				}
		if(isok(face, newface, n))
			printf("Data set %d: Valid set of patterns\n", t);
		else
			printf("Data set %d: Impossible combination\n", t);
		++t;
	}
	return 0;
}
