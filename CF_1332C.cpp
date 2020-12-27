#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> checked(n, 0);
		int ans = 0;
		for (int i = 0; i < n/2; i++) {
			if (checked[i]) continue;

			int group_size = 0;
			vector<int> letters(26, 0);

			for (int j = i; j < n; j += k) {
				if (checked[j]) continue;
				letters[s[j] - 'a'] += 1;
				checked[j] = 1;
				group_size += 1;
			}
			for (int j = n - 1 - i; j >= 0; j -= k) {
				if (checked[j]) continue;
				letters[s[j] - 'a'] += 1;
				checked[j] = 1;
				group_size += 1;
			}
			ans += group_size - *max_element(letters.begin(), letters.end());
		}
		cout << ans << '\n';
	}
}
