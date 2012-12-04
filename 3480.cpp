#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
class classInfo {
public:
	classInfo() {
		super = "";
	}
	classInfo(string super) {
		this->super = super;
	}
	string super;
	set<string> methods;
};
map<string, classInfo> tbl;
void gaoClass() {
	string name;
	cin >> name;
	int pos = name.find(':');
	if(pos == -1) {
		if(tbl.find(name) != tbl.end()) {
			cout << "oops!" << endl;
			return;
		}
		classInfo ci;
		tbl[name] = ci;
		cout << "class " << name << endl;
	}
	else {
		string sname = name.substr(pos + 1, name.size() - pos - 1);
		name = name.substr(0, pos);
		if(tbl.find(name) != tbl.end() || tbl.find(sname) == tbl.end()) {
			cout << "oops!" << endl;
			return;
		}
		classInfo ci(sname);
		tbl[name] = ci;
		cout << "class " << name << ":" << sname << endl;
	}
}
void gaoDef() {
	string name;
	cin >> name;
	int pos = name.find('.');
	string cname = name.substr(0, pos);
	string mname = name.substr(pos + 1, name.size() - pos - 1);
	if(tbl.find(cname) == tbl.end())
		cout << "oops!" << endl;
	else if(tbl[cname].methods.find(mname) != tbl[cname].methods.end()) {
		cout << "redef " << cname << "." << mname << endl;
	}
	else {
		tbl[cname].methods.insert(mname);
		cout << "def " << cname << "." << mname << endl;
	}
}
void gaoUndef() {
	string name;
	cin >> name;
	int pos = name.find('.');
	string cname = name.substr(0, pos);
	string mname = name.substr(pos + 1, name.size() - pos - 1);
	if(tbl.find(cname) == tbl.end() || tbl[cname].methods.find(mname) == tbl[cname].methods.end())
		cout << "oops!" << endl;
	else {
		tbl[cname].methods.erase(mname);
		cout << "undef " << cname << "." << mname << endl;
	}
}
void gaoCall() {
	string name;
	cin >> name;
	int pos = name.find('.');
	string cname = name.substr(0, pos);
	string mname = name.substr(pos + 1, name.size() - pos - 1);
	for(; tbl.find(cname) != tbl.end(); cname = tbl[cname].super) {
		if(tbl[cname].methods.find(mname) != tbl[cname].methods.end()) {
			cout << "invoke " << cname << "." << mname << endl;
			return;
		}
	}
	cout << "oops!" << endl;
}
void gao() {
	string cmd;
	cin >> cmd;
	while(cin >> cmd && cmd != "end") {
		if(cmd == "class")
			gaoClass();
		else if(cmd == "def")
			gaoDef();
		else if(cmd == "undef")
			gaoUndef();
		else
			gaoCall();
	}
	cout << endl;
}
int main() {
	int cas;
	cin >> cas;
	while(cas--) {
		tbl.clear();
		gao();
	}
	return 0;
}
