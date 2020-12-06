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
		cin >> n;

		vector<pair<int, int>> v(100001);

		int maxOccur = 0;
		for (int i = 0; i < n; i++) {
			int num; 
			cin >> num;
			v[num] = { v[num].first+1, num };
			maxOccur = max(maxOccur, v[num].first);
		}

		sort(v.begin(), v.end(), greater<>());

		int ans = 0;
		int numOfMaxOccur = 0;
		for (int i=0;i<v.size();i++){
			if (v[i].first == maxOccur) {
				ans++;
				n -= v[i].first;
			}
		}
		ans -= 1;
		
		if (maxOccur != 1) {
			ans += n / (maxOccur - 1);
		}
		cout << ans << endl;
	}
}