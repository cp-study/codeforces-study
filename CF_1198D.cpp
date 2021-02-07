#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[200001];
int s[200000], p[200000], x[200000];
bool changed[200001];
int maxX;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int q;
	cin >> q;
	for (int i = q - 1; i >= 0; i--)
	{
		cin >> s[i];
		if (s[i] == 1)
		{
			cin >> p[i] >> x[i];
		}
		else
		{
			cin >> x[i];
		}
	}

	// last to first
	for (int i = 0; i < q; i++)
	{
		// 1 p x
		if (s[i] == 1)
		{
			int index = p[i];
			int value = x[i];

			if (changed[index])
			{
				continue;
			}

			changed[index] = true;
			arr[index] = max(maxX, value);
		}
		// 2 x
		else
		{
			int value = x[i];

			maxX = max(maxX, value);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (changed[i])
		{
			cout << arr[i] << ' ';
		}
		else
		{
			cout << max(maxX, arr[i]) << ' ';
		}
	}
	cout << endl;
}
