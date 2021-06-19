#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int n;
vector<int> edges[100000];
pair<int, int> lrs[100001];
long long dp[100000][2];

long long getSum(int node, int prevnode, bool leftSelected) {
	long long ret = 0;

	if (dp[node][leftSelected ? 0 : 1] != -1)
	{
		return dp[node][leftSelected ? 0 : 1];
	}

	int prevLrs;
	if (leftSelected)
	{
		prevLrs = lrs[node].first;
	}
	else
	{
		prevLrs = lrs[node].second;
	}

	for (int i = 0; i < edges[node].size(); i++)
	{
		int next = edges[node][i];

		if (next == prevnode)
		{
			continue;
		}

		// 왼쪽
		long long left = getSum(next, node, true) + abs(prevLrs - lrs[next].first);

		// 오른쪽
		long long right = getSum(next, node, false) + abs(prevLrs - lrs[next].second);

		ret += max(left, right);
	}

	return dp[node][leftSelected ? 0 : 1] = ret;
}

long long solve() {
	// 맨처음은 무시하도록?
	lrs[n].first = 0;
	lrs[n].second = 0;

	return max(getSum(0, n, true), getSum(0, n, false));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n; i++)
		{
			cin >> lrs[i].first >> lrs[i].second;
		}

		// init edges
		for (int i = 0; i < n; i++)
		{
			edges[i].clear();
		}

		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;

			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		cout << solve() << endl;
	}
}
