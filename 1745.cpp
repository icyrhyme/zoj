#include <iostream>
#include <sstream>
using namespace std;
int main() {
	string line;
	bool first = true;
	while(getline(cin, line)) {
		istringstream iss(line);
		int pos, dist, p, prep = 0, newdist;
		iss >> pos;
		dist = abs(pos);
		if(pos == 5280)
			break;
		if(first)
			first = false;
		else
			cout << endl;
		while(iss >> p) {
			cout << "Moving from " << prep << " to " << p << ": ";
			newdist = abs(p - pos);
			if(p == pos)
				cout << "found it!" << endl;
			else if(newdist == dist)
				cout << "same." << endl;
			else if(newdist > dist)
				cout << "colder." << endl;
			else
				cout << "warmer." << endl;
			dist = newdist;
			prep = p;
		}
	}
	return 0;
}
