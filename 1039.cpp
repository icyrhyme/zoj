#include <cstdio>
#include <cstring>
#include <vector>
#define BASE 2
#define LIM 20
#define UNSET(s,i) ((s)&(~(1<<((i)-BASE))))
#define TEST(s,i) ((s)&(1<<((i)-BASE)))
using namespace std;
int mem[1 << (LIM - 1)]; //1 for win, 0 for lose
vector<int> move[1 << (LIM - 1)];
bool gao(int s) {
	if(mem[s] != -1)
		return (bool)mem[s];
	//printf("%x\n", s);
	mem[s] = 0;
	for(int i = BASE; i <= LIM; ++i) {
		if(TEST(s, i)) {
			int t = UNSET(s, i);
			for(int j = BASE; j <= LIM; ++j) {
				if(!TEST(t, j) && j + i <= LIM) {
					t = UNSET(t, j + i);
				}
			}
			if(!gao(t)) {
				mem[s] = 1;
				move[s].push_back(i);
			}
		}
	}
	return mem[s];
}
int main() {
	memset(mem, -1, sizeof(mem));
	gao((1 << (LIM - 1)) - 1);
	int cs;
	scanf("%d", &cs);
	for(int o = 1; o <= cs; ++o) {
		int n;
		scanf("%d", &n);
		int num = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			num = num | (1 << (x - BASE));
		}
		printf("Scenario #%d:\n", o);
		if(mem[num]) {
			printf("The winning moves are:");
			for(int i = 0; i < move[num].size(); ++i) {
				printf(" %d", move[num][i]);
			}
			printf(".\n");
		}
		else {
			printf("There is no winning move.\n");
		}
		putchar('\n');
	}
	return 0;
}

