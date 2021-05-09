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
#define MOD 1000000007
#define MAX 1000005
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		map<int,int> mp;
		deque<int> A(N+1);
		vector<int> prefixXor(N+1);
		int numCnt = 0;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			prefixXor[i] = prefixXor[i - 1] ^ A[i];
		}
		bool isPossible = !prefixXor[N];

		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j < N; j++) {
				isPossible |= (prefixXor[i] == (prefixXor[j] ^ prefixXor[i])
					&& prefixXor[i] == (prefixXor[N] ^ prefixXor[j]));
			}
		}

		if (isPossible) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}