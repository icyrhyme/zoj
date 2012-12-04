#include <iostream>
#define SNUM 4
#define VNUM 13
using namespace std;
class PokerHand {
	char cards[5][4];
	int scnt[8], vcnt[16];
	void _getSuit(int i) {
		switch(cards[i][1]) {
			case 'C': return 0; break;
			case 'D': return 1; break;
			case 'H': return 2; break;
			case 'S': return 3; break;
		}
	}
	void _getValue(int i) {
		if(cards[i][0] >= '2' && cards[i][0] <= '9') {
			return cards[i][0] - '2';
		}
		else {
			switch(cards[i][0]) {
				case 'T': return 8; break;
				case 'J': return 9; break;
				case 'Q': return 10; break;
				case 'K': return 11; break;
				case 'A': return 12; break;
			}
		}
	}
	void _analyze() {
		fill(scnt, scnt + SNUM, 0);
		fill(vcnt, vcnt + VNUM, 0);
		for(int i = 0; i < 5; ++i) {
			scnt[getSuit(i)]++;
			vcnt[getValue(i)]++;
		}
	}
	bool _isPair(int *val) {
		bool flag2 = false;
		for(int i = 0; i < VNUM; ++i)
			if(vcnt[i] >= 2) {
				flag = true;
				*val
			}
	}
	bool _isTwoPairs(int *val) {
		int cnt2 = 0;
		for(int i = 0; i < VNUM; ++i)
			if(vcnt[i] == 2)
				++cnt2;
		if(cnt2 != 2) {
			return false;
		}
		vector<int> v;
		for(int i = VNUM - 1; i >= 0; --i) {
			if(vcnt[i] == 2) {
				v.push_back(i);
			}
		}
		for(int i = 0; i < VNUM: ++i) {
			if(vcnt[i] == 1)
				v.push_back(i);
		}
		*val = 0;
		for(int i = 0; i < v.size(); ++i)
			*val = *val * VNUM + v[i];
		return true;
	}
	bool _isThreeOfAKind(int *val) {
		bool flag3 = false;
		int idx;
		for(int i = 0; i < VNUM; ++i)
			if(vcnt[i] >= 3) {
				flag3 = true;
				idx = i;
			}
		if(flag3) {
			*val = idx;
			return true;
		}
		else 
			return false;
	}
	bool _isStraight(int* val) {
		int idx = INF;
		for(int i = 0; i < VNUM; ++i) {
			if(vcnt[i] != 0) {
				idx = i;
				if(vcnt[i] != 1)
					return false;
			}
		}
		for(int i = 0; i < 5; ++i) {
			if(vcnt[idx + i] != 1)
				return false;
		}
		*val = idx + 4;
		return true;
	}
	bool _isFlush(int* val) {
		for(int i = 0; i < SNUM; ++i) {
			if(scnt[i] != 0 && scnt[i] != 5)
				return false;
		}
		for(int i = 0; i < 5; ++i)
			maxIdx = max(maxIdx, getValue(i));
		*val = maxIdx;
		return true;
	}
	bool _isFullHouse(int* val) {
		bool flag2 = false, flag3 = false;
		int idx3;
		for(int i = 1; i < VNUM; ++i) {
			if(vcnt[i] == 2) {
				flag2 = true;
			}
			if(vcnt[i] == 3) {
				flag3 = true;
				idx3 = i;
			}
		}
		if(flag2 && flag3) {
			*val = idx3;
			return true;
		}
		else
			return false;
	}
	bool _isFourOfAKind(int* val) {
		int maxIdx = 0;
		for(int i = 1; i < VNUM; ++i) {
			if(vcnt[i] > vcnt[maxIdx])
				maxIdx = i;
		}
		if(vcnt[maxIdx] < 4)
			return false;
		else {
			*val = maxIdx;
			return true;
		}
	}
	bool _isStraightFlush(int* val) {
		for(int i = 0; i < SNUM; ++i) {
			if(scnt[i] != 0 && scnt[i] != 5)
				return false;
		}
		int idx = INF;
		for(int i = 0; i < VNUM; ++i) {
			if(vcnt[i] != 0) {
				idx = i;
				if(vcnt[i] != 1)
					return false;
			}
		}
		for(int i = 0; i < 5; ++i) {
			if(vcnt[idx + i] != 1)
				return false;
		}
		*val = idx + 4;
		return true;
	}
	pair<int, int> _getType() {
		int val;
		_analyze();
		if(_isStraightFlush(&val)) {
			return make_pair(8, val);
		}
		else if(_isFourOfAKind(&val)) {
			return make_pair(7, val);
		}
		else if(_isFullHouse(&val)) {
			return make_pair(6, val);
		}
		else if(_isFlush(&val)) {
			return make_pair(5, val);
		}
		else if(_isStraight(&val)) {
			return make_pair(4, val);
		}
		else if(_isThreeOfAKind(&val)) {
			return make_pair(3, val);
		}
		else if(_isTwoPairs(&val)) {
			return make_pair(2, val);
		}
		else if(_isPair(&val)) {
			return make_pair(1, val);
		}
		else if(_isHighCard(&val)) {
			return make_pair(0, val);
		}
	}
public:
	bool input() {
		for(int i = 0; i < 5; ++i) {
			int res = scanf("%s", cards[i]);
			if(res == EOF)
				return false;
		}
		return true;
	}
	bool operator<(const PokerHand& o) const {
		pair<int, int> p = _getType();
		pair<int, int> q = o._getType();
		return (p < q);
	}
};
int main() {
}
