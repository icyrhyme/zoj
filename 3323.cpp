#include <iostream>
#define MAXN 128
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		char s[MAXN];
		scanf("%s", s);
		int i, j;
		for(i = 0, j = 0; s[j] != '\0' && s[i] != '\0';) {
			if(isdigit(s[j])) {
				++j;
			}
			else {
				s[i] = s[j];
				++i;
				++j;
			}
		}
		s[i] = '\0';
		printf("%s\n", s);
	}
	return 0;
}
