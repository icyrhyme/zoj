#include <iostream>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int x;
		scanf("%d", &x);
		printf("%.2lf\n", (double)x * 480);
	}
	return 0;
}
