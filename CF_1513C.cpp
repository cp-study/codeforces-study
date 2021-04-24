#include <iostream>
#include <cstring>
using namespace std;

int dp[200001][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < 10; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i <= 200000; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = dp[i - 1][(j + 1) % 10];
		}
		dp[i][9] += dp[i - 1][1];
		dp[i][9] %= 1000000007;
	}


	while (t--)
	{
		int n, m;
		cin >> n >> m;

		long long res = 0;
		while (n != 0)
		{
			res += dp[m][n % 10];
			res %= 1000000007;

			n /= 10;
		}
		cout << res << endl;
	}
}
