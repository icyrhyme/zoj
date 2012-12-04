#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 64
using namespace std;
union fiu {
	float f;
	unsigned int i;
};
int main() {
	union fiu fi;
	char txt[MAXL];
	printf("Program 6 by team X\n");
	while(scanf("%s", txt) != EOF) {
		if(strcmp(txt, "0000000000000000") == 0 || strcmp(txt, "1000000000000000") == 0) {
			printf(" 0.000000e+000\n");
			continue;
		}
		unsigned int sign, exp, mant, num = 0U;
		//for(int i = 8, j = 15; i < j; ++i, --j)
		//	swap(txt[i], txt[j]);
		for(int i = 0; i < 16; ++i)
			num = num * 2 + txt[i] - '0';
		sign = (num & 0x8000) >> 15;
		exp = (num & 0x7F00) >> 8;
		exp = exp - 63 + 127;
		mant = num & 0x00FF;
		//printf("%d %d %d\n", sign, exp, mant);
		fi.i = 0;
		fi.i = fi.i | (sign << 31);
		fi.i = fi.i | (exp << 23);
		fi.i = fi.i | (mant << 15);
		printf("% .6e\n", (double)fi.f);

	}
	printf("End of program 6 by team X\n");
	return 0;
}

