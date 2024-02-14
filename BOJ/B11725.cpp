/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// bfs�� �ϸ鼭 ���� ��忡�� ���� ���(�ڽ� ���)�� Ž���� ��
// �迭�� ���� ���(�ڽ� ���)�� ���� ���(�θ�)�� ���� ������ش�.

vector<int> tree[100001];
bool visited[100001] = {false, };
int answer[100001] = { 0, };

void B11725Input(int &n)
{
	cin >> n;

	int v1, v2;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> v1 >> v2;
		tree[v1].emplace_back(v2);
		tree[v2].emplace_back(v1);
	}
}

void bfs(int start)
{
	queue<int> que;
	que.push(start);
	visited[start] = true;

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		int size = tree[current].size();
		for (int i = 0; i < size; i++)
		{
			int next = tree[current][i];

			if (!visited[next])
			{
				que.push(next);
				visited[next] = true;
				answer[next] = current;
			}
		}
	}
}

void B11725Solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	B11725Input(n);
	bfs(1);

	for (int i = 2; i <= n; i++)
	{
		cout << answer[i] << "\n";
	}
}

int main()
{
	B11725Solution();
	return 0;
}
*/