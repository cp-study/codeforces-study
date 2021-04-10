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
#define INF INT_MAX
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MOD 1000000007
using namespace std;

void dfs(int curr, vector<vector<int>>& tree, map<int,
	pair<int, int>>& mp, vector<int>& order) {
	order.push_back(curr);
	mp[curr].first = order.size()-1;

	for (int i = 0; i < tree[curr].size(); i++) {
		dfs(tree[curr][i], tree, mp, order);
	}
	mp[curr].second = order.size() - 1;
}

int main() {
	int n, q;
	cin >> n >> q;

	vector<vector<int>> tree(n + 1);

	for (int i = 2; i <= n; i++) {
		int v;
		cin >> v;
		tree[v].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		sort(tree[i].begin(), tree[i].end());
	}

	map<int,pair<int,int>> mp;
	vector<int> order;

	dfs(1, tree, mp, order);

	for (int i = 0; i < q; i++) {
		int u, k;
		cin >> u >> k;
		k--;

		int idx = mp[u].first + k;
		if (idx > mp[u].second) {
			cout << "-1" << endl;
		}
		else {
			cout << order[idx] << endl;
		}
	}
}