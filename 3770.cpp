#include <iostream>
#define MAXN 512
#define MAXC 512
using namespace std;
int p, q, mat[MAXN][MAXN], m, n;
Sum<int> cnt;
inline int lowbit(int x) {
	return (x & (x ^ (x - 1)));
}
template<class elemType>
class Sum{
public:
	elemType a[MAXN], c[MAXN], ret;
	int n;
	void init(int i) {
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		n = i;
	}
	void update(int i, elemType v) {
		v -= a[i];
		a[i] += v;
		for(i++; i <= n; i += lowbit(i)) {
			c[i - 1] += v;
		}
	}
	elemType query(int i) {
		for(ret = 0; i; i ^= lowbit(i)) {
			ret += c[i - 1];
		}
		return ret;
	}
}
int findMedian() {
	int le = 0, ri = 255;
	while(le <= ri) {
		int mid = (le + ri) / 2;
		int count = cnt.query(mid);
		if(count < (
	}
}
int main() {
	while(scanf("%d%d", &p, &q) != EOF) {
		for(int i = 1; i <= p; ++i)
			for(int j = 1; j <= q; ++j)
				scanf("%d", &mat[i][j]);
		scanf("%d%d", &m, &n);
		int ib = (m + 1) / 2, jb = (n + 1) / 2;
		int ie = p - (m - 1) / 2, je = q - (n - 1) / 2;
		for(int i = ib; i <= ie; ++i) {
			for(int j = jb; j <= je; ++j) {
				if(j == jb)
					for(int ii = ib - (m - 1) / 2; ii <= ib + (m - 1) / 2; ++ii)
						for(int jj = jb - (n - 1) / 2; jj <= jb + (n - 1) / 2; ++jj)
							cnt.update(mat[ii][jj], 1);
				int mid = findMedian();
				cnt.update(mat[i][j], -1);
				cnt.update(mid, 1);
				mat[i][j] = mid;
				if(j == je)
					continue;
				for(int ii = i - (m - 1) / 2; ii <= i + (m - 1) / 2; ++ii) {
					cnt.update(mat[ii][j - (n - 1) / 2], -1);
					cnt.update(mat[ii][j + (n - 1) / 2 + 1], 1);
				}
			}
		}
	}
}
