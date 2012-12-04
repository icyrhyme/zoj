#include <cstdio>
#include <string>
#include <map>
#define MAXN 32
#define MAXL 128
using namespace std;
template <class T>
class IDSet {
	map<T, int> mp;
public:
	int getId(T elem) {
		if(mp.find(elem) == mp.end()) {
			int id = mp.size();
			mp[elem] = id;
		}
		return mp[elem];
	}
};
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		IDSet<string> ids;
		char name[MAXL];
		char party[MAXN][MAXL];
		int cnt[MAXN];
		gets(name);
		for(int i = 0; i < n; ++i) {
			gets(name);
			gets(party[i]);
			ids.getId((string)name);
		}
		int m;
		scanf("%d", &m);
		fill(cnt, cnt + n, 0);
		gets(name);
		for(int i = 0; i < m; ++i) {
			gets(name);
			int id = ids.getId((string)name);
			if(id < n)
				cnt[id]++;
		}
		int mcnt = 1, maxv = -1, midx;
		for(int i = 0; i < n; ++i) {
			if(cnt[i] > maxv) {
				maxv = cnt[i];
				midx = i;
				mcnt = 1;
			}
			else if(cnt[i] == maxv) {
				mcnt++;
			}
		}
		if(mcnt == 1) {
			printf("%s\n", party[midx]);
		}
		else
			printf("tie\n");
	}
	return 0;
}
