#include <iostream>
#include <queue>
#include <cstdio>
#define MAXW 80
#define MAXH 80
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct state {
	int x, y, d;
};
struct state makeState(int x, int y, int d) {
	struct state st;
	st.x = x;
	st.y = y;
	st.d = d;
	return st;
}
inline bool isIn(int x, int y, int w, int h) {
	return (x >= 0 && x < w && y >= 0 && y < h);
}
int gao(char board[][MAXH], int w, int h, int x1, int y1, int x2, int y2) {
	int vis[MAXW][MAXH][4];
	for(int i = 0; i < w; ++i)
		for(int j = 0; j < h; ++j)
			for(int k = 0; k < 4; ++k)
				vis[i][j][k] = -1;
	queue<state> p, q;
	for(int i = 0; i < 4; ++i) {
		q.push(makeState(x1, y1, i));
		vis[x1][y1][i] = 1;
	};
	while(1) {
		if(q.empty())
			break;
		while(!q.empty()) {
			struct state s = q.front();
			q.pop();
			p.push(s);
			int nx = s.x + dx[s.d], ny = s.y + dy[s.d];
			while(isIn(nx, ny, w, h) && board[nx][ny] == ' ') {
				if(vis[nx][ny][s.d] == -1) {
					vis[nx][ny][s.d] = vis[s.x][s.y][s.d];
					if(nx == x2 && ny == y2)
						return vis[nx][ny][s.d];
					p.push(makeState(nx, ny, s.d));
				}
				nx += dx[s.d];
				ny += dy[s.d];
			}
		}
		if(p.empty())
			break;
		while(!p.empty()) {
			struct state s = p.front();
			p.pop();
			for(int i = 0; i < 4; ++i) {
				int nx, ny;
				nx = s.x + dx[i];
				ny = s.y + dy[i];
				if(board[nx][ny] == ' ' && vis[nx][ny][i] == -1) {
					vis[nx][ny][i] = vis[s.x][s.y][s.d] + 1;
					if(nx == x2 && ny == y2)
						return vis[nx][ny][i];
					q.push(makeState(nx, ny, i));
				}
			}
		}
	}
	return -1;
}
int main() {
	int w, h;
	int csnum = 1;
	while(scanf("%d%d", &h, &w) != EOF) {
		if(w == 0 && h == 0)
			break;
		char board[MAXW][MAXH], temp[MAXH];
		for(int i = 0; i < w + 2; ++i)
			fill(board[i], board[i] + h + 2, ' ');
		gets(temp);
		for(int i = 0; i < w; ++i) {
			gets(temp);
			for(int j = 0; j < h; ++j)
				board[i + 1][j + 1] = temp[j];
		}
		int x1, y1, x2, y2, pnum = 1;
		printf("Board #%d:\n", csnum);
		while(scanf("%d%d%d%d", &y1, &x1, &y2, &x2) != EOF) {
			if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
				break;
			board[x2][y2] = ' ';
			int ans = gao(board, w + 2, h + 2, x1, y1, x2, y2);
			board[x2][y2] = 'X';
			if(ans == -1)
				printf("Pair %d: impossible.\n", pnum);
			else
				printf("Pair %d: %d segments.\n", pnum, ans);
			++pnum;
		}
		putchar('\n');
		++csnum;
	}
}
