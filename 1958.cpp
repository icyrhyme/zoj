#include <cstdio>
#include <cstring>
#define MAXL 260
using namespace std;
void infix_to_postfix(char expr[]) {
	char res[MAXL], stk[MAXL];
	int rpos = 0, spos = 0;
	for(int i = 0; expr[i]; ++i) {
		switch(expr[i]) {
			case '{':
				while(expr[i] != '}')
					res[rpos++] = expr[i++];
				res[rpos++] = expr[i];
				break;
			case '+':
			case '-':
				while(spos > 0 && stk[spos - 1] != '(')
					res[rpos++] = stk[--spos];
				stk[spos++] = expr[i];
				break;
			case '*':
			case '(':
				stk[spos++] = expr[i];
				break;
			case ')':
				while(stk[spos - 1] != '(')
					res[rpos++] = stk[--spos];
				--spos;
		}
	}
	while(spos > 0) {
		res[rpos++] = stk[--spos];
	}
	res[rpos] = '\0';
	strcpy(expr, res);
}
int op(int a, int b, char ch) {
	switch(ch) {
		case '+': return a | b;
		case '-': return a & (~b);
		case '*': return a & b;
	}
}
int calc(char expr[]) {
	int stk[MAXL], spos = 0, msk;
	int a, b, res;
	for(int i = 0; expr[i]; ++i) {
		switch(expr[i]) {
			case '{':
				++i;
				msk = 0;
				while(expr[i] != '}')
					msk |= (1 << (expr[i++] - 'A'));
				stk[spos++] = msk;
				break;
			case '+':
			case '-':
			case '*':
				b = stk[--spos];
				a = stk[--spos];
				res = op(a, b, expr[i]);
				stk[spos++] = res;
				break;
		}
	}
	return stk[0];
}
void printSet(int res) {
	putchar('{');
	for(int i = 'A'; i <= 'Z'; ++i, res >>= 1) {
		if(res & 1) {
			putchar(i);
		}
	}
	putchar('}');
	putchar('\n');
}
int main() {
	char expr[MAXL];
	while(scanf("%s", expr) != EOF) {
		infix_to_postfix(expr);
		//printf("%s\n", expr);
		int res = calc(expr);
		printSet(res);
	}
	return 0;
}
