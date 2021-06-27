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
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		vector<int> P(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
		}

		int idxBackSorted = N+1;
		int pNum = N;
		for (int i = N; i >= 1; i--) {
			if (P[i] != pNum) break;
			else {
				pNum--;
				idxBackSorted = i;
			}
		}

		ld ans = 0;
		for (int i = 0; i < M; i++) {
			int r;
			ld p;
			cin >> r >> p;
			if (r < idxBackSorted - 1) continue;
			ans += (1 - ans) * p;
		}

		if (idxBackSorted == 1) {
			cout << 1 << endl;
		}
		else {
			cout << ans << endl;
		}
		
	}
}