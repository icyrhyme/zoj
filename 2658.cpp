#include <iostream>
#include <vector>
#define MAXN 128
using namespace std;
int main() {
	char pt[MAXN], ct[MAXN];
	while(scanf("%s%s", pt, ct) != EOF) {
		vector<int> a(26, 0), b(26, 0);
		for(int i = 0; pt[i] != '\0'; ++i)
			a[pt[i] - 'A']++;
		for(int i = 0; ct[i] != '\0'; ++i)
			b[ct[i] - 'A']++;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if(a == b)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
