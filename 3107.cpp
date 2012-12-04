#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define MAXL 128
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int conv(char ch) {
	switch(ch) {
		case 'U': return 0;
		case 'D': return 1;
		case 'R': return 2;
		case 'L': return 3;
		default: return -1;
	}
}
int main() {
	int cs, csnum = 1;
	char cmd[MAXL];
	scanf("%d", &cs);
	while(cs--) {
		map<int, vector<int> > mp;
		scanf("%s", cmd);
		int x = 0, y = 0, nx, ny, k;
		for(int i = 0; cmd[i]; ++i) {
			k = conv(cmd[i]);
			nx = x + dx[k];
			ny = y + dy[k];
			if(cmd[i] == 'R')
				mp[x].push_back(y);
			else if(cmd[i] == 'L')
				mp[nx].push_back(y);
			x = nx;
			y = ny;
		}
		map<int, vector<int> >::iterator it;
		vector<int>::iterator vit;
		int ans = 0, a, b;
		for(it = mp.begin(); it != mp.end(); ++it) {
			sort(it->second.begin(), it->second.end());
			for(vit = it->second.begin(); vit != it->second.end(); ++vit) {
				a = *vit;
				b = *(++vit);
				ans += b - a;
			}
		}
		printf("case %d: %d\n", csnum, ans);
		csnum++;
	}
	return 0;
}
