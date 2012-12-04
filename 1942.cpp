#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAXN 256
using namespace std;
class DisjointSet {
	int a[MAXN];
	int n;
public:
	void init(int nn) {
		int n = nn;
		fill(a, a + n, -1);
	}
	int find(int x) {
		if(a[x] < 0)
			return x;
		else
			return (a[x] = find(a[x]));
	}
	void setUnion(int u, int v) {
		int ur = find(u);
		int vr = find(v);
		if(ur != vr) {
			if(a[ur] > a[vr]) 
				swap(ur, vr);
			a[ur] += a[vr];
			a[vr] = ur;
		}
	}
};
inline double dist(pair<int, int> p1, pair<int, int> p2) {
	int dx = p2.first - p1.first, dy = p2.second - p1.second;
	return sqrt(1.0 * dx * dx + dy * dy);
}
int main() {
	int n, csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		vector<pair<int, int> > vp;
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			vp.push_back(make_pair(x, y));
		}
		double le = 1e100, ri = -1;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j) {
				double d = dist(vp[i], vp[j]);
				le = min(le, d);
				ri = max(ri, d);
			}
		while(ri - le > 1e-5) {
			double mi = (le + ri) / 2;
			DisjointSet di;
			di.init(n);
			for(int i = 0; i < n; ++i)
				for(int j = i + 1; j < n; ++j) {
					double d = dist(vp[i], vp[j]);
					if(d < mi)
						di.setUnion(i, j);
				}
			if(di.find(0) == di.find(1))
				ri = mi;
			else
				le = mi;
		}
		printf("Scenario #%d\n", csnum);
		printf("Frog Distance = %.3lf\n\n", ri);
		++csnum;
	}
	return 0;
}
