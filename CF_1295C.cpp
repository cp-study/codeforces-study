#include <iostream>
#include <string>
using namespace std;

// dp[i][j]: j 문자가 i 이후부터 처음 나타나는 인덱스
int dp[200001][26];
const int INF = 987654321;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;

		// init
		for (int i = 0; i <= s.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				dp[i][j] = INF;
			}
		}

		// precalculate
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = 0; j < 26; ++j)
			{
				dp[i][j] = dp[i + 1][j];
			}

			dp[i][s[i] - 'a'] = i;
		}

		int sidx = 0;
		long long result = 1;

		for (int i = 0; i < t.size(); i++)
		{
			// 문자가 뒤에 더 이상 없음 -> 처음부터 시작
			if (sidx == s.size() || dp[sidx][t[i] - 'a'] == INF)
			{
				sidx = 0;
				++result;
			}

			// impossible
			if (dp[sidx][t[i] - 'a'] == INF && sidx == 0)
			{
				result = INF;
				break;
			}

			sidx = dp[sidx][t[i] - 'a'] + 1;
		}

		if (result >= INF)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << result << endl;
		}
	}
}
