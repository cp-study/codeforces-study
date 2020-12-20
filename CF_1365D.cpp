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
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool dfs(int y, int x, int n, int m, 
	vector<vector<char>>& v,
	vector<vector<bool>>& visited,
	int& Gcnt) {
	if (y <= 0 || x <= 0 || y > n || x > m) {
		return false;
	}
	if (visited[y][x]) return false;
	if (v[y][x] == '#') return false;
	if (v[y][x] == 'G') Gcnt++;

	visited[y][x] = true;
	bool ret = false;
	for (int i = 0; i < 4; i++) {
		ret |= dfs(y + dy[i], x + dx[i], n, m, v,visited, Gcnt);
	}
	return ret;
}

int main() {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> v(n + 1, vector<char>(m + 1));
		vector<pair<int, int>> Bpositions;
		int Gcnt = 0;
		for (int i = 1; i <= n; i++) {
			string input;
			cin >> input;
			cout << "input: " << input << endl;
			for (int j = 1; j <= m; j++) {
				v[i][j] = input[j - 1];
				if (v[i][j] == 'B') {
					Bpositions.push_back({ i,j });
				}
				else if (v[i][j] == 'G') {
					Gcnt++;
				}
			}
		}

		bool isPossible = true;

		for (int i = 0; i < Bpositions.size();i++) {
			int y = Bpositions[i].first;
			int x = Bpositions[i].second;
			for (int k = 0; k < 4; k++) {
				int newY = y + dy[k];
				int newX = x + dx[k];
				if (newY <= 0 || newX <= 0 || newY > n || newX > m)
					continue;
				if (v[newY][newX] == 'G') {
					isPossible = false;
					break;
				}
				else if (v[newY][newX] == '.') {
					v[newY][newX] = '#';
				}
			}
		}

		int cnt = 0;
		vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
		dfs(n, m, n, m,v, visited, cnt);
		if (cnt != Gcnt) isPossible = false;

		if (isPossible) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}