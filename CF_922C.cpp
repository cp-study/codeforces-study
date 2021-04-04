#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	long long n, k;

	cin >> n >> k;

	set<long long> visited;

	string ans = "Yes";

	for (int i = 1; i <= k; i++)
	{
		long long mod = n % i;

		cout << mod << endl;

		if (visited.find(mod) != visited.end())
		{
			ans = "No";
			break;
		}

		visited.insert(mod);
	}

	cout << ans << endl;
}
