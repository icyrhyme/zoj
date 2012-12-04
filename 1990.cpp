#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 5000
using namespace std;
bool cmp(char *aptr, char* bptr) {
	return strcmp(aptr, bptr) < 0;
}
void _sort_substr(char s[], int begin, int end) {
	static char mem[MAXL];
	static char* ptrs[MAXL];
	static char* ptr;
	int k = 0;
	ptr = mem;
	for(int i = begin; i <= end; ++i) {
		int cnt = 0, j;
		ptrs[k++] = ptr;
		//*(ptr++) = s[i];
		for(j = i;; ++j) {
			if(s[j] == '0')
				++cnt;
			else
				--cnt;
			*(ptr++) = s[j];
			if(cnt == 0)
				break;
		}
		*(ptr++) = '\0';
		i = j;
	}
	int len = 0;
	sort(ptrs, ptrs + k, cmp);
	for(int i = 0; i < k; ++i) {
		for(int j = 0; ptrs[i][j]; ++j)
			s[begin + (len++)] = ptrs[i][j];
	}
}
void _gao(char s[], int begin, int end) {
	for(int i = begin; i <= end; ++i) {
		int cnt = 0, j;
		for(j = i;; ++j) {
			if(s[j] == '0')
				++cnt;
			else
				--cnt;
			if(cnt == 0)
				break;
		}
		_gao(s, i + 1, j - 1);
		i = j;
	}
	if(begin <= end)
		_sort_substr(s, begin, end);
}
void gao(char s[]) {
	int len = strlen(s);
	_gao(s, 0, len - 1);
}
int main() {
	int cs;
	char s[MAXL], t[MAXL];
	scanf("%d", &cs);
	while(cs--) {
		scanf("%s", s);
		scanf("%s", t);
		gao(s);
		//printf("%s\n", s);
		gao(t);
		//printf("%s\n", t);
		if(strcmp(s, t) == 0)
			printf("same\n");
		else
			printf("different\n");
	}
	return 0;
}
