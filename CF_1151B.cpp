#include <iostream>
using namespace std;

int a[500][500];
int picked[500];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result ^= a[i][0];
	}

	int checkIdx = 0;
	while (result == 0 && checkIdx < n)
	{
		// pick next
		int next = picked[checkIdx] + 1;

		if (next >= m)
		{
			next = 0;
			checkIdx++;
			continue;
		}

		result ^= a[checkIdx][next - 1] ^ a[checkIdx][next];
		picked[checkIdx] = next;
	}

	if (result != 0)
	{
		cout << "TAK" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << picked[i] + 1 << ' ';
		}
		cout << endl;
	}
	else
	{
		cout << "NIE" << endl;
	}
}
