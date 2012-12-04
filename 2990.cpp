#include <cstdio>
#include <cstring>
#define MAXN 25
#define MAXL 512
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
char mat[MAXN][MAXN];
bool isok(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '\0')
		return true;
	else
		return false;
}
char conv(int val) {
	if(val == 0)
		return ' ';
	else
		return 'A' + (val - 1);
}
void decode(char msg[]) {
	char ans[MAXL];
	int len = strlen(msg);
	int val, i, k;
	for(i = 0, k = 0; i + 4 < len; i += 5, ++k) {
		val = 0;
		for(int j = 0; j < 5; ++j) {
			val = (val << 1) + (msg[i + j] - '0');
		}
		//printf("%d\n", val);
		ans[k] = conv(val);
	}
	ans[k] = '\0';
	--k;
	while(k >= 0 && ans[k] == ' ') {
		ans[k] = '\0';
		--k;
	}
	strcpy(msg, ans);
}
int main() {
	int cs, csnum = 1;
	scanf("%d", &cs);
	while(cs--) {
		scanf("%d%d", &n, &m);
		getchar();
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				mat[i][j] = getchar();
		int x = 0, y = 0, nx, ny, di = 0;
		char msg[MAXL];
		for(int i = 0; i < n * m; ++i) {
			msg[i] = mat[x][y];
			mat[x][y] = '\0';
			nx = x + dx[di];
			ny = y + dy[di];
			if(!isok(nx, ny)) {
				++di;
				if(di == 4)
					di = 0;
			}
			x = x + dx[di];
			y = y + dy[di];
		}
		msg[n * m] = '\0';
		decode(msg);
		printf("%d %s\n", csnum, msg);
		++csnum;
	}
	return 0;
}
