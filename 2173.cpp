#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int mw;
	while(scanf("%d", &mw) != EOF) {
		if(mw == 0)
			break;
		int cw = 0, ch = 0, ew, eh;
		int wndw = 0, wndh = 0;
		while(scanf("%d%d", &ew, &eh) != EOF) {
			if(ew == -1 && eh == -1)
				break;
			if(ew + cw > mw) {
				wndh += ch;
				wndw = max(wndw, cw);
				cw = ew;
				ch = eh;
			}
			else {
				cw += ew;
				ch = max(ch, eh);
			}
		}
		wndh += ch;
		wndw = max(wndw, cw);
		printf("%d x %d\n", wndw, wndh);
	}
	return 0;
}
