#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <cstdlib>
#include <list>
#include <iomanip>
#define ll long long
using namespace std;

int calc(const string& s, char c) {
	if (s.size() == 1) {
		return s[0] == c ? 0:1;
	}
	int mid = s.size() / 2;

	int cntLeft = calc(string(s.begin(), s.begin() + mid), c + 1)
		+ s.size() / 2 - count(s.begin() + mid, s.end(), c);

	int cntRight = calc(string(s.begin() + mid, s.end()), c + 1) 
		+ s.size() / 2 - count(s.begin(), s.begin() + mid, c);

	return min(cntLeft, cntRight);
}

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		string s;
		cin >> n >> s;
		cout << calc(s, 'a') << endl;
	}
}