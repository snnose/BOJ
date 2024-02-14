#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
// 1. ť�� ���� ��ġ�� �ְ�
// 2. �� ��ġ���� -1, +1, x2 �ϴ� ��츦 �� ��ġ�� �湮���� ���� ��� ��� ť�� �ִ´�.
// 3. Ž�� �߿� �������� �������� ���������� �� Ƚ���� ����
*/

void B1697Input(int &curr_Pos, int &destination)
{
	cin >> curr_Pos >> destination;
}

int bfs(int curr_Pos, int destination, int visited[])
{
	queue<int> que;
	que.push(curr_Pos);

	while (!que.empty())
	{
		if (curr_Pos == destination)
		{
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			int x = que.front();
			que.pop();

			if (x > 0)
			{
				if (visited[x - 1] == 0)
				{
					que.push(x - 1);
					visited[x - 1] = visited[x] + 1;
				}
			}
			if (x + 1 <= 100000)
			{
				if (visited[x + 1] == 0)
				{
					que.push(x + 1);
					visited[x + 1] = visited[x] + 1;
				}
			}
			if (x * 2 <= 100000 && x != 0)
			{
				if (visited[x * 2] == 0)
				{
					que.push(x * 2);
					visited[x * 2] = visited[x] + 1;
				}
				
			}
		}
	}

	return visited[destination];
}

/*
int main()
{
	int curr_Pos, destination;
	int visited[100001] = { 0, };

	B1697Input(curr_Pos, destination);
	
	int answer = bfs(curr_Pos, destination, visited);

	cout << answer;
	return 0;
}
*/