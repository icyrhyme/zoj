#include <iostream>
#include <set>
#include <string>
#include <map>
#include <cstdio>
#define MAXL 64
using namespace std;
bool gao(int n) {
	char tmp[MAXL];
	map<string, int> mp;
	int state = -1, cnt, cir;
	gets(tmp);
	bool res = true;
	for(int i = 0; i < n; ++i) {
		gets(tmp);
		if(!res)
			continue;
		string s(tmp);
		if(state == -1) {
			if(mp.find(s) == mp.end()) {
				mp[s] = 1;
			}
			else {
				++mp[s];
				cnt = 1;
				state = 2;
				cir = i;
			}
		}
		else {
			if(mp.find(s) == mp.end()) {
				res = false;
				continue;
			}
			else {
				if(cnt == cir) {
					cnt = 0;
					++state;
				}
				if(++mp[s] != state) {
					res = false;
					continue;
				}
				++cnt;
			}
		}
	}
	return res;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(gao(n))
			printf("Either\n");
		else
			printf("Random\n");
	}
	return 0;
}
