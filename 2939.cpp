#include <cstdio>
#include <vector>
#include <cstring>
#define MAXL 64
using namespace std;
int c2i(char ch) {
	switch(ch) {
		case 'I': return 1; break;
		case 'V': return 5; break;
		case 'X': return 10; break;
		case 'L': return 50; break;
		case 'C': return 100; break;
		case 'D': return 500; break;
		case 'M': return 1000; break;
		default: return -1; break;
	}
}
int conv(char r[]) {
	int len = strlen(r), ret = 0;
	for(int i = 0; i < len; ++i) {
		if(i + 1 < len && c2i(r[i + 1]) > c2i(r[i])) {
			ret -= c2i(r[i]);
		}
		else
			ret += c2i(r[i]);
	}
	return ret;
}
char one[3] = {'I', 'X', 'C'};
char five[3] = {'V', 'L', 'D'};
char ten[3] = {'X', 'C', 'M'};
void rconv(char r[], int num) {
	vector<int> d;
	while(num > 0) {
		d.push_back(num % 10);
		num /= 10;
	}
	int k = 0;
	for(int i = d.size() - 1; i >= 0; --i) {
		if(i == 3) {
			while(d[i]--) {
				r[k++] = 'M';
			}
		}
		else {
			if(d[i] >= 1 && d[i] <= 3) {
				while(d[i]--) {
					r[k++] = one[i];
				}
			}
			else if(d[i] == 4) {
				r[k++] = one[i];
				r[k++] = five[i];
			}
			else if(d[i] >= 5 && d[i] <= 8) {
				r[k++] = five[i];
				d[i] -= 5;
				while(d[i]--) {
					r[k++] = one[i];
				}
			}
			else if(d[i] == 9) {
				r[k++] = one[i];
				r[k++] = ten[i];
			}
		}
	}
	r[k] = '\0';
}
int main() {
	int n, csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		int sum = 0;
		char r[MAXL];
		for(int i = 0; i < n; ++i) {
			scanf("%s", r);
			sum += conv(r);
		}
		rconv(r, csnum);
		printf("Case %s: ", r); 
		rconv(r, sum);
		printf("%s\n", r);
		++csnum;
	}
	return 0;
}
