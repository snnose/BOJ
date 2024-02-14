/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[1001];
int dist[1001];
int INF = 1e9;

void B1916Input(int &start, int &end)
{
	int N, M;
	cin >> N >> M;

	int v1, v2, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> cost;
		edge[v1].emplace_back(cost, v2);
	}

	cin >> start >> end;
}
// ���ͽ�Ʈ�� �˰���
void diikstra(int start)
{
	priority_queue<pair<int, int>> pq;
	// ���� ������ ����� 0�̴�.
	dist[start] = 0;
	pq.push(make_pair(0, start)); // first = cost(dist), second = next vertex

	while (!pq.empty())
	{
		// ���� ��θ� �޴´�.
		int current = pq.top().second;
		int current_dist = -pq.top().first;
		pq.pop();
		
		// ���� ��ΰ� �ּ� ��ΰ� �ƴ϶��
		if (current_dist > dist[current])
			continue;

		// ���� ��θ� Ž���Ѵ�.
		int size = edge[current].size();
		for (int i = 0; i < size; i++)
		{
			// ���� ��θ� �޴´�.
			int next = edge[current][i].second;
			int next_dist = current_dist + edge[current][i].first;

			// ���� ��α��� ����� �ּҶ��
			if (dist[next] > next_dist)
			{
				// �����ϰ� �켱���� ť�� �ִ´�.
				dist[next] = next_dist;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}
}

void B1916Solution()
{
	int start, end;
	B1916Input(start, end);

	// �ּ� ��� �迭 �ʱ�ȭ
	for (int i = 0; i < 1001; i++)
		dist[i] = INF;

	// �������� �Ű� ������ �־� �� ��ġ������ �ּ� ��θ� ã�´�.
	diikstra(start);

	// ������������ �ּ� ��θ� ���
	cout << dist[end];
}

int main()
{
	B1916Solution();
	return 0;
}
*/