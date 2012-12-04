#include <cstdio>
#include <vector>
#include <cstring>
#define MAXL 32
using namespace std;
int getMask(char r[]) {
	int msk = 0;
	for(int i = 0; r[i]; ++i)
		msk |= (1 << (r[i] - 'a'));
	return msk;
}
void printRights(int msk) {
	for(char c = 'a'; c <= 'z'; ++c) {
		if(msk & 1)
			putchar(c);
		msk >>= 1;
	}
}
int main() {
	int csnum = 1;
	while(true) {
		bool quit = false;
		char sep;
		char e[MAXL], x[MAXL], r[MAXL];
		int acl[MAXL], msk;
		memset(acl, 0, sizeof(acl));
		while(true) {
			scanf("%[^-+=\n]", e);
			if(e[0] == '#') {
				quit = true;
				break;
			}
			scanf("%[-+=]%[a-z]", x, r);
			msk = getMask(r);
			for(int i = 0; e[i]; ++i) {
				int j = e[i] - 'A';
				switch(x[0]) {
					case '+': acl[j] |= msk; break;
					case '-': acl[j] &= (~msk); break;
					case '=': acl[j] = msk; break;
				}
			}
			sep = getchar();
			if(sep == '\n')
				break;
		}
		if(quit)
			break;
		vector<int> key, val;
		for(int i = 0; i < 26; ++i) {
			if(acl[i] == 0)
				continue;
			key.push_back(i);
			val.push_back(acl[i]);
		}
		printf("%d:", csnum);
		csnum++;
		for(int i = 0; i < key.size(); ++i) {
			putchar(key[i] + 'A');
			if(i != key.size() - 1 && val[i] == val[i + 1]) {
				continue;
			}
			printRights(val[i]);
		}
		putchar('\n');
	}
	return 0;
}
