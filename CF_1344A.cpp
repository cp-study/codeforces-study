#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
int a[200000];
bool visited[200000];

string solve() {
	for (int i = 0; i < n; i++)
	{
		int r = ((i + a[i]) % n + n) % n;

		if (visited[r])
		{
			return "NO";
		}
		visited[r] = true;
	}

	return "YES";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		memset(visited, false, sizeof(visited));

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		cout << solve() << endl;
	}
}
