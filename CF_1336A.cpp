#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> edges[200001];
int level[200001];
int subtree[200001];
int det[200001];

int dfs(int node, int from) {
	level[node] = level[from] + 1;
	subtree[node] = 1;

	for (int i = 0; i < edges[node].size(); ++i)
	{
		int next = edges[node][i];

		if (next == from) {
			continue;
		}

		subtree[node] += dfs(next, node);
	}

	det[node] = subtree[node] - level[node];
	return subtree[node];
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		cin >> v >> u;

		edges[v].push_back(u);
		edges[u].push_back(v);
	}

	dfs(1, 0);

	// sort by det
	vector< pair<int, int> > sorting;
	for (int i = 1; i <= n; i++)
	{
		sorting.push_back(make_pair(det[i], i));
	}

	sort(sorting.begin(), sorting.end());

	long long answer = 0;
	for (int i = 0; i < n - k; i++)
	{
		answer += sorting[n - i - 1].first;
	}

	cout << answer << endl;
}
