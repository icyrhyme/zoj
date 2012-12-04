#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
#define XMIN 0
#define YMIN 0
#define XMAX 20003
#define YMAX 20003
using namespace std;
struct Point2D {
	int x, y;
	Point2D() {
	}
	Point2D(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
struct RectHV {
	int xmin, ymin, xmax, ymax;
	RectHV() {}
	RectHV(int xmin, int ymin, int xmax, int ymax) {
		this->xmin = xmin;
		this->ymin = ymin;
		this->xmax = xmax;
		this->ymax = ymax;
	}
	bool in(RectHV that) {
		return (xmin >= that.xmin && ymin >= that.ymin && xmax <= that.xmax && ymax <= that.ymax);
	}
	bool intersect(RectHV that) {
		int k1 = max(xmin, that.xmin), k2 = max(ymin, that.ymin);
		int k3 = min(xmax, that.xmax), k4 = min(ymax, that.ymax);
		return (k1 <= k3 && k2 <= k4);
	}
	bool contains(Point2D p) {
		return (p.x >= xmin && p.x <= xmax && p.y >= ymin && p.y <= ymax);
	}
};
class KdTree {
	struct Node {
		Point2D p;
		int cnt;
		int sum;
		RectHV r;
		Node *left, *right;
		Node(Point2D p, int cnt, RectHV r) {
			this->p = p;
			this->cnt = cnt;
			this->sum = cnt;
			this->r = r;
			this->left = NULL;
			this->right = NULL;
		}
	};
	Node* root;
public:
	KdTree() {
		root = NULL;
	}
	void insert(Point2D p, int cnt) {
		bool isX = true;
		vector<Node*> stk;
		Node* cur;
		for(cur = root; cur != NULL; isX = !isX) {
			stk.push_back(cur);
			if(isX) {
				if(p.x < cur->p.x) {
					if(cur->left == NULL) {
						RectHV r(cur->r.xmin, cur->r.ymin, cur->p.x, cur->r.ymax);
						cur->left = new Node(p, cnt, r);
						break;
					}
					cur = cur->left;
				}
				else {
					if(cur->right == NULL) {
						RectHV r(cur->p.x, cur->r.ymin, cur->r.xmax, cur->r.ymax);
						cur->right = new Node(p, cnt, r);
						break;
					}
					cur = cur->right;
				}
			}
			else {
				if(p.y < cur->p.y) {
					if(cur->left == NULL) {
						RectHV r(cur->r.xmin, cur->r.ymin, cur->r.xmax, cur->p.y);
						cur->left = new Node(p, cnt, r);
						break;
					}
					cur = cur->left;
				}
				else {
					if(cur->right == NULL) {
						RectHV r(cur->r.xmin, cur->p.y, cur->r.xmax, cur->r.ymax);
						cur->right = new Node(p, cnt, r);
						break;
					}
					cur = cur->right;
				}
			}
		}
		if(stk.size() == 0) {
			RectHV r(XMIN, YMIN, XMAX, YMAX);
			root = new Node(p, cnt, r);
		}
		for(vector<Node*>::reverse_iterator it = stk.rbegin(); it != stk.rend(); ++it) {
			Node* nd = *it;
			nd->sum = nd->cnt + (nd->left == NULL ? 0 : nd->left->sum) + (nd->right == NULL ? 0 : nd->right->sum);
		}
	}
	int range(RectHV r) {
		if(root == NULL)
			return 0;
		stack<Node*> stk;
		stk.push(root);
		int ret = 0;
		while(!stk.empty()) {
			Node* cur = stk.top();
			stk.pop();
			if(r.contains(cur->p)) {
				//printf("point: %d %d %d\n", cur->p.x, cur->p.y, cur->cnt);
				ret += cur->cnt;
			}
			if(cur->left != NULL && cur->left->r.intersect(r))
				stk.push(cur->left);
			if(cur->right != NULL && cur->right->r.intersect(r))
				stk.push(cur->right);
		}
		return ret;
	}
};
int main() {
	KdTree t;
	while(true) {
		char op;
		op = getchar();
		if(op == 'E')
			break;
		getchar();
		while(true) {
			char tmp;
			tmp = getchar();
			ungetc(tmp, stdin);
			if(isupper(tmp))
				break;
			if(op == 'I') {
				int x, y, cnt;
				scanf("%d%d%d", &x, &y, &cnt);
				getchar();
				//printf("%d %d %d\n", x, y, cnt);
				Point2D p(x, y);
				t.insert(p, cnt);
			}
			else if(op == 'Q') {
				int xmin, xmax, ymin, ymax;
				scanf("%d%d%d%d", &xmin, &xmax, &ymin, &ymax);
				getchar();
				//printf("%d %d %d %d\n", xmin, xmax, ymin, ymax);
				RectHV r(xmin, ymin, xmax, ymax);
				int res = t.range(r);
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
