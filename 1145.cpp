#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#define MAXL 128
#define MAXN 32
using namespace std;
char expr[MAXL], ops[MAXL] = "+-*", ans[MAXL];
int pos[MAXN], sz, val;
int calc(int a, int ch, int b) {
	switch(ch) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
	}
}
int calc_expr(int p) {
	int num[MAXN], ni = 0, oi = 0;
	char op[MAXN];
	for(int i = 0; expr[i];) {
		if(isdigit(expr[i])) {
			num[ni++] = atoi(expr + i);
			while(isdigit(expr[i])) {
				++i;
			}
		}
		else if(expr[i] == '(')
			op[oi++] = expr[i++];
		else if(expr[i] == ')') {
			while(oi > 0 && op[oi - 1] != '(') {
				int b = num[--ni];
				int a = num[--ni];
				num[ni++] = calc(a, op[--oi], b);
			}
			--oi;
			++i;
		}
		else {
			while(oi > 0 && op[oi - 1] != '(') {
				int b = num[--ni];
				int a = num[--ni];
				num[ni++] = calc(a, op[--oi], b);
			}
			op[oi++] = expr[i++];
		}
	}
	while(oi > 0) {
		int b = num[--ni];
		int a = num[--ni];
		num[ni++] = calc(a, op[--oi], b);
	}
	return num[0];
}
void gen_expr(int idx) {
	if(idx == sz) {
		if(calc_expr(0) == val)
			strcpy(ans, expr);
		return;
	}
	for(int i = 0; i < 3; ++i) {
		expr[pos[idx]] = ops[i];
		gen_expr(idx + 1);
	}
}
int main() {
	int cs = 1;
	while(scanf("%d", &val) != EOF && val) {
		scanf("%*[ =]");
		char ch, oexpr[MAXL], pre = '(';
		scanf("%[^\n]", oexpr);
		int ei = 0, oei = 0;
		sz = 0;
		while(oexpr[oei] != '\0') {
			if(isdigit(oexpr[oei])) {
				if(pre == ')' || pre == '0') {
					expr[ei++] = ' ';
					pos[sz++] = ei - 1;
				}
				expr[ei++] = oexpr[oei++];
				while(isdigit(oexpr[oei])) {
					expr[ei++] = oexpr[oei++];
				}
				pre = '0';
			}
			else if(oexpr[oei] == '(') {
				if(pre == ')' || pre == '0') {
					expr[ei++] = ' ';
					pos[sz++] = ei - 1;
				}
				expr[ei++] = oexpr[oei++];
				pre = '(';
			}
			else if(oexpr[oei] == ')') {
				expr[ei++] = oexpr[oei++];
				pre = ')';
			}
			else
				oei++;
		}
		expr[ei] = '\0';
		strcpy(ans, "Impossible");
		gen_expr(0);
		printf("Equation #%d:\n", cs);
		++cs;
		if(ans[0] != 'I')
			printf("%d=%s\n\n", val, ans);
		else
			printf("%s\n\n", ans);
		//printf("%s\n", expr);
	}
	return 0;
}
