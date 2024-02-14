/*
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int field[1001][1001];
bool visited[1001][1001];
pair<int, int> dir4[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };
int N = 0, M = 0;

void B2206Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			int num = tmp[j] - 48;
			field[i][j] = num;
		}
	}
}

bool isValid(tuple<int, int, int> current, pair<int, int> dir4)
{
	if (get<0>(current) + dir4.first >= 0 && get<0>(current) + dir4.first < N &&
		get<1>(current) + dir4.second >= 0 && get<1>(current) + dir4.second < M)
		return true;
	else
		return false;
}

void bfs(int start_row, int start_col)
{
	queue<tuple<int, int, int>> que;

	que.push(make_tuple(start_row, start_col, 0)); // 0 = row, 1 = col, 2 = isCrush(bool)
	visited[start_row][start_col] = true;
	field[start_row][start_col]++;

	while (!que.empty())
	{
		tuple<int, int, int> current = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			if (isValid(current, dir4[i]))
			{
				tuple<int, int ,int> next = 
					make_tuple(get<0>(current) + dir4[i].first, get<1>(current) + dir4[i].second, get<2>(current));

				// 벽이 아니고 방문한 적이 없다면
				if (field[get<0>(next)][get<1>(next)] == 0 && !visited[get<0>(next)][get<1>(next)])
				{
					visited[get<0>(next)][get<1>(next)] = true;
					que.push(next);
					field[get<0>(next)][get<1>(next)] = field[get<0>(current)][get<1>(current)] + 1;
				}

				// 만약 다음 위치가 벽이고 부순적이 없다면
				if (field[get<0>(next)][get<1>(next)] == 1 && get<2>(next) == 0 && !visited[get<0>(next)][get<1>(next)])
				{
					get<2>(next) = 1; // isCrush = true
					visited[get<0>(next)][get<1>(next)] = true;
					que.push(next);
					field[get<0>(next)][get<1>(next)] = field[get<0>(current)][get<1>(current)] + 1;
					continue;
				}
			}
		}
	}
}

void B2206Solution()
{
	B2206Input();
	bfs(0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << field[i][j] << ' ';
		}
		cout << endl;
	}

	if (field[N - 1][M - 1] == 0)
	{
		cout << -1;
	}
	else
	{
		cout << field[N - 1][M - 1];
	}
}

int main()
{
	B2206Solution();
	return 0;
}
*/