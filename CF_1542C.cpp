#include <iostream>
#include <climits>
using namespace std;

long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}
long long LCM(long long x, long long y) {
	return x / gcd(x, y) * y;
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;

		long long i = 1;
		long long d = 1;
		long long result = n;

		while (d <= n)
		{
			result += n / d;
			result %= 1000000007;

			i++;
			d = LCM(d, i);
		}


		cout << result << endl;
	}
}
