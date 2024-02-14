/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[101];
int dist[101];
int itemValue[101];

void B14938Input(int &n, int &m)
{
	int r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> itemValue[i];
	}

	int v1, v2, distance;
	for (int i = 0; i < r; i++)
	{
		cin >> v1 >> v2 >> distance;
		edge[v1].emplace_back(make_pair(distance, v2));
		edge[v2].emplace_back(make_pair(distance, v1));
	}
}

void diikstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(dist[start], start));

	while (!pq.empty())
	{
		int current = pq.top().second;
		int currentDist = -pq.top().first;

		pq.pop();
		if (dist[current] < currentDist)
			continue;

		for (int i = 0; i < edge[current].size(); i++)
		{
			int next = edge[current][i].second;
			int nextDist = currentDist + edge[current][i].first;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

void B14938Solution()
{
	int n, m, INF = 1e9;
	int maximum = 0;
	int tmp = 0;
	B14938Input(n, m);

	for (int i = 1; i <= n; i++)
	{
		tmp = 0;
		for (int j = 0; j < 101; j++)
			dist[j] = INF;

		diikstra(i);

		for (int j = 1; j <= n; j++)
		{
			if (dist[j] <= m)
				tmp += itemValue[j];
		}

		maximum = max(maximum, tmp);
	}

	cout << maximum;
}

int main()
{
	B14938Solution();
	return 0;
}
*/