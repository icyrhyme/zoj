#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	vector<pair<int, int> > vp;
	int n;
	bool isFirst = true;
	while(scanf("%d", &n) != EOF) {
		vp.clear();
		for(int i = 0; i < n; ++i) {
			pair<int, int> temp;
			scanf("%d", &temp.first);
			temp.second = i + 1;
			vp.push_back(temp);
		}
		sort(vp.begin(), vp.end());
		vector<pair<int, int> > ans;
		for(int i = 0; i < n; i += 2) {
			pair<int, int> temp;
			temp.first = vp[i].second;
			temp.second = vp[i + 1].second;
			if(temp.first > temp.second)
				swap(temp.first, temp.second);
			ans.push_back(temp);
		}
		sort(ans.begin(), ans.end());
		if(isFirst)
			isFirst = false;
		else
			printf("\n");
		for(int i = 0; i < ans.size(); ++i) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}
