#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		string s, c;

		cin >> s >> c;

		string sorted = s;
		sort(sorted.begin(), sorted.end());

		int minindex = 0;

		// AAMNOZ AZAMON APPLE
		// AA
		// AZ
		while (minindex < s.length() && sorted[minindex] == s[minindex])
		{
			++minindex;
		}

		if (minindex >= s.length())
		{
			if (s >= c)
			{
				cout << "---" << endl;
			}
			else
			{
				cout << s << endl;
			}
		}
		else
		{
			char tofind = sorted[minindex];

			for (int i = s.length() - 1; i > minindex; i--)
			{
				if (tofind == s[i])
				{
					s[i] = s[minindex];
					s[minindex] = tofind;
					break;
				}
			}

			if (s >= c)
			{
				cout << "---" << endl;
			}
			else
			{
				cout << s << endl;
			}
		}
	}
}
