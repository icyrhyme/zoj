#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		set<int> s;
		for(int i = 0; i <= m; ++i)
			for(int j = 0; j <= m; ++j)
				if(s.find(i * i * i + j * j * j) == s.end())
					s.insert(i * i * i + j * j * j);
		vector<int> v(s.begin(), s.end());
		vector<pair<int, int> > ans;
		int lim = 2 * m * m * m;
		for(int i = 0; i < v.size(); ++i) {
			for(int j = i + 1; j < v.size(); ++j) {
				int a = v[i], d = v[j] - v[i];
				if(a + (n - 1) * d > lim)
					break;
				bool ok = true;
				for(int k = a + (n - 1) * d; k >= a; k -= d) {
					if(s.find(k) == s.end()) {
						ok = false;
						break;
					}
				}
				if(ok)
					ans.push_back(make_pair(d, a));
			}
		}
		sort(ans.begin(), ans.end());
		if(csnum != 1)
			putchar('\n');
		printf("Case %d:\n", csnum);
		csnum++;
		if(!ans.empty()) {
			for(int i = 0; i < ans.size(); ++i)
				printf("%d %d\n", ans[i].second, ans[i].first);
		}
		else
			printf("NONE\n");
	}
	return 0;
}
