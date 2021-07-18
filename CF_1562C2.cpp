#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <cstdlib>
#include <list>
#include <iomanip>
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF LLONG_MAX
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<ll> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	ll curr = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] >= 0) {
			curr += v[i];
			cnt++;
		}
		else {
			if (curr + v[i] >= 0) {
				curr += v[i];
				pq.push(v[i]);
				cnt++;
			}
			else {
				if (!pq.empty() && pq.top() < v[i]) {
					curr -= pq.top();
					pq.pop();
					curr += v[i];
					pq.push(v[i]);
				}
			}
		}
	}
	cout << cnt << endl;
}