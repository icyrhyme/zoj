#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#define MAXN 9
using namespace std;
struct delete_move {
	int i, j;
	char c;
	delete_move() {}
	delete_move(int i, int j, int c) {
		this->i = i;
		this->j = j;
		this->c = c;
	}
};
bool gao(set<char> board[][MAXN], bool done[][MAXN]) {
	pair<int, int> opt;
	int min_choices = 10, max_choices = 1;
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) {
			if(!done[i][j] && board[i][j].size() < min_choices) {
				opt = make_pair(i, j);
				min_choices = board[i][j].size();
			}
			max_choices = max(max_choices, (int)board[i][j].size());

		}
	if(max_choices == 1) {
		for(int i = 0; i < MAXN; ++i) {
			for(int j = 0; j < MAXN; ++j)
				putchar(*board[i][j].begin());
			putchar('\n');
		}
		return true;
	}
	int i = opt.first, j = opt.second;
	vector<char> choices(board[i][j].begin(), board[i][j].end());
	for(vector<char>::iterator it = choices.begin(); it != choices.end(); ++it) {
		vector<delete_move> records;
		for(int k = '0'; k <= '9'; ++k) {
			if(board[i][j].find(k) != board[i][j].end() && k != *it) {
				board[i][j].erase(k);
				delete_move temp(i, j, k);
				records.push_back(temp);
			}
		}
		for(int k = 0; k < MAXN; ++k) {
			if(board[i][k].find(*it) != board[i][k].end() && k != j) {
				board[i][k].erase(*it);
				delete_move temp(i, k, *it);
				records.push_back(temp);
			}
			if(board[k][j].find(*it) != board[k][j].end() && k != i) {
				board[k][j].erase(*it);
				delete_move temp(k, j, *it);
				records.push_back(temp);
			}
		}
		int br = i / 3, bc = j / 3;
		for(int k = 0; k < 3; ++k)
			for(int l = 0; l < 3; ++l) 
				if(board[br + k][br + l].find(*it) != board[br + k][br + l].end() && (br + k != i || bc + l != j)) {
					board[br + k][br + l].erase(*it);
					delete_move temp(br + k, br + l, *it);
					records.push_back(temp);
				}
		done[i][j] = true;
		if(gao(board, done))
			return true;
		done[i][j] = false;
		for(vector<delete_move>::iterator rit = records.begin(); rit != records.end(); ++rit) {
			board[rit->i][rit->j].insert(rit->c);
		}
	}
}
int main() {
	int cs;
	char sudoku[MAXN][MAXN + 1];
	set<char> board[MAXN][MAXN];
	bool done[MAXN][MAXN];
	scanf("%d", &cs);
	while(cs--) {
		for(int i = 0; i < MAXN; ++i)
			scanf("%s", sudoku[i]);
		for(int i = 0; i < MAXN; ++i)
			for(int j = 0; j < MAXN; ++j) {
				if(sudoku[i][j] == '0')
					for(char k = '0'; k <= '9'; ++k)
						board[i][j].insert(k);
				else
					board[i][j].insert(sudoku[i][j]);
			}
		memset(done, false, sizeof(done));
		gao(board, done);
	}
	return 0;
}
