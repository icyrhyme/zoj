#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#define MAXL 64
using namespace std;
bool isSlurpy(char str[]) {
	stack<char> s;
	s.push('Z');
	int i = 0, len = strlen(str);
	while(!s.empty()) {
		if(i == len)
			return false;
		char in = str[i], sym = s.top();
		//printf("%c %s\n", sym, str + i);
		s.pop();
		if(sym <= 'H') {
			if(in == sym) {
				++i;
			}
			else
				return false;
			continue;
		}
		switch(sym) {
			case 'Z':
				if(in == 'A') {
					s.push('Y');
					s.push('X');
				}
				else
					return false;
				break;
			case 'X':
				if(in == 'A') {
					s.push('R');
					s.push('A');
				}
				else
					return false;
				break;
			case 'Y':
				switch(in) {
					case 'D':
					case 'E':
						s.push('L');
						s.push('S');
						s.push('P');
						break;
					default:
						return false;
				}
				break;
			case 'R':
				switch(in) {
					case 'B':
						s.push('C');
						s.push('X');
						s.push('B');
						break;
					case 'D':
					case 'E':
						s.push('C');
						s.push('Y');
						break;
					case 'H':
						s.push('H');
						break;
					default:
						return false;
				}
				break;
			case 'P':
				switch(in) {
					case 'D':
						s.push('D');
						break;
					case 'E':
						s.push('E');
						break;
					default:
						return false;
				}
				break;
			case 'S':
				switch(in) {
					case 'D':
					case 'E':
					case 'G':
						break;
					case 'F':
						s.push('S');
						s.push('F');
						break;
					default:
						return false;
				}
				break;
			case 'L':
				switch(in) {
					case 'D':
					case 'E':
						s.push('Y');
						break;
					case 'G':
						s.push('G');
						break;
					default:
						return false;
				}
				break;
			default:
				return false;
		}
	}
	if(i == len)
		return true;
	else
		return false;
}
int main() {
	int cs;
	scanf("%d", &cs);
	printf("SLURPYS OUTPUT\n");
	while(cs--) {
		char str[MAXL];
		scanf("%s", str);
		if(isSlurpy(str)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	printf("END OF OUTPUT");
	return 0;
}
