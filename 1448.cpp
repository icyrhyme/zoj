#include <iostream>
#include <vector>
#include <set>
#define MAXN 128
using namespace std;
struct NFA_Edge {
	bool isInvert;
	bool isAny;
	char begin, end;
	int target;
};
vector<NFA_Edge> NFA[MAXN];
int final;
int uid;
int pt;
char pattern[MAXN];
char getch() {
	switch(pattern[pt]) {
		case '\\':
			++pt;
		default:
			return pattern[pt++];
	}
}
void getRange(NFA_Edge* e) {
	++pt;
	e->isInvert = false;
	e->isAny = false;
	if(pattern[pt] == '^') {
		e->isInvert = true;
		++pt;
	}
	e->begin = getch();
	++pt;
	e->end = getch();
	++pt;
}
bool makeEdge(NFA_Edge* e) {
	switch(pattern[pt]) {
		case '.': 
			e->isAny = true;
			e->isInvert = false;
			++pt;
			break;
		case '[':
			getRange(e);
			break;
		case '\0':
			return false;
		case '\\':
		default:
			char ch = getch();
			e->begin = ch;
			e->end = ch;
			e->isAny = false;
			e->isInvert = false;
			break;
	}
	return true;
}
void makeNode(NFA_Edge *e) {

	switch(pattern[pt]) {
		case '*':
			e->target = uid;
			NFA[uid].push_back(*e);
			while(pattern[pt] == '*' || pattern[pt] == '+')
				++pt;
			break;
		case '+':
			e->target = uid + 1;
			NFA[uid].push_back(*e);
			NFA[uid + 1].push_back(*e);
			while(pattern[pt] == '*' || pattern[pt] == '+')
				++pt;
			++uid;
			break;
		default:
			e->target = uid + 1;
			NFA[uid].push_back(*e);
			++uid;
			break;
	}
}
void construct() {
	pt = 0;
	uid = 0;
	NFA_Edge e;
	while(makeEdge(&e)) {
		makeNode(&e);
	}
}
bool canTrans(NFA_Edge e, char ch) {
	if(e.isAny)
		return true;
	bool flag;
	if(ch >= e.begin && ch <= e.end)
		flag = true;
	else
		flag = false;
	if(e.isInvert)
		return !flag;
	else
		return flag;
}
set<int> trans(set<int> sset, char ch) {
	set<int> ret;
	set<int>::iterator it;
	for(it = sset.begin(); it != sset.end(); ++it) {
		int state = *it;
		//printf("%d ", state);
		for(int i = 0; i < NFA[state].size(); ++i) {
			if(canTrans(NFA[state][i], ch) && ret.find(NFA[state][i].target) == ret.end()) {
				ret.insert(NFA[state][i].target);
			}
		}
	}
	//printf("\n");
	return ret;
}
inline bool isAccepted(set<int> sset) {
	if(sset.find(uid - 1) != sset.end())
		return true;
	else
		return false;
}
pair<int, int> match(char text[MAXN]) {
	for(int i = 0; text[i] != '\0'; ++i) {
		set<int> sset, newsset;
		sset.insert(0);
		int lastj = -1;
		int j;
		//printf("i = %d\n", i);
		for(j = i; text[j] != '\0'; ++j) {
			set<int>::iterator it;
			newsset = trans(sset, text[j]);
//			printf("from: ");
//			for(it = sset.begin(); it != sset.end(); ++it){
//				printf("%d ", *it);
//			}
//			printf("\n");
//			printf("to: ");
//			for(it = newsset.begin(); it != newsset.end(); ++it){
//				printf("%d ", *it);
//			}
//			printf("\n");
			if(isAccepted(newsset)) {
				lastj = j;
			}
			if(newsset.empty()) {
				if(lastj != -1)
					return make_pair(i, lastj + 1);
				else
					break;
			}
			sset = newsset;
		}
		if(lastj != -1)
			return make_pair(i, lastj + 1);
	}
	return make_pair(-1, -1);
}
int main() {
	char text[MAXN];
	while(1) {
		gets(pattern);
		if(strcmp(pattern, "end") == 0) {
			break;
		}
		gets(text);
		if(strcmp(pattern, "") == 0) {
			printf("%s\n", text);
			continue;
		}
		construct();
		++uid;
//		for(int i = 0; i < uid; ++i) {
//			for(int j = 0; j < NFA[i].size(); ++j) {
//				printf("%d->%d\n", i, NFA[i][j].target);
//				printf("%d %d\n", (int)NFA[i][j].isInvert, (int)NFA[i][j].isAny);
//				printf("%c-%c\n", NFA[i][j].begin, NFA[i][j].end);
//			}
//		}
		pair<int, int> substr = match(text);
//		printf("%d %d\n", substr.first, substr.second);
		for(int i = 0; text[i] != '\0'; ++i) {
			if(i == substr.first)
				putchar('(');
			putchar(text[i]);
			if(i == substr.second - 1)
				putchar(')');
		}
		putchar('\n');
		for(int i = 0; i < uid; ++i)
			NFA[i].clear();
	}
}
