#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int l = 1, r = n;
	int second;

	while (l < r)
	{
		cout << "? " << l << ' ' << r << endl;
		cout.flush();

		cin >> second;

		if (r - l <= 1)
		{
			break;
		}

		int mid = (r + l) / 2;

		if (mid < second)
		{
			int right;

			cout << "? " << mid << ' ' << r << endl;
			cout.flush();
			cin >> right;

			// 최대값은 오른쪽에 있음.
			if (right == second)
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		else
		{
			int left;

			cout << "? " << l << ' ' << mid << endl;
			cout.flush();
			cin >> left;

			// 최대값은 왼쪽에 있음.
			if (left == second)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
	}

	if (l == second)
	{
		cout << "! " << r << endl;
	}
	else
	{
		cout << "! " << l << endl;
	}
	cout.flush();
}
