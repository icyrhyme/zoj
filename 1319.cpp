#include <iostream>
#include <queue>
#define MAXN 30005
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int M, N;
		scanf("%d%d", &M, &N);
		int a[MAXN], u[MAXN];
		for(int i = 0; i < M; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < N; ++i)
			scanf("%d", &u[i]);
		priority_queue<int> maxq;
		priority_queue<int, vector<int>, greater<int> > minq;
		int ui = 0;
		for(int i = 0; i < M; ++i) {
			if(maxq.empty() || a[i] < maxq.top()) {
				maxq.push(a[i]);
				minq.push(maxq.top());
				maxq.pop();
			}
			else
				minq.push(a[i]);
			while(ui < N && i == u[ui] - 1) {
				printf("%d\n", minq.top());
				maxq.push(minq.top());
				minq.pop();
				++ui;
			}
		}
		if(t > 0)
			printf("\n");
	}
	return 0;
}
