#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 1024
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		char num[MAXN];
		scanf("%s", num);
		int len = strlen(num);
		reverse(num, num + len);
		int i, sum = 0;
		for(i = 0; num[i] == '0'; ++i)
			;
		--num[i];
		sum += num[i] - '0';
		for(++i; num[i] == '9' && num[i] != '\0'; ++i)
			sum += num[i] - '0';
		if(num[i] == '\0') {
			num[i] = '1';
			num[i + 1] = '\0';
			++len;
		}
		else {
			++num[i];
		}
		memset(num, '0', sizeof(char) * i);
		for(i = 0; sum - 9 > 0; sum -= 9, ++i) {
			num[i] = '9';
		}
		num[i] = sum + '0';
		reverse(num, num + len);
		printf("%s\n", num);
	}
	return 0;
}
