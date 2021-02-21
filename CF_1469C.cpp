#include <iostream>
#include <algorithm>
using namespace std;

int h[200000];

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;

		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
		}

		bool ok = true;
		int minRange = h[0], maxRange = h[0];

		for (int i = 1; i < n; i++)
		{
			minRange = max(min(minRange - (k - 1), minRange), h[i]);
			maxRange = min(max(maxRange + k - 1, maxRange), h[i] + k - 1);


			// check
			if (minRange > maxRange)
			{
				ok = false;
			}
		}

		if (h[n - 1] < minRange)
		{
			ok = false;
		}

		cout << (ok ? "YES" : "NO") << endl;
	}
}
