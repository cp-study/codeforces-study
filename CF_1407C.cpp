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
	int N;
	cin >> N;

	int maxim = 0;
	int maxim_idx = 1;
	vector<int> v(N+1, 0);
	for (int i = 2; i <= N; i++) {
		int k1, k2;
		cout << "? " << maxim_idx << " "<<i << endl;
		cout.flush();
		cin >> k1;
		cout << "? " << i << " " << maxim_idx << endl;
		cout.flush();
		cin >> k2;
		if (k1 < k2) {
			v[i] = k2;
		}
		else {
			v[maxim_idx] = k1;
			maxim_idx = i;
		}
	}
	v[maxim_idx] = N;

	cout << "! ";
	for (int i = 1; i <= N; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout.flush();
}