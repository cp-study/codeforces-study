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

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		string s;
		cin >> n >> s;
		s.push_back('X'); // dummy
		int cnt = 1;

		int dead = 0;
		int total = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1]) {
				cnt++;
			}
			else {
				if (cnt == 1) {
					dead++;
				} else if (cnt > 2) {
					dead = max(dead - (cnt - 2), 0);
				}
				total++;
				cnt = 1;
			}
		}
		cout << "total: " << total << endl;
		cout << "dead: " << dead << endl;
		cout << "ans: " << total - (dead/2) << endl;
	}
}