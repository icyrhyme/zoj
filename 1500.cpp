#include <cstdio>
#include <cstring>
#define MAXL 30
using namespace std;
char ta[MAXL], tb[MAXL];
int m, c[MAXL][MAXL];
int gao(int ale, int ari, int ble, int bri) {
	if(ale > ari)
		return 1;
	int cnt = 0, s = 0, ret = 1;
	for(int i = 0; i <= (ari - ale); ++i) {
		if(tb[ble + i] == ta[ale + s]) {
			++cnt;
			ret *= gao(ale + s + 1, ale + i, ble + s, ble + i - 1);
			s = i + 1;
		}
	}
	return ret * c[m][cnt];
}
int main() {
	for(int i = 0; i < MAXL; ++i)
		for(int j = 0; j <= i; ++j) {
			if(j == 0 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	while(scanf("%d", &m) != EOF) {
		if(m == 0)
			break;
		scanf("%s%s", ta, tb);
		int len = strlen(ta);
		printf("%d\n", gao(1, len - 1, 0, len - 2));
	}
	return 0;
}
