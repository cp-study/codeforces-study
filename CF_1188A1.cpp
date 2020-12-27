#include <iostream>
using namespace std;

int degree[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		degree[u]++;
		degree[v]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}
