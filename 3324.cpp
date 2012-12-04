#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAXN 50005
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)^1)
#define M(x,y) (((x)+(y))>>1)
struct SegTreeNode {
	int le, ri, cover, cnt;
	bool lcover, rcover;
} st[3 * MAXN];
void init(int le, int ri, int x = 1)
{
	st[x].le = le;
	st[x].ri = ri;
	st[x].cover = 0;
	st[x].lcover = st[x].rcover = false;
	st[x].cnt = 1;
	if(le == ri)
		return;
	init(le, M(le, ri), L(x));
	init(M(le, ri) + 1, ri, R(x));
}
int query()
{
	return st[1].cnt;
}
void update(int le, int ri, int delta, int x = 1)
{
	if(st[x].le == le && st[x].ri == ri)
	{
		st[x].cover += delta;
		if(st[x].cover != 0)
		{
			st[x].lcover = st[x].rcover = true;
			st[x].cnt = 0;
		}
		else if(st[x].le == st[x].ri)
		{
			st[x].lcover = st[x].rcover = false;
			st[x].cnt = 1;
		}
		else
		{
			st[x].lcover = st[L(x)].lcover;
			st[x].rcover = st[R(x)].rcover;
			st[x].cnt = st[L(x)].cnt + st[R(x)].cnt;
			if(!st[L(x)].rcover && !st[R(x)].lcover)
				st[x].cnt -= 1;
		}
		return;
	}
	int m = M(st[x].le, st[x].ri);
	if(ri <= m)
		update(le, ri, delta, L(x));
	else if(le > m)
		update(le, ri, delta, R(x));
	else
	{
		update(le, m, delta, L(x));
		update(m + 1, ri, delta, R(x));
	}
	if(st[x].cover == 0)
	{
		st[x].lcover = st[L(x)].lcover;
		st[x].rcover = st[R(x)].rcover;
		st[x].cnt = st[L(x)].cnt + st[R(x)].cnt;
		if(!st[L(x)].rcover && !st[R(x)].lcover)
			st[x].cnt -= 1;
	}
}
int main()
{
	int T, cs = 1;
	scanf("%d", &T);
	while(cs <= T)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		char cmd[4];
		int le, ri;
		vector<pair<char, pair<int, int> > > input;
		map<int, int> mm;
		for(int i = 0; i < m; ++i)
		{
			scanf("%s%d%d", cmd, &le, &ri);
			input.push_back(make_pair(cmd[0], make_pair(le, ri)));
			if(mm.find(le) == mm.end())
				mm[le] = 0;
			if(mm.find(ri) == mm.end())
				mm[ri] = 0;
		}
		int pre = -1;
		vector<int> temp;
		for(map<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
		{
			if(it->first != pre + 1)
				temp.push_back(it->first - 1);
			pre = it->first;
		}
		if(pre != n - 1)
			temp.push_back(n - 1);
		for(int i = 0; i < temp.size(); ++i)
			mm[temp[i]] = 0;
		int id = 0;
		for(map<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
		{
			it->second = id;
			++id;
		}
		init(0, id - 1);
		//printf("%d\n", id);
		printf("Case #%d:\n", cs);
		for(int i = 0; i < input.size(); ++i)
		{
			char c = input[i].first;
			le = input[i].second.first, ri = input[i].second.second;
			le = mm[le], ri = mm[ri];
			if(c == 'p')
				update(le, ri, 1);
			else if(c == 'r')
				update(le, ri, -1);
			printf("%d\n", query());
		}
		++cs;
	}
	return 0;
}
