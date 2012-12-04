#include <cstdio>
#define MAXL 16
using namespace std;
char sx[12][MAXL] = {
	"Rabbit",
	"Tiger",
	"Ox",
	"Rat",
	"Pig",
	"Dog",
	"Rooster",
	"Monkey",
	"Ram",
	"Horse",
	"Snake",
	"Dragon"
};
int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		int age;
		scanf("%d", &age);
		puts(sx[(age - 1) % 12]);
	}
	return 0;
}
