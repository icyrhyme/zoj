#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 128
#define MAXL 32
#define MAXPL 128
using namespace std;
bool cmp(char* sa, char* sb) {
	if(strcmp(sa, sb) < 0)
		return true;
	else
		return false;
}
bool isMatch(int cnt[], char p[]) {
	bool match = false;
	for(int i = 0; p[i] != '\0';) {
		int j;
		bool umatch = false, smatch = true;
		for(j = i; p[j] != '\0' && p[j] != '|'; ++j) {
			switch(p[j]) {
				case '+':
					++j;
					if(cnt[p[j] - 'a'] == 0)
						smatch = false;
					break;
				case '-':
					++j;
					if(cnt[p[j] - 'a'] != 0)
						smatch = false;
					break;
				default:
					if(cnt[p[j] - 'a'] != 0)
						umatch = true;
					break;
			}
			//printf("%d %d\n", (int)umatch, (int)smatch);
		}
		//printf("%d\n", (int)match);
		match = (match || (umatch && smatch));
		if(p[j] == '|')
			i = j + 1;
		else
			i = j;
	}
	return match;
}
int main() {
	char data[MAXN][MAXL];
	char *words[MAXN];
	int cnt[MAXN][MAXL];
	while(true) {
		bool isQuit = false;
		int n;
		for(int i = 0; ; n = ++i) {
			scanf("%s", data[i]);
			if(strcmp(data[i], "#") == 0) {
				isQuit = true;
				break;
			}
			else if(strcmp(data[i], "*") == 0) {
				break;
			}
			words[i] = data[i];
		}
		if(isQuit) {
			break;
		}
		sort(words, words + n, cmp);
		for(int i = 0; i < n; ++i) {
			//printf("%s\n", words[i]);
			fill(cnt[i], cnt[i] + MAXL, 0);
			for(int j = 0; words[i][j]; ++j) {
				++cnt[i][words[i][j] - 'a'];
			}
		}
		char pattern[MAXPL];
		while(true) {
			scanf("%s", pattern);
			if(strcmp(pattern, "**") == 0)
				break;
			int i;
			for(i = 0; i < n; ++i) {
				if(isMatch(cnt[i], pattern)) {
					printf("%s\n", words[i]);
					break;
				}
			}
			if(i == n)
				printf("NONE\n");
		}
		printf("$\n");
	}
	return 0;
}
