#include <iostream>
#include <algorithm>
using namespace std;

int towers[200000];
int heightCount[200001];

int main() {
	int n, k;
	cin >> n >> k;

	int minheight = 200000;
	int maxHeight = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> towers[i];

		minheight = min(minheight, towers[i]);
		maxHeight = max(maxHeight, towers[i]);
		heightCount[towers[i]]++;
	}

	// 3 1 2 2 4
	/* 4:1
	* 3:2
	* 2:4
	* 1:5
	*/
	for (int i = 200000; i > 0; i--)
	{
		heightCount[i - 1] += heightCount[i];
	}

	long long ans = 0;
	int sum = 0;
	for (int i = 200000; i > minheight; i--)
	{
		sum += heightCount[i];

		if (sum > k)
		{
			sum -= heightCount[i];
			ans++;
			sum = 0;
			i++;
		}
	}

	if (maxHeight != minheight)
	{
		++ans;
	}

	cout << ans << endl;
}
