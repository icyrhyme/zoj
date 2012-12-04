#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ATO 0
#define PLU 1
#define MIN 2
#define MUL 3
#define DIV 4
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
		return _lcm(b, o.b) / b * a < _lcm(b, o.b) / o.b * o.a;
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
	frac res;
	pair<int, int> le, ri;
	expr() {
		frac t;
		res = t;
		le = make_pair(0, 0);
		ri = make_pair(0, 0);
		op = ATO;
	}
	expr(frac result, pair<int, int> l, pair<int, int> r, int o) {
		res = result;
		le = l;
		ri = r;
		op = o;
	}
};
vector<expr> vp[9];
void print_expr(int i, int j) {
	expr e = vp[i][j];
	if(e.op == ATO)
		printf("%lld", e.res.toInteger());
	else {
		printf("(");
		print_expr(e.le.first, e.le.second);
		switch(e.op) {
			case PLU: printf("+"); break;
			case MIN: printf("-"); break;
			case MUL: printf("*"); break;
			case DIV: printf("/"); break;
		}
		print_expr(e.ri.first, e.ri.second);
		printf(")");
	}
}
long long all8[9] = {0, 8, 88, 888, 8888, 88888, 888888, 8888888, 88888888};
int main() {
	for(int i = 1; i <= 8; ++i) {
		set<frac> s;
		frac temp(all8[i], 1);
		expr e(temp, make_pair(0, 0), make_pair(0, 0), ATO);
		vp[i].push_back(e);
		s.insert(temp);
		for(int j = 1; j < i; ++j)
			for(int a = 0; a < (int)vp[j].size(); ++a)
				for(int b = 0; b < (int)vp[i - j].size(); ++b)
					for(int op = 1; op <= 4; ++op) {
						switch(op) {
							case PLU: temp = vp[j][a].res + vp[i - j][b].res; break;
							case MIN: temp = vp[j][a].res - vp[i - j][b].res; break;
							case MUL: temp = vp[j][a].res * vp[i - j][b].res; break;
							case DIV:
								  if(!vp[i - j][b].res.isZero())
								  	temp = vp[j][a].res / vp[i - j][b].res;
								  break;
						}
						if(s.find(temp) != s.end())
							continue;
						s.insert(temp);
						expr newe(temp, make_pair(j, a), make_pair(i - j, b), op);
						vp[i].push_back(newe);
					}
	}
	map<int, int> mp;
	for(int i = 0; i < (int)vp[8].size(); ++i) {
		if(vp[8][i].res.isInteger()) {
			mp[vp[8][i].res.toInteger()] = i;
		}
	}
	long long n;
	while(scanf("%lld", &n) != EOF) {
		if(mp.find(n) != mp.end())
			print_expr(8, mp[n]);
		else
			printf("Impossible\n");
	}
	return 0;
}
