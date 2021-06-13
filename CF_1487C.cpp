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
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		if (N % 2 == 1) {
			for (int i = 2; i <= N; i++) {
				for (int j = i; j <= N; j++) {
					if (j-i+1 <= (N-1) / 2) {
						cout << 1 << " ";
					}
					else {
						cout << -1 << " ";
					}
				}
			}
		}
		else {
			for (int i = 2; i <= N; i++) {
				for (int j = i; j <= N; j++) {
					if (j-i+1 < N / 2) {
						cout << 1 << " ";
					}
					else if (j-i+1== N / 2) {
						cout << 0 << " ";
					}
					else {
						cout << -1 << " ";
					}
				}
			}
		}
		cout << endl;
	}
}