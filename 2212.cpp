#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXLEN 10
using namespace std;
struct result
{
	int t, qn, tdiff;
	bool operator>(const result& o)const
	{
		if(t != o.t)
			return t > o.t;
		else
			return qn > o.qn;
	}
};
int main()
{
	char cmd[MAXLEN];
	while(scanf("%s", cmd) != EOF)
	{
		int k;
		result tmp;
		priority_queue<result, vector<result>, greater<result> > pq;
		scanf("%d%d", &tmp.qn, &tmp.t);
		tmp.tdiff = tmp.t;
		pq.push(tmp);
		while(1)
		{
			scanf("%s", cmd);
			if(cmd[0] == '#')
				break;
			scanf("%d%d", &tmp.qn, &tmp.t);
			tmp.tdiff = tmp.t;
			pq.push(tmp);
		}
		scanf("%d", &k);
		while(k--)
		{
			result r = pq.top();
			pq.pop();
			printf("%d\n", r.qn);
			r.t += r.tdiff;
			pq.push(r);
		}
	}
	return 0;
}
