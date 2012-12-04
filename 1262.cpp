#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#define MAXN 16
#define GETB(num,i) ((num)&(1<<(i))?1:0)
#define SETB(num,i) ((num)|=(1<<(i)))
#define CLRB(num,i) ((num)&=~(1<<(i)))
using namespace std;
int s2i(char s[]) {
	int ret = 0;
	for(int i = 0; s[i]; ++i)
		ret = (ret << 1) + s[i] - 'a';
	return ret;
}
int tab[8];
int n;
inline int jus(int x) {
	if(x < 0)
		x += n;
	else if(x >= n)
		x -= n;
	return x;
}
int getNext(int num) {
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		int b1, b2, b3;
		b1 = GETB(num, jus(i - 2));
		b2 = GETB(num, i);
		b3 = GETB(num, jus(i + 1));
		int idx = b1 * 4 + b2 * 2 + b3;
		if(tab[idx])
			SETB(ret, i);
	}
	return ret;
}
void shift(string& s) {
	char c = s[0];
	for(int i = 1; i < (int)s.size(); ++i)
		s[i - 1] = s[i];
	s[s.size() - 1] = c;
}
void printRes(int res) {
	string sres(n, 'a');
	for(int i = 0; i < n; ++i) {
		if(res & 1)
			sres[i] = 'b';
		else
			sres[i] = 'a';
		res >>= 1;
	}
	reverse(sres.begin(), sres.end());
	string mins = sres;
	for(int i = 0; i < n; ++i) {
		shift(sres);
		if(sres < mins)
			mins = sres;
	}
	printf("%s\n", mins.c_str());
}
int getNum(int num, int s) {
	int step[1 << MAXN];
	vector<int> v;
	fill(step, step + (1 << n), -1);
	int st = 0;
	while(step[num] == -1) {
		step[num] = st;
		v.push_back(num);
		if(st == s)
			return num;
		++st;
		num = getNext(num);
	}
	int clen = st - step[num];
	int rem = step[num];
	return v[rem + (s - rem) % clen];
}
int main() {
	while(scanf("%d", &n) != EOF) {
		char str[MAXN];
		char snum[MAXN];
		scanf("%s", snum);
		reverse(snum, snum + n);
		for(int i = 0; i < 8; ++i) {
			scanf("%s", str);
			int val = str[3] - 'a';
			str[3] = 0;
			int idx = s2i(str);
			tab[idx] = val;
		}
		int s;
		scanf("%d", &s);
		int num = s2i(snum);
		int res = getNum(num, s);
		printRes(res);
	}
}
