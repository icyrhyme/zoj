#include <cstdio>
#include <cstring>
#define MAXL 128
#define MAXN 25
using namespace std;
class Generator {
	char msg[MAXL];
	int len;
	int cnt;
	int num;
public:
	Generator(char msg[]) {
		strcpy(this->msg, msg);
		len = strlen(msg);
		cnt = 0;
	}
	int _conv(char ch) {
		if(ch == ' ')
			return 0;
		else
			return ch - 'A' + 1;
	}
	char getBit() {
		if(cnt >= len * 5)
			return '0';
		if(cnt % 5 == 0)
			num = _conv(msg[cnt / 5]);
		char ret;
		if(num & (1 << 4))
			ret = '1';
		else
			ret = '0';
		++cnt;
		num <<= 1;
		return ret;
	}
};
int n, m;
char mat[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool isok(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == '\0')
		return true;
	else
		return false;
}
int main() {
	int cs, csnum = 1;
	scanf("%d", &cs);
	while(cs--) {
		char msg[MAXL];
		scanf("%d%d", &n, &m);
		getchar();
		gets(msg);
		memset(mat, 0, sizeof(mat));
		Generator g(msg);
		int x = 0, y = 0, nx, ny, k = 0;
		for(int i = 0; i < n * m; ++i) {
			mat[x][y] = g.getBit();
			//putchar(mat[x][y]);
			nx = x + dx[k];
			ny = y + dy[k];
			if(!isok(nx, ny)) {
				++k;
				if(k == 4)
					k = 0;
			}
			x = x + dx[k];
			y = y + dy[k];
		}
		//putchar('\n');
		printf("%d ", csnum);
		csnum++;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				putchar(mat[i][j]);
		putchar('\n');
	}
	return 0;
}
