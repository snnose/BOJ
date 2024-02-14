/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;


// ���� bfs�� ť�� �ٷ� �־ �����ִ� �ݸ�
// �� �˰����� Ž���� ���� Ʈ���� ���Ϳ� �� ���� ��
// ť�� ������ ������� ���� �� Ʈ���� ť�� �־��ش�.


vector<int> tree[101];

void B1389Input(int &N, int &M)
{
	cin >> N >> M;

	int tmp1, tmp2;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;

		tree[tmp1].emplace_back(tmp2);
		tree[tmp2].emplace_back(tmp1);
	}
}

int bfs(int start, bool visited[])
{
	vector<int> tmp;
	queue<int> que;
	int stage = 1;
	int Kevin_Count = 0;

	que.push(start);
	visited[start] = true;

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		int currentSize = tree[current].size();
		for (int i = 0; i < currentSize; i++)
		{
			int next = tree[current][i];
			// �湮���� �ʾҴٸ�
			if (!visited[next])
			{
				// ���Ϳ� ���� Ʈ���� ������ �ְ� �ɺ� ������ ���� �ܰ踸ŭ ������Ų��.
				tmp.emplace_back(next);
				visited[next] = true;
				Kevin_Count += stage;
			}
		}
		// ť�� ����ٸ�
		if (que.empty())
		{
			int size = tmp.size();
			// ���� �� ���� Ʈ�� ������ ť�� �����Ѵ�.
			for (int i = 0; i < size; i++)
				que.push(tmp[i]);
			
			stage++;
			tmp.clear();
		}
	}

	return Kevin_Count;
}

void B1389Solution()
{
	int N, M;
	vector<int> answers;
	bool visited[101] = { false, };

	B1389Input(N, M);

	for (int i = 1; i <= N; i++)
	{
		answers.emplace_back(bfs(i, visited));
		memset(visited, false, sizeof(bool) * 101);
	}

	int min = min_element(answers.begin(), answers.end()) - answers.begin();

	cout <<  min + 1;
}

int main()
{
	B1389Solution();
	return 0;
}
*/