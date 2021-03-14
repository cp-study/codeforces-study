#include <iostream>
#include <cstring>
using namespace std;

int arr[(unsigned int)1e5];
int n;
int dp[(unsigned int)1e5][6];

int solve(int idx, int k, int z) {
	// 끝
	if (k == 0)
	{
		return 0;
	}
	if (dp[idx][z] != 0)
	{
		return dp[idx][z];
	}

	int ret = arr[idx];

	// 왼쪽
	if (z > 0 && idx > 0)
	{
		ret = max(ret, arr[idx] + solve(idx - 1, k - 1, z - 1));
	}

	// 오른쪽
	if (idx + 1 < n)
	{
		ret = max(ret, arr[idx] + solve(idx + 1, k - 1, z));
	}

	return  dp[idx][z] = ret;
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int k, z;

		cin >> n >> k >> z;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		memset(dp, 0, sizeof(dp));

		cout << solve(0, k + 1, z) << endl;
	}
}
