#include <iostream>
#define INF 1000000000
#define MAXN 1024
using namespace std;
int primes[4] = {2, 3, 5, 7};
char num[MAXN];
int len, fcnt[MAXN][4];
int dfcnt[10][4], dcnt[10];
bool isOK(int idx, int d, int nfcnt[]) {
	int temp[4], cnt;
	for(int i = 0; i < 4; ++i)
		temp[i] = nfcnt[i];
	int od = num[idx] - '0';
	for(int i = 0; i < 4; ++i) {
		temp[i] -= dfcnt[d][i];
		if(temp[i] < 0)
			return false;
	}
	for(int i = 9; i >= 2; --i) {
		int mm = INF;
		for(int j = 0; j < 4; ++j)
			if(dfcnt[i][j] != 0)
				mm = min(mm, temp[j] / dfcnt[i][j]);
		for(int j = 0; j < 4; ++j)
			if(dfcnt[i][j] != 0)
				temp[j] -= mm * dfcnt[i][j];
		dcnt[i] = mm;
	}
	int sum = 0;
	for(int i = 2; i <= 9; ++i)
		sum += dcnt[i];
	if(sum <= idx)
		return true;
	else
		return false;
}
void change(int idx, int d, int nfcnt[]) {
	int j = 0;
	num[idx] = '0' + d;
	for(int i = 9; i >= 1; --i) {
		for(int k = 0; k < dcnt[i]; ++k, ++j)
			num[j] = '0' + i;
	}
	for(; j < idx; ++j) {
		num[j] = '1';
	}
}
void getNext() {
	int zeroIdx = -1;
	for(int i = len - 1; i >= 0; --i)
		if(num[i] == '0') {
			zeroIdx = i;
			break;
		}
	if(zeroIdx != -1) {
		int i;
		for(i = 0; i < len; ++i) {
			if(zeroIdx == 0 && i == 0)
				continue;
			if(num[i] == '9')
				continue;
			++num[i];
			break;
		}
		if(i == len) {
			num[len] = '1';
			++len;
			num[len] = '\0';
		}
		for(--i; i >= 0; --i)
			num[i] = '0';
		return;
	}
	memset(fcnt, 0, sizeof(fcnt));
	memset(dfcnt, 0, sizeof(dfcnt));
	for(int i = 1; i < 10; ++i)
		for(int j = 0; j < 4; ++j) {
			int d = i;
			while(d % primes[j] == 0) {
				++dfcnt[i][j];
				d /= primes[j];
			}
		}
	int nfcnt[4] = {0, 0, 0, 0};
	int i;
	for(i = 0; i < len; ++i) {
		for(int j = 0; j < 4; ++j)
			nfcnt[j] += dfcnt[num[i] - '0'][j];
		for(int j = num[i] - '0' + 1; j <= 9; ++j)
			if(isOK(i, j, nfcnt)) {
				change(i, j, nfcnt);
				return;
			}
	}
	num[len] = '1';
	++len;
	num[len] = '\0';
	if(isOK(len - 1, 1, nfcnt))
		change(len - 1, 1, nfcnt);
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", num);
		len = strlen(num);
		reverse(num, num + len);
		getNext();
		reverse(num, num + len);
		printf("%s\n", num);
	}
	return 0;
}
