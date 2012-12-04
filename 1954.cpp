#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;
int dxs[6] = {0, 1, 1, 0, -1, -1};
int dys[6] = {-1, -1, 0, 1, 1, 0};
int getType(int x, int y) {
	if(x < 0 && y > 0 && x + y == 0)
		return 0;
	if(x < 0 && y == 0)
		return 1;
	if(x == 0 && y < 0)
		return 2;
	if(x > 0 && y < 0 && x + y == 0)
		return 3;
	if(x > 0 && y == 1)
		return 4;
	if(x == 0 && y > 0)
		return 5;
	return -1;
}
int main() {
	vector<pair<int, int> > vp;
	vp.push_back(make_pair(0, 0));
	vp.push_back(make_pair(0, 1));
	int x = -1, y = 1, dx, dy;
	for(int i = 0; i < 100000; ++i) {
		vp.push_back(make_pair(x, y));
		int type = getType(x, y);
		if(type >= 0) {
			dx = dxs[type];
			dy = dys[type];
		}
		x += dx;
		y += dy;
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		assert(n < 100000);
		--n;
		printf("%d %d\n", vp[n].first, vp[n].second);
	}
	return 0;
}
