#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[200000];
int level[200000];

int solve() {
	int last = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			++last;
		}

		level[i] = level[last] + 1;
	}

	return level[n - 1];
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			level[i] = 0;
		}

		cout << solve() << endl;
	}
}
