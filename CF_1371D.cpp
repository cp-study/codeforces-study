#include <iostream>
#include <cstring>
using namespace std;

int board[300][300];

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		memset(board, 0, sizeof(board));

		int x = 0, y = 0;
		while (k--)
		{
			board[x][y] = 1;
			
			x = (x + 1) % n;
			y = (y + 1) % n;

			if (x == 0)
			{
				y = (y + 1) % n;
			}
		}

		// check
		int maxr = 0, minr = 987654321;
		int maxc = 0, minc = 987654321;

		for (int i = 0; i < n; i++)
		{
			int c = 0;
			for (int j = 0; j < n; j++)
			{
				c += board[i][j];
			}
			maxc = max(maxc, c);
			minc = min(minc, c);
		}

		for (int j = 0; j < n; j++)
		{
			int r = 0;
			for (int i = 0; i < n; i++)
			{
				r += board[i][j];
			}
			maxr = max(maxr, r);
			minr = min(minr, r);
		}

		cout << (maxr - minr) * (maxr - minr) + (maxc - minc) * (maxc - minc) << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
	}
}
