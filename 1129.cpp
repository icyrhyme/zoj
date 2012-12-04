#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#define MAXL 256
#define MAXP 32005
#define MAXA 10005
using namespace std;
template<class T>
class IDGen {
	map<T, int> mp;
	vector<T> v;
public:
	int size() {
		return v.size();
	}
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
int main() {
	int p, n;
	char line[MAXL];
	char name[MAXL];
	vector<int> papers[MAXP];
	int vis[MAXP];
	int onum[MAXA];
	int cs = 1;
	while(scanf("%d%d", &p, &n) != EOF && p != 0 && n != 0) {
		IDGen<string> ids;
		getchar();
		for(int i = 0; i < p; ++i) {
			gets(line);
			int len = strlen(line);
			for(int j = len - 1; line[j] != ':'; --j)
				line[j] = '\0';
			papers[i].clear();
			char *pch;
			pch = strtok(line, " ,:");
			while(pch != NULL)
			{
				strcpy(name, pch);
				pch = strtok(NULL, " ,:");
				if(pch != NULL) {
					strcat(name, ", ");
					strcat(name, pch);
					int id = ids.getId((string)name);
					//printf("%s\n", name);
					papers[i].push_back(id);
					pch = strtok(NULL, " ,:");
				}
			}
		}
		vector<vector<int> > authors(ids.size());
		for(int i = 0; i < p; ++i) {
			for(int j = 0; j < papers[i].size(); ++j)
				authors[papers[i][j]].push_back(i);
		}
		memset(onum, -1, MAXA * sizeof(int));
		memset(vis, 0, p * sizeof(int));
		int begin = ids.getId("Erdos, P.");
		onum[begin] = 0;
		queue<int> q;
		q.push(begin);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(vector<int>::iterator it = authors[u].begin(); it != authors[u].end(); ++it) {
				if(vis[*it])
					continue;
				vis[*it] = 1;
				for(vector<int>::iterator j = papers[*it].begin(); j != papers[*it].end(); ++j) {
					if(onum[*j] == -1) {
						onum[*j] = onum[u] + 1;
						q.push(*j);
					}	
				}
			}
		}
		printf("Database #%d\n", cs);
		for(int i = 0; i < n; ++i) {
			gets(line);
			int id = ids.getId((string)line);
			if(onum[id] == -1)
				printf("%s: infinity\n", line);
			else
				printf("%s: %d\n", line, onum[id]);
		}
		putchar('\n');
		++cs;
	}
	return 0;
}
