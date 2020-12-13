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
	int n, m;

	cin >> n >> m;

	vector<int> a;
	vector<int> b;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}

	int MAX_LIMIT = pow(2, 9) - 1;
	int minim = INT_MAX;
	for (int i = 0; i <= MAX_LIMIT; i++) {
		int curr = i;
		bool isPossible = false;
		for (int j = 0; j < a.size(); j++) {
			isPossible = false;
			for (int k = 0; k < b.size(); k++) {
				if (((a[j] & b[k]) | curr) == curr) {
					isPossible = true;
					break;
				}
			}
			if (!isPossible) break;
		}
		if (isPossible) {
			minim = min(minim, curr);
		}
	}
	cout << minim << endl;
}