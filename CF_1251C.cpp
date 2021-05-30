#include <iostream>
#include <string>
#include <deque>
using namespace std;

void go() {
	string num;
	cin >> num;

	deque<char> even;
	deque<char> odd;

	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] % 2 == 0)
		{
			even.push_back(num[i]);
		}
		else
		{
			odd.push_back(num[i]);
		}
	}

	string result = "";
	while (!even.empty() && !odd.empty())
	{
		// 홀수를 넣는다.
		if (even.front() > odd.front())
		{
			result += odd.front();
			odd.pop_front();
		}
		else
		{
			result += even.front();
			even.pop_front();
		}
	}

	// 나머지 처리
	while (!even.empty())
	{
		result += even.front();
		even.pop_front();
	}
	while (!odd.empty())
	{
		result += odd.front();
		odd.pop_front();
	}

	cout << result << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		go();
	}
}
