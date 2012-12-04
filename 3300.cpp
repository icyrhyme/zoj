#include <iostream>
#include <vector>
using namespace std;
bool isOk(int cnt[]) {
	int tmp[16];
	for(int i = 1; i <= 9; ++i) {
		tmp[i] = cnt[i];
	}
	for(int i = 1; i <= 9; ++i) {
		if(tmp[i] == 3) {
			tmp[i] = 0;
		}
		else if(i + 2 <= 9) {
			tmp[i + 1] -= tmp[i] % 3;
			tmp[i + 2] -= tmp[i] % 3;
			tmp[i] = 0;
			if(tmp[i + 1] < 0 || tmp[i + 2] < 0)
				return false;
		}
	}
	for(int i = 1; i <= 9; ++i) {
		if(tmp[i] != 0)
			return false;
	}
	return true;
}
int main() {
	int cnt[16], tile;
	while(scanf("%d", &tile) != EOF) {
		vector<int> res;
		memset(cnt, 0, sizeof(cnt));
		++cnt[tile];
		for(int i = 0; i < 12; ++i) {
			scanf("%d", &tile);
			++cnt[tile];
		}
		for(int i = 1; i <= 9; ++i) {
			if(cnt[i] + 1 > 4)
				continue;
			++cnt[i];
			bool found = false;
			for(int j = 1; j <= 9 && !found; ++j) {
				if(cnt[j] - 2 < 0)
					continue;
				cnt[j] -= 2;
				if(isOk(cnt)) {
					found = true;
					res.push_back(i);
				}
				cnt[j] += 2;
			}
			--cnt[i];
		}
		for(int i = 0; i < res.size(); ++i) {
			printf("%d%c", res[i], (i == res.size() - 1 ? '\n' : ' '));
		}
	}
	return 0;
}
