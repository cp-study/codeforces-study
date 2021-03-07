#include<iostream>
#include<algorithm>
using namespace std;

long long a[100000];
long long b[100000];
long long c[100000];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		long long answer = 0;
		long long prev = 0;

		for (int i = 1; i < n; i++)
		{
			long long current = abs(a[i] - b[i]) + c[i] + 1;

			// 같지 않으면 이전 사이클에 붙이는거 확인.
			if (a[i] != b[i])
			{
				current = max(current, prev - abs(a[i] - b[i]) + c[i] + 1);
			}

			answer = max(answer, current);
			prev = current;
		}

		cout << answer << endl;
	}
}
