#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	vector<int> vd, pos;
	for(int i = 100000; i >= 1; --i)
	{
		int dcnt = 0, tmp = i;
		while(tmp)
		{
			++dcnt;
			vd.push_back(tmp % 10);
			tmp /= 10;
		}
		pos.push_back(dcnt);
	}
	reverse(vd.begin(), vd.end());
	reverse(pos.begin(), pos.end());
	for(int i = 1; i < pos.size(); ++i)
		pos[i] = pos[i - 1] + pos[i];
	while(scanf("%d", &n) != EOF)
	{
		int a = 1, b = 2;
		for(int i = 0; (pos[n - 1] - a) / b; ++i)
		{
			if(i % 2 == 0)
				a += b;
			b *= 2;
		}
		printf("%d\n", vd[a - 1]);
	}
	return 0;
}
