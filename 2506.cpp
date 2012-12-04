#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int gcd(int a, int b) {
	return (a == 0 ? b : gcd(b % a, a));
}
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int a, b, lim;
		scanf("%d/%d", &a, &b);
		scanf("%d", &lim);
		int g = gcd(a, b);
		a /= g;
		b /= g;
		int aa = a, bb = b;
		vector<int> cf;
		while(bb > 0) {
			cf.push_back(aa / bb);
			aa -= aa / bb * bb;
			swap(aa, bb);
		}
		vector<pair<int, int> > frac;
		frac.push_back(make_pair(cf[0], 1));
		frac.push_back(make_pair(cf[0] * cf[1] + 1, cf[1]));
		for(int i = 2; i < cf.size(); ++i) {
			int s = cf[i] * frac[i - 1].first + frac[i - 2].first;
			int t = cf[i] * frac[i - 1].second + frac[i - 2].second;
			if(t <= lim)
				frac.push_back(make_pair(s, t));
			else
				break;
		}
		vector<pair<int, int> >::reverse_iterator rit;
		for(rit = frac.rbegin(); rit != frac.rend(); ++rit) {
			if(rit->second <= lim) {
				printf("%d/%d\n", rit->first, rit->second);
				break;
			}
		}
	}
	return 0;
}
