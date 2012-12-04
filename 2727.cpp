#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 90
#define MAXN 128
using namespace std;
struct book {
	char name[MAXL];
	int year;
	int price;
};
struct CmpFunctor {
	char ce[MAXL];
	bool operator()(book a, book b) {
		switch(ce[0]) {
			case 'N':
				if(strcmp(a.name, b.name) != 0)
					return (strcmp(a.name, b.name) < 0);
				break;
			case 'Y':
				if(a.year != b.year)
					return a.year < b.year;
				break;
			case 'P':
				if(a.price != b.price)
					return a.price < b.price;
				break;
		}
		if(strcmp(a.name, b.name) != 0)
			return (strcmp(a.name, b.name) < 0);
		else if(a.year != b.year)
			return a.year < b.year;
		else
			return a.price < b.price;
	}
};
int main() {
	int n, csnum = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0)
			break;
		book books[MAXN];
		for(int i = 0; i < n; ++i) {
			scanf("%s", books[i].name);
			scanf("%d", &books[i].year);
			scanf("%d", &books[i].price);
		}
		CmpFunctor cmp;
		scanf("%s", cmp.ce);
		sort(books, books + n, cmp);
		if(csnum != 1)
			putchar('\n');
		for(int i = 0; i < n; ++i) {
			printf("%s %d %d\n", books[i].name, books[i].year, books[i].price);
		}
		csnum++;
	}
	return 0;
}
