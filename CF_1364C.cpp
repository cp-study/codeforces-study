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
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> A;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	vector<int> B(A.size(), -1);
	set<int> used;
	priority_queue<int> pq;

	for (int i = 0; i < A.back(); i++) {
		pq.push(i);
	}
	for (int i = 1; i < B.size(); i++) {
		if (A[i - 1] != A[i]) {
			B[i] = A[i - 1];
			used.insert(A[i - 1]);
		}
	}

	bool isPossible = true;
	int extra = A.back() + 1;
	for (int i = B.size() - 1; i >= 1; i--) {

		while (!pq.empty()) {
			if (used.find(pq.top()) != used.end()) {
				pq.pop();
			}
			else break;
		}

		if (B[i] != -1) continue;

		if (!pq.empty() && pq.top() > A[i]) {
			B[i] = pq.top();
			pq.pop();
		}
		else {
			B[i] = extra++;
		}
	}

	priority_queue<int> pq2;
	while (!pq.empty()) {
		if (used.find(pq.top()) == used.end()) {
			pq2.push(pq.top());
			pq.pop();
		}
		else {
			pq.pop();
		}
	}
	if (A[0] >= 2) {
		isPossible = false;
	}
	else {
		if (A[0] == 0) {
			if (!pq2.empty() && pq2.size() == 1 && pq2.top() != 0) {
				B[0] = pq2.top();
			}
			else if (pq2.empty()) {
				B[0] = extra;
			}
			else {
				isPossible = false;
			}
		}
		else if (A[0] == 1) {
			if (!pq2.empty() && pq2.top() == 0) {
				B[0] = 0;
			}
			else {
				isPossible = false;
			}
		}
	}

	if (isPossible) {
		for (int i = 0; i < B.size(); i++) {
			cout << B[i] << " ";
		}
	}
	else {
		cout << -1;
	}
}