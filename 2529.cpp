#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#define MAXL 256
#define MAXN 32
using namespace std;
vector<int> plst;
bool isPrime(int x) {
	if(x == 0 || x == 1)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}
int add(int a[], int alen, int b[], int blen) {
	int c = 0, i;
	for(i = 0; i < max(alen, blen); ++i) {
		int newc = (a[i] + b[i] + c) / plst[i];
		a[i] = (a[i] + b[i] + c) % plst[i];
		c = newc;
	}
	if(c != 0)
		a[i++] = c;
	return i;
}
int main() {
	for(int i = 2; ; ++i) {
		if(isPrime(i)) {
			plst.push_back(i);
			if(plst.size() == MAXN)
				break;
		}
	}
	//for(auto it = plst.begin(); it != plst.end(); ++it)
	//	printf("%d\n", *it);
	char abuf[MAXL], bbuf[MAXL];
	int a[MAXN], b[MAXN];
	int alen, blen;
	while(scanf("%s%s", abuf, bbuf) != EOF) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		string str = abuf;
		istringstream iss(str);
		for(alen = 0; ;++alen) {
			iss >> a[alen];
			char tmp;
			if(iss >> tmp)
				;
			else
				break;
		}
		str = bbuf;
		iss.clear();
		iss.str(str);
		for(blen = 0; ;++blen) {
			iss >> b[blen];
			char tmp;
			if(iss >> tmp)
				;
			else
				break;
		}
		++alen;
		++blen;
		reverse(a, a + alen);
		reverse(b, b + blen);
		int len = add(a, alen, b, blen);
		for(int i = len - 1; i >= 0; --i)
			printf("%d%c", a[i], (i == 0 ? '\n' : ','));
	}
	return 0;
}
