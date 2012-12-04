#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x7fffffff
using namespace std;
int main() {
	int csnum = 1;
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		vector<pair<int, int> > vp;
		int minx = -INF, maxx = INF, miny = -INF, maxy = INF;
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			vp.push_back(make_pair(x, y));
		}
		for(int j = n - 1, i = 0; i < n; j = i++) {
			if(vp[j].first == vp[i].first) {
				if(vp[j].second < vp[i].second) {
					minx = max(minx, vp[i].first);
				}
				else {
					maxx = min(maxx, vp[i].first);
				}
			}
			else {
				if(vp[j].first < vp[i].first) {
					maxy = min(maxy, vp[i].second);
				}
				else {
					miny = max(miny, vp[i].second);
				}
			}
		}
		printf("Floor #%d\n", csnum);
		csnum++;
		if(minx <= maxx && miny <= maxy) {
			printf("Surveillance is possible.\n");
		}
		else {
			printf("Surveillance is impossible.\n");
		}
		putchar('\n');
	}
}
