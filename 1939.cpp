#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 128
#define MAXL 32
template <class T>
class IDSet {
	map<T, int> mp;
	vector<T> v;
public:
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
			v.push_back(elem);
		}
		return mp[elem];
	}
	T getElem(int id) {
		return v[id];
	}
};
int input(int a[], IDSet<string>& ids) {
	int i;
	char word[MAXL];
	i = 0;
	while(scanf("%s", word) != EOF && strcmp(word, "#") != 0) {
		a[i] = ids.getId((string)word);
		++i;
	}
	return i;
}
int dx[3] = {-1, -1, 0};
int dy[3] = {-1, 0, -1};
int main() {
	int a[MAXN], b[MAXN];
	while(true) {
		int n, m;
		IDSet<string> ids;
		n = input(a, ids);
		if(n == 0)
			break;
		m = input(b, ids);
		int dp[MAXN][MAXN], pre[MAXN][MAXN];
		for(int i = 0; i <= n; ++i)
			dp[i][0] = 0;
		for(int j = 0; j <= m; ++j)
			dp[0][j] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) {
				if(a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					pre[i][j] = 0;
				}
				else {
					if(dp[i - 1][j] > dp[i][j - 1]) {
						dp[i][j] = dp[i - 1][j];
						pre[i][j] = 1;
					}
					else {
						dp[i][j] = dp[i][j - 1];
						pre[i][j] = 2;
					}
				}
			}
		vector<int> ans;
		for(int i = n, j = m; i > 0 && j > 0; ) {
			if(pre[i][j] == 0) {
				ans.push_back(a[i - 1]);
			}
			int tmp = pre[i][j];
			i += dx[tmp];
			j += dy[tmp];
		}
		vector<int>::reverse_iterator it;
		for(it = ans.rbegin(); it != ans.rend(); ++it) {
			printf("%s%c", ids.getElem(*it).c_str(), (it == ans.rend() - 1 ? '\n' : ' '));
		}
	}
	return 0;
}
