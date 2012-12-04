#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXC 26
#define MAXN 128
#define MAXL 5000005
using namespace std;
char output[MAXL];
char str[MAXN][8];
class Trie {
public:
	struct trieNode {
		trieNode* e[MAXC];
		char* os;
		bool ambi;
		trieNode() {
			for(int i = 0; i < MAXC; ++i)
				e[i] = NULL;
			os = NULL;
			ambi = false;
		}
	};
	trieNode* root;
	Trie() {
		root = new trieNode();
	}
	typedef trieNode* iter;
	void insert(char s[]) {
		int len = strlen(s);
		for(int i = 1; i < (1 << len); ++i) {
			iter it = root;
			for(int j = 0; j < len; ++j) {
				if(i & (1 << j)) {
					if(it->e[s[j] - 'A'] == NULL) {
						it->e[s[j] - 'A'] = new trieNode();
					}
					it = it->e[s[j] - 'A'];
				}
			}
			if(!it->ambi) {
				if(it->os == NULL || it->os == s)
					it->os = s;
				else
					it->ambi = true;
			}
		}
	}
	void decode() {
		iter it = root;
		char c;
		int oi = 0;
		bool flag = false;
		while(true) {
			c = getchar();
			int idx = c - 'A';
			if(isalpha(c)) {
				it = it->e[idx];
				flag = true;
			}
			else {
				if(it->ambi) {
					strcpy(output, "AMBIGUITY");
					while(getchar() != '#')
						;
					return;
				}
				if(it != root)
					for(int i = 0; it->os[i]; ++i)
						output[oi++] = it->os[i];
				if(c != '#')
					output[oi++] = c;
				else
					break;
				it = root;
			}
		}
		output[oi] = '\0';
		if(!flag)
			strcpy(output, "AMBIGUITY");
	}
	void _drop(iter it) {
		for(int i = 0; i < MAXC; ++i)
			if(it->e[i] != NULL)
				_drop(it->e[i]);
		delete it;
	}
	void clear() {
		_drop(root);
		root = new trieNode();
	}
} tr;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", str[i]);
			tr.insert(str[i]);
		}
		getchar();
		tr.decode();
		printf("%s\n", output);
		if(cs != 0)
			putchar('\n');
		tr.clear();
	}
	return 0;
}
