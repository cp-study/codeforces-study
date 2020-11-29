#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int FR_TURN = 0;
const int MY_TURN = 1;

int n;
int a[200000];

int dp[2][200001];

int solve(int turn, int boss) {
	if (boss >= n)
	{
		return 0;
	}
	if (dp[turn][boss] != -1)
	{
		return dp[turn][boss];
	}

	int ret = 987654321;

	if (turn == FR_TURN)
	{
		ret = min(ret, solve(1 - turn, boss + 1) + a[boss]);
		ret = min(ret, solve(1 - turn, boss + 2) + a[boss] + a[boss + 1]);
	}
	else
	{
		ret = min(ret, solve(1 - turn, boss + 1));
		ret = min(ret, solve(1 - turn, boss + 2));
	}

	return dp[turn][boss] = ret;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(FR_TURN, 0) << endl;
	}
}
