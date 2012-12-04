#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;
typedef pair<int, double> tim;
bool between(tim it, tim ft, tim tt) {
	if(it < ft) {
		if(it < tt && tt < ft)
			return true;
		else
			return false;
	}
	else {
		if(it < tt || tt < ft)
			return true;
		else
			return false;
	}
}
int main() {
	vector<tim> tv;
	for(int i = 1; i < 12; ++i) {
		tv.push_back(make_pair(i, i * 60.0 / 11));
	}
	tim it, ft;
	printf("Program 3 by team X\n");
	printf("Initial time  Final time  Passes\n");

	while(scanf("%d%lf%d%lf", &it.F, &it.S, &ft.F, &ft.S) != EOF) {
		int cnt = 0;
		for(int i = 0; i < tv.size(); ++i)
			if(between(it, ft, tv[i]))
				++cnt;
		printf("       %02d:%02d       %02d:%02d      %2d\n", it.F, (int)it.S, ft.F, (int)ft.S, cnt);
	}

	printf("End of program 3 by team X\n");
	return 0;
}
