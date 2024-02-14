/*
#include <iostream>
#include <vector>
#include <queue>

// Ư�� ������ ������ ����������.
// 1 -> v1 + v1 -> v2 + v2 -> N �� ���ϸ� �� �� ����.
// �߰�) 1 -> v2 + v2 -> v1 + v1 -> N�� ��쵵 ���

using namespace std;
vector<pair<int, int>> field[801];

void B1504Input(int &N, int &E, int &v1, int &v2)
{
	cin >> N >> E;

	int tmp1, tmp2, dis;
	for (int i = 1; i <= E; i++)
	{
		cin >> tmp1 >> tmp2 >> dis;
		field[tmp1].emplace_back(make_pair(tmp2, dis));
		field[tmp2].emplace_back(make_pair(tmp1, dis));
	}
	
	cin >> v1 >> v2;
}

int diikstra(int start, int end)
{
	int d[801];
	for (int i = 0; i < 801; i++)
	{
		d[i] = 1e9; // infinity;
	}

	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int curr_node = pq.top().first;
		int curr_dist = -pq.top().second;

		pq.pop();

		if (d[curr_node] < curr_dist)
			continue;
		
		int size = field[curr_node].size();
		for (int i = 0; i < size; i++)
		{
			int next = field[curr_node][i].first;
			int next_dist = curr_dist + field[curr_node][i].second;

			if (next_dist < d[next])
			{
				d[next] = next_dist;
				pq.push(make_pair(next, -next_dist));
			}
		}
	}

	return d[end];
}

void B1504Solution()
{
	int N, E, v1, v2; // v1, v2 = �� ���ľ��ϴ� ����
	int min_dist = 0;
	B1504Input(N, E, v1, v2);

	// �ּ� �Ÿ� ���
	min_dist = diikstra(1, v1) + diikstra(v1, v2) + diikstra(v2, N);
	min_dist = min(min_dist, diikstra(1, v2) + diikstra(v2, v1) + diikstra(v1, N));

	// ��θ� ã�� �� ���ų� ������ �������� �ʴ´ٸ�
	if (min_dist >= 1e9 || E == 0)
		min_dist = -1;

	cout << min_dist;
}

int main()
{
	B1504Solution();
	return 0;
}
*/