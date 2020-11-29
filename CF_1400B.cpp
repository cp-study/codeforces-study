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


int follower_take_total(ll s, ll w, ll cnts, ll cntw, ll p) {
	if (s > w)
		return follower_take_total(w, s, cntw, cnts, p);

	if (s * cnts >= p)
		return p / s;

	return cnts + min((p - s * cnts) / w, cntw);
}


int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int p, f;
		cin >> p >> f;

		ll cnts, cntw;
		cin >> cnts >> cntw;
		ll s, w;
		cin >> s >> w;
		ll best = 0;
		for (ll cs = 0; cs <= cnts; cs++)
			if (cs * s <= p) {
				ll cw = min((p - cs * s) / w, cntw);
				best = max(best, cs + cw + follower_take_total(s, w, cnts - cs, cntw - cw, f));
			}

		cout << best << endl;
	}
}