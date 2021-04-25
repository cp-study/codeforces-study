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
#define MOD 1000000007
using namespace std;

ll getSum(int a, int b) {
	int k = b - a + 1;
	return k * (2 * a + (k - 1)) / 2;
}
int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		int k = r - l + 1;
		ll minim = getSum(1, k);
		ll maxim = getSum(n-k+1, n);
		
		if (s >= minim && s <= maxim) {
			vector<int> v;
			for (int i = 1; i <= k; i++) {
				v.push_back(i);
			}
			deque<int> rest;
			for (int i = k + 1; i <= n; i++) {
				rest.push_back(i);
			}
			int cnt = 0;
			int idx = k - 1;
			bool isFound = false;
			if (minim == s) isFound = true;
			while (idx >= 0) {
				if (isFound) break;
				
				for (int i = 0; i < rest.size(); i++) {
					cnt++;
					if (minim + cnt == s) {
						int tmp = v[idx];
						v[idx] = rest[i];
						rest[i] = tmp;
						isFound = true;
						break;
					}
				}
				if (isFound) break;
				else {
					int tmp = v[idx];
					v[idx] = rest.back();
					rest.pop_back();
					rest.push_front(tmp);
				}
				idx--;
			}
			int vIdx=0;
			int restIdx=0;
			for (int i = 1; i <= n; i++) {
				if (l <= i && r >= i) {
					cout << v[vIdx++] << " ";
				}
				else {
					cout << rest[restIdx++] << " ";
				}
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}