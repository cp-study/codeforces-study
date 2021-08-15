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
#define ull unsigned long long
#define ld long double
#define MOD 998244353
#define INF LLONG_MAX
using namespace std;

int N;

bool tryPossible(vector <pair<int, int>>& v, vector<int>& ans,
	int first, int second) {
	ans.clear();
	ans.push_back(1);
	ans.push_back(first);
	ans.push_back(second);
	bool isPossible = true;
	for (int i = 1; i < N; i++) {
		if (ans[(i + 1) % N] == v[ans[i]].first) {
			if (ans.size() < N) ans.push_back(v[ans[i]].second);
		}
		else if (ans[(i + 1) % N] == v[ans[i]].second) {
			if (ans.size() < N) ans.push_back(v[ans[i]].first);
		}
		else {
			isPossible = false;
			break;
		}
	}
	return isPossible;
}

int main()
{
	cin >> N;
	
	vector <pair<int,int>> v(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	vector<int> ans;
	
	if (!tryPossible(v, ans, v[1].first, v[1].second)) {
		tryPossible(v, ans, v[1].second, v[1].first);
	}


	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}