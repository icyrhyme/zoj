#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXL 16
#define MAXD 16
using namespace std;
class Poly {
	int data[MAXD];
	int deg;
public:
	Poly() {
		deg = 0;
		data[0] = 0;
	}
	Poly(int n) {
		deg = 0;
		data[0] = n;
	}
	void add(Poly o) {
		//print();
		//putchar('+');
		//o.print();
		//putchar('\n');
		for(int i = deg + 1; i <= o.deg; ++i)
			data[i] = 0;
		for(int i = 0; i <= o.deg; ++i)
			data[i] = data[i] + o.data[i];
		deg = max(deg, o.deg);
		while(deg > 0 && data[deg] == 0)
			--deg;
		//print();
		//putchar('\n');
	}
	void multiI(int a) {
		//print();
		//printf("*%d\n", a);
		for(int i = 0; i <= deg; ++i)
			data[i] *= a;
		while(deg > 0 && data[deg] == 0)
			--deg;
		//print();
		//putchar('\n');
	}
	void multiN() {
		//print();
		//printf("*n\n");
		++deg;
		for(int i = deg; i > 0; --i)
			data[i] = data[i - 1];
		data[0] = 0;
		while(deg > 0 && data[deg] == 0)
			--deg;
		//print();
		//putchar('\n');
	}
	void print() {
		if(deg == 0 && data[0] == 0) {
			putchar('0');
			return;
		}
		for(int i = deg; i >= 0; --i) {
			if(data[i] == 0)
				continue;
			if(i != deg)
				putchar('+');
			if(i != 0 && data[i] != 1)
				printf("%d*", data[i]);
			else if(i == 0)
				printf("%d", data[i]);
			if(i >= 2)
				printf("n^%d", i);
			else if(i == 1)
				putchar('n');
		}
	}
};
Poly op() {
	int n;
	scanf("%d", &n);
	Poly p(n);
	return p;
}
Poly loop() {
	char para[MAXL], cmd[MAXL];
	Poly p;
	scanf("%s", para);
	while(1) {
		scanf("%s", cmd);
		if(cmd[0] == 'E')
			break;
		switch(cmd[0]) {
			case 'L': p.add(loop()); break;
			case 'O': p.add(op()); break;
		}
	}
	if(isdigit(para[0])) {
		int loopn = atoi(para);
		p.multiI(loopn);
	}
	else
		p.multiN();
	return p;
}
Poly program() {
	char cmd[8];
	Poly p;
	scanf("%s", cmd);
	while(1) {
		scanf("%s", cmd);
		switch(cmd[0]) {
			case 'L': p.add(loop()); break;
			case 'O': p.add(op()); break;
			case 'E': return p; break;
		}
	}
}
int main() {
	int cs, csnum = 1;
	scanf("%d", &cs);
	while(cs--) {
		Poly p = program();
		printf("Program #%d\n", csnum);
		csnum++;
		printf("Runtime = ");
		p.print();
		putchar('\n');
		putchar('\n');
	}
	return 0;
}
