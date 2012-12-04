#include <cstdio>
#include <cstring>
#define MAXL 32
#define MAXN 128
using namespace std;
int main() {
	int cas;
	char name[MAXL];
	char names[MAXN][MAXL];
	scanf("%d", &cas);
	while(cas--) {
		int n, idx;
		scanf("%d%s", &n, name);
		for(int i = 0; i < n; ++i) {
			scanf("%s", names[i]);
			if(strcmp(name, names[i]) == 0) {
				idx = i;
			}
		}
		printf("%s\n", names[(idx + n / 2) % n]);
	}
	return 0;
}
