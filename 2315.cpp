#include <iostream>
#include <vector>
#define MAXN 500005
using namespace std;
int t[MAXN], color[MAXN];
int main() {
	int C;
	scanf("%d", &C);
	while(C--) {
		int N;
		scanf("%d", &N);
		t[0] = -1;
		for(int i = 1; i < N; ++i) {
			scanf("%d", &t[i]);
		}
		int cnt = 0;
		memset(color, 0, sizeof(int) * N);
		vector<int> res;
		for(int i = N - 1; i > 0; --i) {
			if(color[i] == 0 && color[t[i] - 1] == 0) {
				res.push_back(i);
				color[i] = color[t[i] - 1] = 1;
			}
		}
		printf("%d\n", res.size());
		for(int i = res.size() - 1; i >= 0; --i) {
			printf("%d%c", res[i] + 1, (i == 0 ? '\n' : ' '));
		}
	}
	return 0;
}
