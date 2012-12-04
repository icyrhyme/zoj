#include <iostream>
#define MAXN 64
using namespace std;
int M, N;
int map[MAXN][MAXN];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int conv(char c) {
	static int c2i[] = {3, 6, 9, 12, 10, 5, 7, 11, 13, 14, 15};
	return c2i[c - 'A'];
}
inline int opposite(int d) {
	return ((d == 1 || d == 4) ? 5 - d : 10 - d);
}
inline bool isValid(int i, int j) {
	if(i >= 0 && i < M && j >= 0 && j < N)
		return true;
}
void dfs(int i, int j) {
	int temp = map[i][j];
	map[i][j] = 0;
	for(int p = 0; p < 4; ++p) {
		if((temp & (1 << p)) != (1 << p))
			continue;
		int newi = i + dx[p], newj = j + dy[p];
		if(isValid(newi, newj) && (map[newi][newj] & opposite(1 << p)) != 0)
			dfs(newi, newj);
	}
}
int main() {
	while(scanf("%d%d", &M, &N) != EOF) {
		if(M < 0 && N < 0)
			break;
		char data[MAXN][MAXN];
		for(int i = 0; i < M; ++i) {
			scanf("%s", data[i]);
			for(int j = 0; data[i][j]; ++j) {
				map[i][j] = conv(data[i][j]);
			}
		}
		int ans = 0;
		for(int i = 0; i < M; ++i) {
			for(int j = 0; j < N; ++j) {
				if(map[i][j]) {
					dfs(i, j);
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
