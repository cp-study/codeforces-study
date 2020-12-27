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
		int n, m;
		cin >> n >> m;

		vector<string> strs;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			strs.push_back(str);
		}

		bool isFound = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 26; j++) {
				string strTemp = strs[0];
				strTemp[i] = 'a' + j;
				int maxDiff = 0;
				for (int k = 0; k < n; k++) {
					int diffCnt = 0;
					for (int l = 0; l < m; l++) {
						if (strTemp[l] != strs[k][l]) {
							diffCnt++;
						}
					}
					maxDiff = max(maxDiff, diffCnt);
				}
				if (maxDiff <= 1) {
					cout << strTemp << endl;
					isFound = true;
					break;
				}
			}
			if (isFound) break;
		}
		if (!isFound) {
			cout << -1 << endl;
		}
	}
}