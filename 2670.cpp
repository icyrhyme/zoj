#include <iostream>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) {
				if(i == n - 1 && j == n - 1)
					printf("100");
				else
					printf("0");
				if(j == n - 1)
					printf("\n");
				else
					printf(" ");
			}
	}
	return 0;
}
