#include <iostream>
#define MAXLEN 32
using namespace std;
int main() {
	char str[MAXLEN];
	int r, c;
	while(scanf("%s", str) != EOF) {
		if(strcmp(str, "ENDOFINPUT") == 0)
			break;
		scanf("%d%d", &r, &c);
		char img[MAXLEN][MAXLEN], newImg[MAXLEN][MAXLEN];
		for(int i = 0; i < r; ++i)
			scanf("%s", img[i]);
		for(int i = 0; i < r - 1; ++i) {
			for(int j = 0; j < c - 1; ++j) {
				newImg[i][j] = (img[i][j] + img[i + 1][j] + img[i][j + 1] + img[i + 1][j + 1]) / 4;
			}
			newImg[i][c - 1] = '\0';
		}
		scanf("%s", str);
		for(int i = 0; i < r - 1; ++i)
			printf("%s\n", newImg[i]);
	}
	return 0;
}
