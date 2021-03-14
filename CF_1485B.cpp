#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#define ll long long int
#define ull unsigned long long int
#define ld long double
using namespace std;

int main() {
	ll n, q, k;

	cin >> n >> q >> k;
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;

		ll ans = k + (v[r] - v[l] + 1) - 2 * (r - l + 1);

		cout << ans << endl;
	}
}