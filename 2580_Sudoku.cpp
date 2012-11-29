#include <cstdio>
#include <cstring>
#include <map>
#define MAXN 9
#define UNSET(a,i) ((a)&(~(1<<(i))))
using namespace std;
class Board {
	short data[MAXN][MAXN];
	bool done[MAXN][MAXN];
public:
	void _init() {
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j) {
				data[i][j] = (1 << MAXN) - 1;
				done[i][j] = false;
			}
	}
	Board() {
		_init();
	}
	Board(const Board& that) {
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j) {
				data[i][j] = that.data[i][j];
				done[i][j] = that.done[i][j];
			}
	}
	Board(char str[][MAXN + 1]) {
		_init();
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j)
				if(str[i][j] != '0')
					set(i, j, str[i][j] - '0');
	}
	void set(int i, int j, int n) {
		--n;
		data[i][j] = 1 << n;
		done[i][j] = true;
		for(int k = 0; k < MAXN; ++k) 
			if(k != j)
				data[i][k] = UNSET(data[i][k], n);
		for(int k = 0; k < MAXN; ++k)
			if(k != i)
				data[k][j] = UNSET(data[k][j], n);
		int br = i / 3 * 3, bc = j / 3 * 3;
		for(int k = 0; k < 3; ++k)
			for(int l = 0; l < 3; ++l)
				if(br + k != i || bc + l != j)
					data[br + k][bc + l] = UNSET(data[br + k][bc + l], n);
	}
	pair<int, int> getMostCertainPosition() {
		pair<int, int> ret(-1, -1);
		int m = 10;
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j) {
				int cur = __builtin_popcount(data[i][j]);
				if(!done[i][j] && cur < m) {
					m = cur;
					ret = make_pair(i, j);
				}
			}
		return ret;
	}
	bool isDone() {
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j)
				if(!done[i][j])
					return false;
		return true;
	}
	int getOptions(int i, int j) {
		return data[i][j];
	}
	void print() {
		for(int i = 0; i < MAXN; ++i) {
			for(int j = 0; j < MAXN; ++j) {
				int cnt = 0;
				for(int k = 0; k < MAXN; ++k) {
					if(data[i][j] & (1 << k)) {
						putchar('1' + k);
						++cnt;
					}
				}
				for(int k = 0; k < 9 - cnt; ++k)
					putchar(' ');
				if(j % 3 == 2 && j != MAXN - 1)
					putchar('|');
			}
			putchar('\n');
			if(i % 3 == 2 && i != MAXN - 1) {
				for(int k = 0; k < MAXN * 9 + 2; ++k)
					putchar('-');
				putchar('\n');
			}
		}
		putchar('\n');
	}
	void output() {
		for(int i = 0; i < MAXN; ++i) {
			for(int j = 0; j < MAXN; ++j) {
				for(int k = 0; k < MAXN; ++k) {
					if(data[i][j] & (1 << k)) {
						putchar('1' + k);
						break;
					}
				}
			}
			putchar('\n');
		}
	}
};
Board* solve(Board b) {
	//b.print();
	if(b.isDone())
		return (new Board(b));
	pair<int, int> p = b.getMostCertainPosition();
	if(p.first == -1)
		return NULL;
	int ops = b.getOptions(p.first, p.second);
	for(int k = 1; k <= MAXN; ++k) {
		if(ops & (1 << (k - 1))) {
			Board nb(b);
			nb.set(p.first, p.second, k);
			Board* ret = solve(nb);
			if(ret != NULL)
				return ret;
		}
	}
	return NULL;
}
int main() {
	int cs;
	char str[MAXN][MAXN + 1];
	scanf("%d", &cs);
	while(cs--) {
		for(int i = 0; i < MAXN; ++i)
			scanf("%s", str[i]);
		Board b(str);
		Board* sol = solve(b);
		if(sol != NULL)
			sol->output();
	}
	return 0;
}
