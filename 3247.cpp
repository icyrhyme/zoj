#include <iostream>
#define MAXN 128
using namespace std;
int Hex2Dec(char str[]) {
	int ret = 0;
	for(int i = 0; str[i]; ++i) {
		ret <<= 4;
		if(str[i] >= '0' && str[i] <= '9')
			ret += str[i] - '0';
		else
			ret += str[i] - 'A' + 10;
	}
	return ret;
}
int main() {
	int T, C, data[MAXN][5];
	scanf("%d", &T);
	for(int oo = 1; oo <= T; ++oo) {
		scanf("%d", &C);
		for(int i = 0; i < C; ++i)
			for(int j = 0; j < 5; ++j) {
				char temp[4];
				scanf("%s", temp);
				data[i][j] = Hex2Dec(temp);
			}
		printf("Case %d:\n\n", oo);
		for(int p = 1; p <= 0x40; p <<= 1) {
			for(int i = 0; i < C; ++i) {
				for(int j = 0; j < 5; ++j)
					if((data[i][j] & p) == p)
						putchar('#');
					else
						putchar(' ');
				putchar(i == C - 1 ? '\n' : ' ');
			}
		}
		putchar('\n');
	}
	return 0;
}
