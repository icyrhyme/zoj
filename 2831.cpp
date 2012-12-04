#include <iostream>
using namespace std;
char digit[][10] = {
"  XXXX  ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
"  XXXX  ",
"   XX   ",
" XXXX   ",
"   XX   ",
"   XX   ",
"   XX   ",
"   XX   ",
"   XX   ",
" XXXXXX ",
"  XXXX  ",
" XX  XX ",
" XX  XX ",
"     XX ",
"    XX  ",
"   XX   ",
"  XX    ",
" XXXXXX ",
"  XXXX  ",
" X   XX ",
"     XX ",
"   XXX  ",
"     XX ",
"     XX ",
" X   XX ",
"  XXXX  ",
"    XX  ",
"   XXX  ",
"   XXX  ",
"  X XX  ",
" X  XX  ",
" XXXXXX ",
"    XX  ",
"  XXXXX ",
"  XXXXX ",
"  XX    ",
"  XXXX  ",
"  X  XX ",
"     XX ",
"     XX ",
" X   XX ",
"  XXXX  ",
"   XXXX ",
"  XX    ",
" XX     ",
" XXXXX  ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
"  XXXX  ",
" XXXXXX ",
" X   XX ",
"     XX ",
"    XX  ",
"    XX  ",
"    XX  ",
"   XX   ",
"   XX   ",
"  XXXX  ",
" XX  XX ",
" XX  XX ",
"  XXXX  ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
"  XXXX  ",
"  XXXX  ",
" XX  XX ",
" XX  XX ",
" XX  XX ",
"  XXXXX ",
"     XX ",
"    XX  ",
" XXXX   ",
"        ",
"   X    ",
"   X    ",
"   X    ",
"XXXXXXX ",
"   X    ",
"   X    ",
"   X    ",
};
#define MAXH 8
#define MAXL 10000
char buf[MAXH][MAXL];
bool isMatch(int idx, int c) {
	int len = strlen(digit[8 * c]);
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < len; ++j)
			if(digit[8 * c + i][j] != buf[i][idx + j])
				return false;
	return true;
}
char parse(int idx) {
	for(int i = 0; i < 11; ++i) {
		if(isMatch(idx, i)) {
			if(i == 10)
				return '+';
			else
				return i + '0';
		}
	}
}
#include <vector>
void output(int num) {
	vector<int> v;
	do {
		v.push_back(num % 10);
		num /= 10;
	}
	while(num > 0);
	for(int i = 0; i < 8; ++i) {
		for(int j = v.size() - 1; j >= 0; --j) {
			putchar(' ');
			printf("%s", digit[v[j] * 8 + i]);
			putchar(' ');
		}
		putchar('\n');
	}
}
int main() {
	for(int i = 0; i < 11; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(i != 10) {
				for(int k = 1; digit[i * 8 + j][k]; ++k)
					digit[i * 8 + j][k - 1] = digit[i * 8 + j][k];
				int len = strlen(digit[i * 8 + j]);
				digit[i * 8 + j][len - 2] = '\0';
			}
			else {
				int len = strlen(digit[i * 8 + j]);
				digit[i * 8 + j][len - 1] = '\0';
			}
		}
	}
	int N;
	scanf("%d", &N);
	while(N--) {
		gets(buf[0]);
		int ml = -1;
		for(int i = 0; i < MAXH; ++i) {
			gets(buf[i]);
		ml = max(ml, (int)strlen(buf[i]));
		}
		for(int i = 0; i < MAXH; ++i) {
			for(int j = strlen(buf[i]); j < ml; ++j)
				buf[i][j] = ' ';
			buf[i][ml] = '\0';
		}
		int a = 0, b = 0;
		bool isB = false;
		for(int j = 0; j < ml; ++j) {
			int i;
			for(i = 0; i < 8; ++i)
				if(buf[i][j] != ' ')
					break;
			if(i >= 8)
				continue;
			char sym = parse(j);
			if(isdigit(sym)) {
				if(isB)
					b = b * 10 + sym - '0';
				else
					a = a * 10 + sym - '0';
			}
			else
				isB = true;
			j += 6;
		}
		output(a + b);
		if(N != 0)
			putchar('\n');
	}
	return 0;
}
