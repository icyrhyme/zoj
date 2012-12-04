/*
 * Date: 2010-4-24
 * Tags: Geometry, Graph Theory
 */
#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 305
#define EPS 1e-7
using namespace std;
struct circle {
	double x, y, r;
};

bool isIntersect(circle a, circle b) {
	double dist;
	dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return (dist < a.r + b.r);
}

#define PI acos(-1.0)
double getAngle(double x1, double y1, double x2, double y2) {
	double dtheta, theta1, theta2;
	theta1 = atan2(y1, x1);
	theta2 = atan2(y2, x2);
	dtheta = theta2 - theta1;
	while(dtheta > PI)
		dtheta -= PI * 2;
	while(dtheta < -PI)
		dtheta += PI * 2;
	return dtheta;

}
bool isBlocked;
bool vis[MAXN];
double dist[MAXN];
vector<pair<int, double> > g[MAXN];

void dfs(int node, double d) {
	if(vis[node]) {
		if(fabs(d - dist[node]) < EPS)
			;
		else
			isBlocked = true;
		return;
	}
	vis[node] = true;
	dist[node] = d;
	for(int i = 0; i < g[node].size() && !isBlocked; ++i) {
		double len = g[node][i].second;
		int v = g[node][i].first;
		dfs(v, d + len);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		vector<circle> vc;
		for(int i = 0; i < N; ++i) {
			circle c;
			scanf("%lf%lf%lf", &c.x, &c.y, &c.r);
			vc.push_back(c);
		}
		circle kol;
		scanf("%lf%lf%lf", &kol.x, &kol.y, &kol.r);
		for(int i = 0; i < vc.size(); ++i) {
			vc[i].x -= kol.x;
			vc[i].y -= kol.y;
			vc[i].r += kol.r;
		}
		for(int i = 0; i < N; ++i)
			g[i].clear();
		for(int i = 0; i < vc.size(); ++i) {
			for(int j = i + 1; j < vc.size(); ++j) {
				if(!isIntersect(vc[i], vc[j]))
					continue;
				double angle = getAngle(vc[i].x, vc[i].y, vc[j].x, vc[j].y);
				g[i].push_back(make_pair(j, angle));
				g[j].push_back(make_pair(i, -angle));
			}
		}
		memset(vis, false, sizeof(vis));
		isBlocked = false;
		for(int i = 0; i < N && !isBlocked; ++i) {
			if(!vis[i])
				dfs(i, 0);
		}
		if(isBlocked)
			printf("NO\n");
		else
			printf("YES\n");
		if(T > 0)
			printf("\n");
	}
}
