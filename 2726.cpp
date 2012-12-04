#include <iostream>
#define INF 1000000000
using namespace std;
int s2m(char ms[])
{
	static char month[][16] = {"January", "February", "March", "April",
		"May", "June", "July", "August", "September",
		"October", "November", "December"};
	for(int i = 0; i < 12; ++i)
		if(strcmp(month[i], ms) == 0)
			return (i + 1);
}
char cons[][16] = {"Ar", "Ta", "Ge", "Ca", "Le", "Vi", "Li", "Sc",
	"Sa", "Ca", "Aq", "Pi"};
int sm[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2};
int em[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3};
int sd[] = {20, 21, 22, 23, 23, 23, 23, 23, 23, 23, 22, 21};
int ed[] = {20, 21, 22, 22, 22, 22, 22, 22, 22, 21, 20, 19};
int getCons(int month, int day) {
	for(int i = 0; i < 12; ++i) {
		if(month == sm[i] && day >= sd[i] ||
		   month == em[i] && day <= ed[i])
			return i;
	}
}
#define MAXN 16
int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}
void print_blank(int cnt) {
	while(cnt--)
		putchar(' ');
}
int main()
{
	int N;
	while(scanf("%d", &N) != EOF) {
		if(N == 0)
			break;
		char ms[16];
		int cnt[MAXN];
		int month, day;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < N; ++i) {
			scanf("%s%d", ms, &day);
			month = s2m(ms);
			int res = getCons(month, day);
			++cnt[res];
		}
		bool first = true;
		int g;
		for(int i = 0; i < 12; ++i)
			if(cnt[i] != 0) {
				if(first) {
					g = cnt[i];
					first = false;
				}
				else
					g = gcd(g, cnt[i]);
			}
		//for(int i = 0; i < 12; ++i)
		//	printf("%d\n", cnt[i] / g);
		int maxh = -1;
		for(int i = 0; i < 12; ++i)
			maxh = max(maxh, cnt[i] / g);
		int bcnt;
		for(int i = maxh + 1; i > 0; --i) {
			bcnt = 0;
			for(int j = 0; j < 12; ++j)
			{
				if(j == 0)
					bcnt += 1;
				else
					bcnt += 2;
				if(cnt[j] / g + 1 == i && cnt[j] != 0)
				{
					print_blank(bcnt);
					bcnt = 0;
					printf("%2d", cnt[j]);
				}
				else if(cnt[j] / g >= i)
				{
					print_blank(bcnt);
					bcnt = 0;
					printf("XX");
				}
				else
					bcnt += 2;
			}
			printf("\n");
		}
		printf("-");
		for(int j = 0; j < 12; ++j)
		{
			printf("--");
			if(j == 11)
				printf("-\n");
			else
				printf("--");
		}
		printf(" ");
		for(int j = 0; j < 12; ++j)
		{
			printf("%s", cons[j]);
			if(j == 11)
				printf("\n");
			else
				printf("  ");
		}
		printf("\n");
	}
	return 0;
}
