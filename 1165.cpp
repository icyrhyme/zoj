#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
int gcd(int a, int b) {
	return (a == 0 ? b : gcd(b % a, a));
}
int main() {
	int x, y;
	while(scanf("%d%d", &x, &y) != EOF) {
		if(x == 0 && y == 0)
			break;
		vector<pair<int, int> > vp;
		vp.PB(MP(x, y));
		while(scanf("%d%d", &x, &y) != EOF) {
			if(x == 0 && y == 0)
				break;
			vp.PB(MP(x, y));
		}
		set<pair<int, pair<int, int> > > s;
		vector<vector<int> > ans;
		for(int i = 0; i < vp.size(); ++i) {
			map<pair<int, int>, vector<int> > mp;
			int x1 = vp[i].FI, y1 = vp[i].SE;
			for(int j = i + 1; j < vp.size(); ++j) {
				int x2 = vp[j].FI, y2 = vp[j].SE;
				int dx = x2 - x1, dy = y2 - y1;
				if(dx < 0) {
					dx = -dx;
					dy = -dy;
				}
				int g = gcd(abs(dx), abs(dy));
				dx /= g;
				dy /= g;
				map<pair<int, int>, vector<int> >::iterator mit = mp.find(MP(dx, dy));
				set<pair<int, pair<int, int> > >::iterator sit = s.find(MP(i, MP(dx, dy)));
				if(sit == s.end()) {
					if(mit == mp.end()) {
						vector<int> tmp;
						tmp.PB(i);
						mp[MP(dx, dy)] = tmp;
					}
					else {
						mit->SE.PB(i);
					}
					s.insert(MP(i, MP(dx, dy)));
				}
				sit = s.find(MP(j, MP(dx, dy)));
				mit = mp.find(MP(dx, dy));
				if(sit == s.end()) {
					if(mit == mp.end()) {
						vector<int> tmp;
						tmp.PB(j);
						mp[MP(dx, dy)] = tmp;
					}
					else {
						mit->SE.PB(j);
					}
					s.insert(MP(j, MP(dx, dy)));
				}
			}
			map<pair<int, int>, vector<int> >::iterator mit;
			for(mit = mp.begin(); mit != mp.end(); ++mit) {
				if(mit->SE.size() > 2)
					ans.push_back(mit->SE);
			}
		}
		vector<vector<pair<int, int> > > vvp(ans.size());
		for(int i = 0; i < ans.size(); ++i) {
			for(int j = 0; j < ans[i].size(); ++j)
				vvp[i].PB(MP(vp[ans[i][j]].FI, vp[ans[i][j]].SE));
			sort(vvp[i].begin(), vvp[i].end());
		}
		sort(vvp.begin(), vvp.end());
		if(!vvp.empty()) {
			printf("The following lines were found:\n");
			for(int i = 0; i < vvp.size(); ++i) {
				for(int j = 0; j < vvp[i].size(); ++j) {
					printf("(%4d,%4d)", vvp[i][j].FI, vvp[i][j].SE);
				}
				putchar('\n');
			}
		}
		else {
			printf("No lines were found\n");
		}
	}
	return 0;
}
