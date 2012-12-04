#include <iostream>
#define MAXN 512
#define MAXM 1024 
#define MAX (MAXN + 1) * (MAXM + 1)
#define INF 0x7fffffff
using namespace std;
int U[MAX], D[MAX], L[MAX], R[MAX], cid[MAX], rid[MAX], ccnt[MAXM];
int bound, res[MAXN], rec[MAXN];
int addlr(int cur, int prv, int nxt) {
	L[cur] = prv;
	R[prv] = cur;
	L[nxt] = cur;
	R[cur] = nxt;
}
int addud(int cur, int prv, int nxt) {
	U[cur] = prv;
	D[prv] = cur;
	U[nxt] = cur;
	D[cur] = nxt;
}
void cover(int c) {
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	for(int i = D[c]; i != c; i = D[i])
		for(int j = R[i]; j != i; j = R[j]) {
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			--ccnt[cid[j]];
		}
}
void uncover(int c) {
	for(int i = U[c]; i != c; i = U[i])
		for(int j = L[i]; j != i; j = L[j]) {
			++ccnt[cid[j]];
			U[D[j]] = j;
			D[U[j]] = j;
		}
	L[R[c]] = c;
	R[L[c]] = c;
}
void search(int k) {
	if(k >= bound)
		return;
	if(R[0] == 0) {
		bound = k;
		//for(int i = 0; i < k; ++i)
		//	res[i] = rec[i];
		return;
	}
	int c, s = INF;
	for(int i = R[0]; i != 0; i = R[i])
		if(ccnt[i] < s) {
			c = i;
			s = ccnt[i];
		}
	if(s == INF)
		return;
	cover(c);
	for(int i = D[c]; i != c; i = D[i]) {
		//rec[k] = rid[i];
		for(int j = R[i]; j != i; j = R[j])
			cover(cid[j]);
		search(k + 1);
		for(int j = L[i]; j != i; j = L[j])
			uncover(cid[j]);
	}
	uncover(c);
}
int exactCover(bool matr[][MAXM], int rn, int cn) {
	memset(ccnt, 0, sizeof(ccnt));
	addlr(0, 0, 0);
	addud(0, 0, 0);
	int rfirst = 0;
	for(int i = 1; i <= cn; ++i) {
		addlr(i, i - 1, rfirst);
		addud(i, i, i);
	}
	int cprev[MAXM], cnext[MAXM];
	for(int i = 0; i < cn; ++i)
		cprev[i] = i + 1;
	int id = cn + 1;
	for(int i = 0; i < rn; ++i) {
		rfirst = -1;
		for(int j = 0; j < cn; ++j) {
			if(!matr[i][j])
				continue;
			cid[id] = j + 1;
			rid[id] = i;
			if(rfirst == -1) {
				addlr(id, id, id);
				rfirst = id;
			}
			else {
				addlr(id, id - 1, rfirst);
			}
			addud(id, cprev[j], j + 1);
			cprev[j] = id;
			++id;
			++ccnt[j + 1];
		}
	}
	bound = INF;
	search(0);
	return bound;
}
#define UNPACK(m, j) make_pair((j)/(m), (j)%(m))
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		bool matr[MAXN][MAXM];
		int n, m, p;
		scanf("%d%d%d", &n, &m, &p);
		for(int i = 0; i < p; ++i) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			--x2, --y2;
			for(int j = 0; j < m * n; ++j) {
				pair<int, int> pt = UNPACK(m, j);
				if(pt.first >= x1 && pt.first <= x2 && pt.second >= y1 && pt.second <= y2)
					matr[i][j] = true;
				else
					matr[i][j] = false;
			}
		}
		exactCover(matr, p, m * n);
		if(bound == INF)
			printf("-1\n");
		else
			printf("%d\n", bound);
	}
	return 0;
}
