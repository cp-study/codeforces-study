#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int music[400000];
int prefix[400001];
int suffix[400001];

map<int, int> cnt;

long long n, i;

int main() {


	cin >> n >> i;

	for (int i = 0; i < n; i++)
	{
		cin >> music[i];

		cnt[music[i]]++;
	}

	int k = min((8 * i) / n, 30LL);
	int range = pow(2, k);

	if (cnt.size() <= range)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> v;
	for (auto i = cnt.begin(); i != cnt.end(); i++)
	{
		v.push_back(i->second);
	}

	// prefix sum, suffix sum
	for (int i = 0; i < v.size(); i++)
	{
		prefix[i + 1] = prefix[i] + v[i];
	}
	for (int i = 0; i < v.size(); i++)
	{
		suffix[i + 1] = suffix[i] + v[v.size() - 1 - i];
	}

	int result = INT_MAX;
	int req = cnt.size() - range;
	for (int i = 0; i <= req; i++)
	{
		int sum = prefix[i] + suffix[req - i];

		result = min(result, sum);
	}

	cout << result << endl;
}
