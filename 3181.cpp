#include <iostream>
#define MAXK 26
#define MAXLEN 1024
#define MAXN 205
#define MOD 1000000007LL
#define LL long long
using namespace std;
int dp[MAXLEN][MAXLEN];
int sum[MAXLEN];
int mcnt[MAXLEN][MAXLEN];
struct trieNode {
       trieNode* sons[MAXK];
       int val;
       trieNode() {
	       for(int i = 0; i < MAXK; ++i)\
		       sons[i] = NULL;
	       val = 0;
       }
};
typedef trieNode *trie;
void insert(trie t, char s[]) {
	for(int i = 0; s[i] != '\0'; ++i) {
		if(t->sons[s[i] - 'A'] == NULL)
			t->sons[s[i] - 'A'] = new trieNode();
		t = t->sons[s[i] - 'A'];
	}
	++t->val;
}
void query(trie t, char pat[], int idx) {
	for(int i = idx; pat[i] != '\0'; ++i) {
		if(t->sons[pat[i] - 'A'] == NULL)
			return;
		t = t->sons[pat[i] - 'A'];
		mcnt[idx][i] = t->val;
	}
}
int drop(trie t) {
	for(int i = 0; i < MAXK; ++i)
		if(t->sons[i])
			drop(t->sons[i]);
	delete t;
}
int main() {
	int t;
	char str[MAXLEN];
	scanf("%d", &t);
	while(t--) {
		trie tr = new trieNode();
		scanf("%s", str);
		int n;
		char tmp[MAXN];
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", tmp);
			insert(tr, tmp);
		}
		memset(mcnt, 0, sizeof(mcnt));
		for(int i = 0; str[i] != '\0'; ++i)
			query(tr, str, i);
		int len = strlen(str);
		memset(sum, 0, sizeof(sum));
		sum[0] = 1;
		for(int j = 0; j < len; ++j) {
			int base = max(0, j - MAXN);
			for(int i = base; i <= j; ++i)
				dp[i][j] = (int)((LL)mcnt[i][j] * sum[i] % MOD);
			int temp = 0;
			for(int i = base; i <= j; ++i) {
				sum[i] = (sum[i] + temp) % MOD;
				temp = (temp + dp[i][j]) % MOD;
			}
		}
		int ans = 0;
		for(int i = max(0, len - MAXN); i < len; ++i) {
			ans = (ans + dp[i][len - 1]) % MOD;
		}
		printf("%d\n", ans);
		drop(tr);
	}
	return 0;
}
