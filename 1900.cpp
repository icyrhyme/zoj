#include <cstdio>
#include <bitset>
#include <algorithm>
#define MAXN 128
using namespace std;
bool cmp(bitset<128> a, bitset<128> b) {
	string stra = a.to_string<char, char_traits<char>, allocator<char> >();
	string strb = b.to_string<char, char_traits<char>, allocator<char> >();
	return stra < strb;
}
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		bitset<128> bs[MAXN];
		int u, v;
		while(scanf("%d%d", &u, &v) != EOF) {
			--u, --v;
			bs[u].set(v);
		}
		sort(bs, bs + n);
		int nn = unique(bs, bs + n) - bs;
		printf("%d\n", nn);
	}
	return 0;
}
