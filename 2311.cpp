#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
map<string, int> mp;
void init() {
	mp["zero"] = 0;
	mp["one"] = 1;
	mp["two"] = 2;
	mp["three"] = 3;
	mp["four"] = 4;
	mp["five"] = 5;
	mp["six"] = 6;
	mp["seven"] = 7;
	mp["eight"] = 8;
	mp["nine"] = 9;
	mp["ten"] = 10;
	mp["eleven"] = 11;
	mp["twelve"] = 12;
	mp["thirteen"] = 13;
	mp["fourteen"] = 14;
	mp["fifteen"] = 15;
	mp["sixteen"] = 16;
	mp["seventeen"] = 17;
	mp["eighteen"] = 18;
	mp["nineteen"] = 19;
	mp["twenty"] = 20;
	mp["thirty"] = 30;
	mp["forty"] = 40;
	mp["fifty"] = 50;
	mp["sixty"] = 60;
	mp["seventy"] = 70;
	mp["eighty"] = 80;
	mp["ninety"] = 90;
	mp["hundred"] = 100;
	mp["thousand"] = 1000;
	mp["million"] = 1000000;
}
int trans(string word) {
	return mp[word];
}
int main() {
	init();
	string line;
	while(getline(cin, line)) {
		if(line == "")
			break;
		istringstream iss(line);
		string word;
		int val = 0, pval = 0, flag = 1;
		while(iss >> word) {
			if(word == "negative")
				flag = -1;
			else if(word == "thousand" || word == "million") {
				val += pval * trans(word);
				pval = 0;
			}
			else if(word == "hundred") {
				pval *= trans(word);
			}
			else {
				pval += trans(word);
			}
		}
		cout << flag * (val + pval) << endl;
	}
	return 0;
}
