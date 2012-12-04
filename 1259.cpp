#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#define MAXN 1024
using namespace std;
bool isok(int a[], int n) {
	stack<int> s;
	int i, j;
	for(i = 1, j = 0; i <= n; ++i) {
		s.push(i);
		while(!s.empty() && s.top() == a[j]) {
			s.pop();
			++j;
		}
	}
	for(; j < n; ++j) {
		if(s.top() != a[j])
			return false;
		else
			s.pop();
	}
	return true;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		int a[MAXN];
		while(1) {
			scanf("%d", &a[0]);
			if(a[0] == 0) {
				putchar('\n');
				break;
			}
			for(int i = 1; i < n; ++i) {
				scanf("%d", &a[i]);
			}
			if(isok(a, n))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
