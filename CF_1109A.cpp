#include <iostream>
using namespace std;

int arr[300001];
int prefix[300001];
int cnt[2][(1 << 20) + 1];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		prefix[i] = prefix[i - 1] ^ arr[i];
	}

	cnt[0][0] = 1;
	// prefix 같은 것들
	for (int i = 1; i <= n; i++)
	{
		cnt[i % 2][prefix[i]] ++;
	}

	long long result = 0;
	for (int i = 0; i < (1 << 20) + 1; i++)
	{
		long long c = cnt[0][i];
		result += c * (c - 1) / 2;

		c = cnt[1][i];
		result += c * (c - 1) / 2;
	}
	cout << result << endl;
}
