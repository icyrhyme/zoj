#include <iostream>
#include <vector>
#define MAXLEN 128
using namespace std;

int parseInt(char s[]) {
	int ret = 0;
	for(int i = 0; s[i] != '\0'; ++i)
		ret = ret * 10 + s[i] - '0';
	return ret;
}
#define MAXP 128
bool isPrime[MAXP];
int dcnt;
vector<int> nextDay(vector<int> d);
void init() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i < 60; ++i)
		if(isPrime[i])
			for(int j = i; j * i < 60; ++j)
				isPrime[j * i] = false;
	vector<int> d(3);
	d[0] = 1999;
	d[1] = d[2] = 1;
	dcnt = 0;
	for(; !(d[1] == 12 && d[2] == 31); d = nextDay(d)) {
		if(isPrime[d[1]] && isPrime[d[2]]) {
			++dcnt;
			//printf("%d %d %d\n", d[0], d[1], d[2]);
		}
	}
}
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
inline bool isLegal(vector<int> d) {
	if(d[1] <= 0 || d[1] > 12) {
		return false;
	}
	if(d[1] == 2) {
		return d[2] > 0 && d[2] <= 28 + isLeap(d[0]);
	}
	return d[2] > 0 && d[2] <= days[d[1] - 1];
}
vector<int> nextDay(vector<int> d) {
	++d[2];
	if(isLegal(d))
		return d;
	d[2] = 1;
	++d[1];
	if(isLegal(d))
		return d;
	d[1] = 1;
	++d[0];
	return d;
}
vector<int> sd(3), ed(3);
int solve() {
	int ans = 0;
	if(sd[0] == ed[0]) {
		vector<int> d = sd;
		for(; d != nextDay(ed); d = nextDay(d))
			if(isPrime[d[1]] && isPrime[d[2]])
					++ans;
		return ans;
	}
	vector<int> d = sd;
	for(; !(d[1] == 12 && d[2] == 31); d = nextDay(d)) {
		if(isPrime[d[1]] && isPrime[d[2]])
				++ans;
	}
	d = ed;
	d[1] = d[2] = 1;
	for(; d != nextDay(ed); d = nextDay(d)) {
		if(isPrime[d[1]] && isPrime[d[2]])
			++ans;
	}
	int lycnt = 0, nlycnt = 0;
	for(int i = sd[0] + 1; i < ed[0]; ++i)
		if(isLeap(i))
			++lycnt;
		else
			++nlycnt;
	return (ans + nlycnt * dcnt + lycnt * (dcnt + 1));
}
int main() {
	init();
	int T;
	scanf("%d", &T);
	while(T--) {
		char s[MAXLEN];
		for(int i = 0; i < 3; ++i) {
			scanf("%s", s);
			sd[i] = parseInt(s);
		}
		for(int i = 0; i < 3; ++i) {
			scanf("%s", s);
			ed[i] = parseInt(s);
		}
		printf("%d\n", solve());
	}
	return 0;
}
