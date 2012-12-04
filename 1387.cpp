#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#define MAXL 10005
using namespace std;
char codes[32][8] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
};
inline int getIdx(char c) {
	if(c == '.')
		return 0;
	else
		return 1;
}
class Trie {
	struct trieNode {
		int cnt;
		struct trieNode* child[2];
		trieNode() {
			cnt = 0;
			child[0] = child[1] = NULL;
		}
	};
	trieNode* root;
	void _drop(trieNode* x) {
		for(int i = 0; i < 2; ++i)
			if(x->child[i] != NULL)
				_drop(x->child[i]);
		delete x;
	}
public:
	typedef trieNode* iterator;
	void clear() {
		for(int i = 0; i < 2; ++i)
			if(root->child[i] != NULL)
				_drop(root->child[i]);
		root->child[0] = root->child[1] = NULL;
	}
	Trie() {
		root = new trieNode();
	}
	~Trie() {
		_drop(root);
	}
	void insert(char s[]) {
		trieNode* it = root;
		for(int i = 0; s[i]; ++i) {
			int idx = getIdx(s[i]);
			if(it->child[idx] == NULL) {
				it->child[idx] = new trieNode();
			}
			it = it->child[idx];
		}
		it->cnt++;
	}
	vector<pair<int, int> > search(char s[]) {
		assert(root != NULL);
		trieNode* it = root;
		vector<pair<int, int> > ret;
		for(int i = 0; s[i]; ++i) {
			int idx = getIdx(s[i]);
			if(it->child[idx] != NULL) {
				it = it->child[idx];
				if(it->cnt > 0)
					ret.push_back(make_pair(i, it->cnt));
			}
			else {
				break;
			}
		}
		return ret;
	}
};
void encode(char str[]) {
	char tmp[MAXL] = "";
	for(int i = 0; str[i]; ++i) {
		strcat(tmp, codes[str[i] - 'A']);
	}
	strcpy(str, tmp);
}
char txt[MAXL];
int memo[MAXL];
Trie t;
int search(int idx) {
	if(txt[idx] == '\0')
		return 1;
	if(memo[idx] != -1)
		return memo[idx];
	vector<pair<int, int> > v = t.search(txt + idx);
	memo[idx] = 0;
	for(int i = v.size() - 1; i >= 0; --i) {
		memo[idx] += search(idx + v[i].first + 1) * v[i].second;
	}
	return memo[idx];
}
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		char str[MAXL];
		int n;
		scanf("%s", txt);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", str);
			encode(str);
			t.insert(str);
		}
		fill(memo, memo + strlen(txt), -1);
		printf("%d\n", search(0));
		t.clear();
	}
	return 0;
}
