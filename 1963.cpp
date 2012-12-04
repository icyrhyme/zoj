#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXL 16
using namespace std;
double conv(char t[]) {
	if(strcmp(t, "-:--:--") == 0)
		return -1;
	int h, m, s;
	h = t[0] - '0';
	m = (t[2] - '0') * 10 + t[3] - '0';
	s = (t[5] - '0') * 10 + t[6] - '0';
	return (double)h * 3600 + m * 60 + s;
}
int main() {
	int n;
	double d;
	scanf("%d%lf", &n, &d);
	int id;
	while(scanf("%d", &id) != EOF) {
		double sec = 0;
		bool isok = true;
		char ti[MAXL];
		for(int i = 0; i < n; ++i) {
			scanf("%s", ti);
			double tsec = conv(ti);
			if(tsec >= 0) {
				sec += tsec;
			}
			else {
				isok = false;
			}
		}
		if(isok) {
			sec /= d;
			int isec = (int)(sec + 0.5);
			int min = isec / 60;
			isec = isec % 60;
			printf("%3d: %d:%02d min/km\n", id, min, isec); 
		}
		else
			printf("%3d: -\n", id);
	}
	return 0;
}
