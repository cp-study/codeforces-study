#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int arr[100001];
int prefixSum[100001];

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string str;
		cin >> n >> str;

		for (int i = 0; i < n; i++)
		{
			arr[i] = str[i] - '0';

			if (i - 1 < 0)
			{
				prefixSum[i] = arr[i];
			}
			else
			{
				prefixSum[i] = prefixSum[i - 1] + arr[i];
			}
		}

		// good => prefix[r] - prefix[l] == r - l
		// prefix[r] - r == prefix[l] - l

		map<int, long long> cnt;
		cnt[0] = 1;
		for (int i = 0; i < n; i++)
		{
			int x = prefixSum[i] - (i+1);
			cnt[x]++;
		}

		long long result = 0;

		// nC2
		for (std::map<int, long long>::iterator it = cnt.begin(); it != cnt.end(); ++it)
		{
			result += (it->second) * ((it->second) - 1) / 2;
		}

		cout << result << endl;
	}
}
