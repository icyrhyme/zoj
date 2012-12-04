#include <iostream>
#include <vector>
#define OK 39
using namespace std;
#define MAXN 16
int parseInt(char s[]) {
	int ret = 0;
	for(int i = 0; s[i] != '\0'; ++i)
		ret = ret * 10 + s[i] - '0';
	return ret;
}
int main() {
	char s[MAXN];
	int T;
	scanf("%d", &T);
	while(T--) {
		vector<int> va(3), vb(3);
		for(int i = 0; i < 3; ++i) {
			scanf("%s", s);
			va[i] = parseInt(s);
		}
		for(int i = 0; i < 3; ++i) {
			scanf("%s", s);
			vb[i] = parseInt(s);
		}
		if(va < vb)
			printf("javaman\n");
		else if(va > vb)
			printf("cpcs\n");
		else
			printf("same\n");
	}
	return 0;
}
