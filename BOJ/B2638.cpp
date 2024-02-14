/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� ����� ������ ī��Ʈ���� �ʴ� �� ������� �ʾҴ�. �ٽ� �ؾߵ�

int N, M; // N = col, M = row
int field[101][101];
bool visited[101][101] = { false, };
pair<int, int> dir4[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) }; // �����¿�

void B2638Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> field[i][j];
		}
	}
}

// ��ȿ �������� �Ǵ��Ѵ�.
bool isValid(pair<int, int> coord)
{
	if (coord.first >= 0 && coord.first < M &&
		coord.second >= 0 && coord.second < N)
		return true;

	return false;
}


void bfs(int start_row, int start_col)
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> melting;
	vector<pair<int, int>> freezed;
	que.push(make_pair(start_row, start_col));
	visited[start_row][start_col] = true;

	while (!que.empty())
	{
		pair<int, int> current = que.front();
		int melt_count = 0;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(current.first + dir4[i].first, current.second + dir4[i].second);
			// ���� ��ǥ�� ��ȿ �����̰�
			if (isValid(next))
			{
				// ���� 0�̸�
				if (field[next.first][next.second] == 0)
					melt_count++;
				// ���� 1�̸�
				else
				{
					if (!visited[next.first][next.second])
					{
						que.push(next);
						visited[next.first][next.second] = true;
					}
				}
			}
		}

		// ġ� ����� �ȳ���� ó��
		if (melt_count > 1)
			melting.emplace_back(current);
		else
			freezed.emplace_back(current);

		// ġ�� ��ü�� �� Ž���ߴٸ� (ť�� ��ٸ�)
		// ġ� ��� ������ ��� ġ� ã�´�.
		if (que.empty())
		{
			int melt_size = melting.size();
			int freezed_size = freezed.size();
		}
	}
}

void B2638Solution()
{
	B2638Input();
}

int main()
{
	B2638Solution();
}
*/