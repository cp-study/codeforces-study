#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const string res[2] = { "Ayush", "Ashish" };

int graph[1001][1001];
int indegree[1001];
bool deleted[1001];
int n, x;


string solve() {
	int turn = 0;

	// 시작부터 리프노드이면
	if (indegree[x] <= 1)
	{
		return res[turn];
	}

	priority_queue<pair<int, int> > pq;
	for (int i = 1; i <= n; i++)
	{
		pq.push(make_pair(-indegree[i], i));
	}

	while (!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();

		if (node == x)
		{
			turn = 1 - turn;
			break;
		}

		// 제거됨
		if (deleted[node])
		{
			continue;
		}

		// 제거해서 x 가 리프 노드가 되면 제거하면 안됨 
		if (indegree[x] <= 2 && graph[node][x] == 1)
		{
			pq.push(make_pair(-987654321, node));
			continue;
		}

		// 제거
		indegree[node]--;
		for (int i = 1; i <= n; i++)
		{
			if (graph[node][i] == 1)
			{
				indegree[i]--;
				graph[node][i] = 0;
				graph[i][node] = 0;

				// 새로 추가
				pq.push(make_pair(-indegree[i], i));
			}
		}

		deleted[node] = true;

		turn = 1 - turn;
	}

	return res[turn];
}

int main() {
	int t;
	cin >> t;

	while (t--)
	{
		// init
		memset(indegree, 0, sizeof(indegree));
		memset(deleted, false, sizeof(deleted));
		memset(graph, 0, sizeof(graph));

		cin >> n >> x;

		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a][b] = 1;
			graph[b][a] = 1;

			indegree[a]++;
			indegree[b]++;
		}

		cout << solve() << endl;
	}
}
