#include <iostream>
#include <string>
#include <stack>
#include <climits>
using namespace std;

int main() {
	long long l;
	bool overflowed = false;
	cin >> l;

	stack<long long> forStack;
	stack<long long> addStack;

	addStack.push(0);

	// clear buffer
	string command;
	getline(cin, command);

	while (l--)
	{
		getline(cin, command);

		// for
		if (command[0] == 'f')
		{
			long long forcount = 0;

			for (long long i = 4; i < command.size(); i++)
			{
				forcount *= 10;
				forcount += command[i] - '0';
			}

			forStack.push(forcount);
			addStack.push(0);
		}
		// end
		else if (command[0] == 'e')
		{
			long long forCount = forStack.top();
			forStack.pop();

			long long add = addStack.top();
			addStack.pop();
			long long prev = addStack.top();
			addStack.pop();

			prev += add * forCount;

			if (prev > UINT32_MAX)
			{
				overflowed = true;
			}

			addStack.push(prev);
		}
		// add
		else
		{
			long long prev = addStack.top();
			addStack.pop();

			if (prev + 1 > UINT32_MAX)
			{
				overflowed = true;
			}

			addStack.push(prev + 1);
		}
	}

	if (overflowed)
	{
		cout << "OVERFLOW!!!" << endl;
	}
	else
	{
		cout << addStack.top() << endl;
	}
}
