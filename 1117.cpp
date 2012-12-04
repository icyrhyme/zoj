#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#define MAXN 100005
using namespace std;
int main() {
	int cnt[32];
	char buf[MAXN];
	while(1) {
		scanf("%s", buf);
		if(strcmp(buf, "END") == 0)
			break;
		fill(cnt, cnt + 32, 0);
		int len = strlen(buf);
		for(int i = 0; i < len; ++i) {
			if(buf[i] >= 'A' && buf[i] <= 'Z')
				++cnt[buf[i] - 'A'];
			else if(buf[i] == '_')
				++cnt['Z' - 'A' + 1];
		}
		priority_queue<int, vector<int>, greater<int> > q;
		for(int i = 0; i <= 'Z' - 'A' + 1; ++i) {
			if(cnt[i] != 0)
				q.push(cnt[i]);
		}
		int clen = 0;
		if(q.size() == 1)
			clen += q.top();
		while(q.size() > 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			clen += a + b;
			q.push(a + b);
		}
		printf("%d %d %.1lf\n", len * 8, clen, (len * 8.0) / clen);
	}
	return 0;
}
