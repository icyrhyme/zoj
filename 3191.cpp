#include <iostream>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == -1)
			break;
		n = 90 - n;
		if(n < 0)
			n += 360;
		for(int i = 0; i < 12; ++i) {
			if(n == i * 30) {
				printf("Exactly %d o'clock\n", i);
				break;
			}
			else if(n > i * 30 && n < (i + 1) * 30) {
				printf("Between %d o'clock and %d o'clock\n", i, (i + 1 == 12 ? 0: i + 1));
				break;
			}
		}
	}
	return 0;
}
