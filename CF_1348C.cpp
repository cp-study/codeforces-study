#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string str;

string solve() {
	// sort
	sort(str.begin(), str.end());

	// 앞에 k 개가 같지 않으면 k 번째 문제가 답
	if (str[0] != str[k - 1])
	{
		string ret = "";
		ret += str[k - 1];
		return ret;
	}

	// k 뒤부터 같지 않으면 한곳에 몰아주는게 좋음
	if (str[k] != str[n - 1])
	{
		string ret = "";
		for (int i = k - 1; i < n; i++)
		{
			ret += str[i];
		}
		return ret;
	}

	// 남은게 모두 같으면 한개씩 몰아줌
	else
	{
		string ret = "";
		ret += str[0];
		for (int i = 0; i < (n - 1) / k; i++)
		{
			ret += str[n - 1];
		}
		return ret;
	}
	return "";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k >> str;


		cout << solve() << endl;
	}
}
