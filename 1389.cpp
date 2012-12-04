#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		scanf("%d", &n);
		map<int, int> mp;
		for(int i = 0; i < n; ++i) {
			int b, h, w, d;
			scanf("%d%d%d%d", &b, &h, &w, &d);
			mp[b] += w * d;
			mp[b + h] -= w * d;
		}
		int vol;
		scanf("%d", &vol);
		map<int, int>::iterator it = mp.begin();
		int area = it->second;
		double he = it->first;
		for(++it; it != mp.end(); ++it) {
			if(area * (it->first - he) >= vol) {
				he += 1.0 * vol / area;
				vol = 0;
				break;
			}
			vol -= area * (it->first - he);
			area += it->second;
			he = it->first;
		}
		if(it == mp.end())
			printf("OVERFLOW\n");
		else
			printf("%.2lf\n", he);
	}
	return 0;
}
