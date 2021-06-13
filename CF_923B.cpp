#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long V[100001], T[100001], prefix[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> V[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> T[i];
		prefix[i] = prefix[i - 1] + T[i];
	}

	priority_queue<long long, vector<long long>, greater<long long> > pq;

	for (int i = 1; i <= n; i++)
	{
		long long answer = 0;

		pq.push(V[i] + prefix[i - 1]);

		// 없어짐
		while (!pq.empty() && pq.top() <= prefix[i])
		{
			answer += pq.top() - prefix[i - 1];
			pq.pop();
		}

		// 안 없어진 나머지
		answer += pq.size() * T[i];

		cout << answer << ' ';
	}
	cout << endl;
}
