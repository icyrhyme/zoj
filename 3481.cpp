#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 2048
#define MAXL 1024
using namespace std;
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%*s");
		vector<int> ts;
		char ch;
		int x;
		do {
			scanf("%d%c", &x, &ch);
			//printf("%d\n", x);
			ts.push_back(x);
		}
		while(ch != ' ');
		//printf("good!\n");
		sort(ts.begin(), ts.end());
		if(ts.size() > 1) {
			ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
			x = ts[ts.size() - 1];
			while(ts.size() < MAXN) {
				++x;
				ts.push_back(x);
			}
		}
		else {
			x = ts[0];
			while(ts.size() < MAXN) {
				x += ts[0];
				ts.push_back(x);
			}
		}
		char delim[MAXL], line[MAXL];
		scanf("<<%s%*c", delim);
		//printf("%s\n", delim);
		while(gets(line) && strcmp(line, delim) != 0) {
			int pos = 0;
			for(int i = 0; line[i]; ++i) {
				if(line[i] != '\t') {
					putchar(line[i]);
					++pos;
				}
				else {
					int lim = *upper_bound(ts.begin(), ts.end(), pos);
					for(; pos < lim; ++pos)
						putchar(' ');
				}
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
