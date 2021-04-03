#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#define INF INT_MAX
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MOD 1000000007
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		vector<int> a(N);
		vector<int> b(N);
		vector<int> c(M);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}
		int needPaintCnt = 0;
		map<int, int> stayPaints;
		map<int, queue<int>> needPaint;
		for (int i = 0; i < N; i++) {
			if (a[i] != b[i]) {
				needPaint[b[i]].push(i);
				needPaintCnt++;
			}
			else {
				stayPaints.insert({ a[i], i });
			}
		}

		for (int i = 0; i < M; i++) {
			cin >> c[i];
		}

		int wrongPaintCnt = 0;
		vector<int> ans;
		for (int i = 0; i < c.size(); i++) {
			if (needPaint.find(c[i]) == needPaint.end()
				|| needPaint[c[i]].size() == 0) {
				if (stayPaints.find(c[i]) == stayPaints.end())
					wrongPaintCnt++;
				else {
					for (int j = 0; j < wrongPaintCnt + 1; j++) {
						ans.push_back(stayPaints[c[i]]);
					}
					wrongPaintCnt = 0;
				}
			}
			else {
				int idx = needPaint[c[i]].front();
				needPaint[c[i]].pop();
				stayPaints.insert({ c[i], idx });
				for (int i = 0; i < wrongPaintCnt; i++) {
					ans.push_back(idx);
				}
				ans.push_back(idx);
				needPaintCnt--;
				wrongPaintCnt = 0;
			}
		}

		if (wrongPaintCnt > 0 || needPaintCnt > 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (auto num : ans) {
				cout << num + 1 << " ";
			}cout << endl;
		}
	}
}