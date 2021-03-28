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
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define PI 3.141592653589793238462643383279502884L 
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		// Get last idx to Change
		int idxToChange = -1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] > v[i]) {
				idxToChange = i - 1;
			}
		}

		ll ans = 0;
		// Replace until last to Change
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > x  && i <= idxToChange) {
				int temp = x;
				x = v[i];
				v[i] = temp;
				ans++;
			}
		}

		// Check if sorted
		bool isSorted = true;
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] > v[i]) {
				isSorted = false;
				break;
			}
		}

		if (isSorted) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}