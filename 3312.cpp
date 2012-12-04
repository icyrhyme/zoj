#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ATO 0
#define PLU 1
#define MIN 2
#define MUL 3
#define DIV 4
#define abs(x) ((x)>0?(x):(-x))
using namespace std;
class frac {
	long long a, b;
	static long long _gcd(long long a, long long b) {
		return (a == 0 ? b : _gcd(b % a, a));
	}
	static long long _lcm(long long a, long long b) {
		return (a / _gcd(a, b) * b);
	}
public:
	frac(long long aa = 0, long long bb = 1) {
		int temp = _gcd(abs(aa), abs(bb));
		if(aa * bb > 0) {
			a = abs(aa) / temp;
			b = abs(bb) / temp;
		}
		else {
			a = -abs(aa) / temp;
			b = abs(bb) / temp;
		}
	}
	const frac operator+(const frac& o) const {
		int newa, newb;
		newa = a * o.b / _gcd(b, o.b) + o.a * b / _gcd(b, o.b);
		newb = _lcm(b, o.b);
		return frac(newa, newb);
	}
	const frac operator-(const frac& o) const {
		frac temp(-o.a, o.b);
		return *this + temp;
	}
	const frac operator*(const frac& o) const {
		int newa, newb, temp = _gcd(abs(a * o.a), b * o.b);
		newa = a * o.a / temp;
		newb = b * o.b / temp;
		return frac(newa, newb);
	}
	const frac operator/(const frac& o) const {
		frac temp(o.b, o.a);
		return *this * temp;
	}
	bool operator<(const frac& o) const {
		return a * o.b < o.a * b;
	}
	bool isInteger() {
		if(b == 1)
			return true;
		else
			return false;
	}
	bool isZero() {
		if(a == 0)
			return true;
		else
			return false;
	}
	long long toInteger() {
		return a;
	}
};
struct expr {
	int op;
	frac le, ri;
	int led, rid;
	expr() {
	}
	expr(int ld, frac l, int rd, frac r, int o) {
		led = ld;
		le = l;
		rid = rd;
		ri = r;
		op = o;
	}
};
map<frac, expr> vp[9];
void print_expr(int idx, frac f) {
	expr e = vp[idx][f];
	if(e.op == ATO)
		printf("%lld", f.toInteger());
	else {
		printf("(");
		print_expr(e.led, e.le);
		switch(e.op) {
			case PLU: printf("+"); break;
			case MIN: printf("-"); break;
			case MUL: printf("*"); break;
			case DIV: printf("/"); break;
		}
		print_expr(e.rid, e.ri);
		printf(")");
	}
}
long long all8[9] = {0, 8, 88, 888, 8888, 88888, 888888, 8888888, 88888888};
int main() {
	for(int i = 1; i <= 8; ++i) {
		frac temp(all8[i], 1);
		expr e(0, temp, 0, temp, ATO);
		vp[i][temp] = e;
		for(int j = 1; j < i; ++j)
			for(map<frac, expr>::iterator it1 = vp[j].begin(); it1 != vp[j].end(); ++it1)
				for(map<frac, expr>::iterator it2 = vp[i - j].begin(); it2  != vp[i - j].end(); ++it2)
					for(int op = 1; op <= 4; ++op) {
						frac s = it1->first;
						frac t = it2->first;
						switch(op) {
							case PLU: temp = s + t; break;
							case MIN: temp = s - t; break;
							case MUL: temp = s * t; break;
							case DIV:
								  if(!t.isZero())
								  	temp = s / t;
								  break;
						}
						if(vp[i].find(temp) != vp[i].end())
							continue;
						expr newe(j, s, i - j, t, op);
						vp[i][temp] = newe;
					}
	}
	long long n;
	while(scanf("%lld", &n) != EOF) {
		frac temp(n, 1);
		if(vp[8].find(temp) != vp[8].end()) {
			print_expr(8, temp);
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
