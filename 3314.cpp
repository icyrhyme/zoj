#include <iostream>
#define MAXN 305
#define INF 1000000000
using namespace std;
char mmm[26][7][20] = {
"111111MMM1111111",
"11111MM1MM111111",
"1111MM111MM11111",
"111MMMMMMMMM1111",
"11MM1111111MM111",
"1MMM11111111MM11",
"1MM1111111111MM1",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",
"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111111MM1",
"111MM1111111MM11",
"11111MMMMMMMM111",
"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",
"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MM1111111111111",
"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111MMMMM1",
"111MM1111111MM11",
"11111MMMMMMMMM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MMMMMMMMMMMMM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",
"11111MMMMMM11111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11111MMMMMM11111",
"1111MMMMMMMM1111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"111MM11MM1111111",
"111MMM1MM1111111",
"11111MMMM1111111",
"11MM111111MMM111",
"11MM11111MMM1111",
"11MM111MMM111111",
"11MMMMM111111111",
"11MM111MMM111111",
"11MM11111MMM1111",
"11MM111111MMMM11",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MMMMMMMMMMMM11",
"1MM1111111111MM1",
"1MMMM111111MMMM1",
"1MM1MM1111MM1MM1",
"1MM11MMMMM111MM1",
"1MM1111M11111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MMM111111111MM1",
"1MMMM11111111MM1",
"1MM1MM1111111MM1",
"1MM11MM111111MM1",
"1MM1111MM1111MM1",
"1MM111111MMM1MM1",
"1MM11111111MMMM1",
"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",
"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MM1111111111111",
"1MM1111111111111",
"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM1MMMM1MMM11",
"111MMM11MMMMM111",
"111111MMMM1MMMM1",
"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM111111111MMM1",
"1111MMMMMMMM1111",
"111MM1111111MM11",
"11MMM1111111MMM1",
"1111MMMMM1111111",
"1MMM111MMMM11111",
"111MMM11111MMM11",
"11111MMMMMMM1111",
"11MMMMMMMMMMMM11",
"11MMMMMMMMMMMM11",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MMM11111111MMM1",
"1MMM11111111MMM1",
"111MMMMMMMMMM111",
"1MMMM111111MMMM1",
"11MMM111111MMM11",
"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"11111MM11MM11111",
"111111MMMM111111",
"1MM1111111111MM1",
"1MM1111111111MM1",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM1MM11MM1MM11",
"111MMM1111MMM111",
"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"111MMMMMMMMMM111",
"1111111111MM1111",
"111111111MM11111",
"11111111MM111111",
"111111MM11111111",
"11111MM111111111",
"111MMMMMMMMMMM11",
};
char input[MAXN][MAXN];
int n, m, miny, maxy, minx, maxx;
char comp[7][20];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
void dfsOne(int x, int y) {
	input[x][y]++;
	minx = min(minx, x);
	maxx = max(maxx, x);
	miny = min(miny, y);
	maxy = max(maxy, y);
	for(int i = 0; i < 8; ++i) {
		int newx = x + dx[i], newy = y + dy[i];
		if(newx >= 0 && newx < n && newy >= 0 && newy < m && input[newx][newy] == 'M')
			dfsOne(newx, newy);
	}
}
void dfsTwo(int x, int y, int basex, int basey) {
	input[x][y] = '1';
	comp[x - basex][y - basey] = 'M';
	for(int i = 0; i < 8; ++i) {
		int newx = x + dx[i], newy = y + dy[i];
		if(newx >= 0 && newx < n && newy >= 0 && newy < m && input[newx][newy] == 'M' + 1)
			dfsTwo(newx, newy, basex, basey);
	}
}
bool isMatch(char txt[][20], char pat[][20]) {
	bool flag[2] = {true, true};
	for(int i = 0; i < 7; ++i)
		for(int j = 0; txt[i][j] != '\0'; ++j)
			if(txt[i][j] != pat[i][j]) {
				flag[0] = false;
				break;
			}
	for(int i = 0; i < 7; ++i)
		for(int j = 0; txt[i][j] != '\0'; ++j)
			if(txt[i][j] != pat[6 - i][maxy - miny - j]) {
				flag[1] = false;
				break;
			}
	return (flag[0] || flag[1]);
}
int main() {
	for(int i = 0; i < 26; ++i) {
		miny = INF, maxy = -1;
		for(int j = 0; j < 7; ++j)
			for(int k = 0; k < 16; ++k) {
				if(mmm[i][j][k] == 'M') {
					miny = min(miny, k);
					maxy = max(maxy, k);
				}
			}
		for(int j = 0; j < 7; ++j) {
			int kk = 0;
			for(int k = miny; k <= maxy; ++k, ++kk) {
				mmm[i][j][kk] = mmm[i][j][k];
			}
			mmm[i][j][kk] = '\0';
			//printf("%s\n", mmm[i][j]);
		}
	}
	bool isFound[26];
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i)
			scanf("%s", input[i]);
		memset(isFound, false, sizeof(isFound));
		for(int j = 0; j < m; ++j) {
			for(int i = 0; i < n; ++i) {
				if(input[i][j] != 'M')
					continue;
				miny = INF, maxy = -1, minx = INF, maxx = -1;
				dfsOne(i, j);
				memset(comp, '1', sizeof(comp));
				dfsTwo(i, j, minx, miny);
				for(int k = 0; k < 7; ++k) {
					comp[k][maxy - miny + 1] = '\0';
					//printf("%s\n", comp[k]);
				}
				for(int k = 0; k < 26; ++k)
					if(isMatch(comp, mmm[k]))
						isFound[k] = true;
			}
		}
		for(int i = 0; i < 26; ++i)
			if(isFound[i])
				putchar('A' + i);
		putchar('\n');
	}
	return 0;
}
/*int main() {
	char mm[26][7][20];
	freopen("temp.txt", "r", stdin);
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < 7; ++j) {
			for(int k = 0; k < (i == 4 ? 2 : 6); ++k) {
				char temp[20];
				scanf("%s", temp);
				strcpy(mm[i * 6 + k][j], temp);
				printf("%s %d %d\n", temp, i * 6 + k, j);
			}
		}
	}
	for(int i = 0; i < 26; ++i) {
		int miny = 0, maxy = 15;
		for(int j = 0; j < 7; ++j) {
			putchar('\"');
			for(int k = miny; k <= maxy; ++k) {
				putchar(mm[i][j][k]);
			}
			putchar('\"');
			putchar(',');
			putchar('\n');
		}
	}
	return 0;
}*/
