#include <iostream>
#include <vector>
#define MAXN 32
using namespace std;
int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		if(N == 0)
			break;
		char snum[MAXN];
		int sum = 0, num;
		for(int i = 0; i < N; ++i) {
			scanf("%s", snum);
			num = 0;
			for(int i = 0; snum[i] != '\0'; ++i)
				if(isdigit(snum[i]))
					num = num * 10 + snum[i] - '0';
			sum += num;
		}
		//printf("%d\n", sum);
		int fp = sum % 100;
		sum /= 100;
		vector<int> a;
		while(sum >= 1000)
		{
			a.push_back(sum % 1000);
			sum /= 1000;
		}
		a.push_back(sum);
		printf("$");
		for(int i = a.size() - 1; i >= 0; --i) {
			if(i == a.size() - 1)
				printf("%d", a[i]);
			else
				printf("%03d", a[i]);
			printf("%c", (i == 0 ? '.' : ','));
		}
		printf("%02d\n", fp);
	}
	return 0;
}
