/*
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M; // N = �� M = ��
int field[501][501];
bool visited[501][501] = { false, };
int init[1][1] = { {1} };
pair<int, int> dir4[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) }; // �����¿�
vector<int> answer;

void B14500Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
		}
	}
}

// ���� ��ġ���� ���� ��ġ�� �̵��Ϸ� �� ��, ��ȿ�� �������� �˷��ش�.
bool isInvalidRange(pair<int, int> curr_Pos, pair<int, int> dir)
{
	if (curr_Pos.first + dir.first >= 0 && curr_Pos.first + dir.first < N &&
		curr_Pos.second + dir.second >= 0 && curr_Pos.second + dir.second < M)
	{
		return false;
	}
	else
		return true;
}

int bfs(int start_row, int start_col)
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> tmp; // visited �迭 �ʱ�ȭ�� ���� ����
	int sum;

	que.push(make_pair(start_row, start_col));
	tmp.emplace_back(make_pair(start_row, start_col));
	visited[start_row][start_col] = true;
	sum = field[start_row][start_col];

	for (int i = 0; i < 3; i++)
	{
		pair<int, int> curr_Pos = que.front();
		que.pop();

		pair<int, int> next_Pos;
		pair<int, int> next_Max; // ���� ���� ū ��ġ�� ���� ����
		// �Ǹ�� ó�� (�밡�ٷ� ó���ߴ�)
		// �� �������� ������ ����� ������ ������ �������� �ִ밪�� ã�� ������ ������ ����.
		if (i == 0)
		{
			// ��, ��, ��, �� 4���� ���.
			pair<int, int> up, down, left, right;
			up = make_pair(curr_Pos.first + dir4[0].first, curr_Pos.second + dir4[0].second);
			down = make_pair(curr_Pos.first + dir4[1].first, curr_Pos.second + dir4[1].second);
			left = make_pair(curr_Pos.first + dir4[2].first, curr_Pos.second + dir4[2].second);
			right = make_pair(curr_Pos.first + dir4[3].first, curr_Pos.second + dir4[3].second);

			int sum_tmp = sum;
			// �� �� ��
			if (!isInvalidRange(curr_Pos, dir4[0]))
					sum_tmp += field[up.first][up.second];
			if (!isInvalidRange(curr_Pos, dir4[2]))
					sum_tmp += field[left.first][left.second];
			if (!isInvalidRange(curr_Pos, dir4[1]))
					sum_tmp += field[down.first][down.second];

			if(sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;

			// �� �� ��
			if (!isInvalidRange(curr_Pos, dir4[0]))
					sum_tmp += field[up.first][up.second];
			if (!isInvalidRange(curr_Pos, dir4[3]))
					sum_tmp += field[right.first][right.second];
			if (!isInvalidRange(curr_Pos, dir4[1]))
					sum_tmp += field[down.first][down.second];

			if (sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;

			// �� �� ��
			if (!isInvalidRange(curr_Pos, dir4[2]))
					sum_tmp += field[left.first][left.second];
			if (!isInvalidRange(curr_Pos, dir4[1]))
					sum_tmp += field[down.first][down.second];
			if (!isInvalidRange(curr_Pos, dir4[3]))
					sum_tmp += field[right.first][right.second];

			if (sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;

			// �� �� ��
			if (!isInvalidRange(curr_Pos, dir4[2]))
					sum_tmp += field[left.first][left.second];
			if (!isInvalidRange(curr_Pos, dir4[0]))
					sum_tmp += field[up.first][up.second];
			if (!isInvalidRange(curr_Pos, dir4[3]))
					sum_tmp += field[right.first][right.second];

			if(sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;
		}

		int curr_max = 0;
		for (int j = 0; j < 4; j++)
		{
			if (!isInvalidRange(curr_Pos, dir4[j]))
			{
				next_Pos = make_pair(curr_Pos.first + dir4[j].first, curr_Pos.second + dir4[j].second);
				// �湮���� �ʾҰ� ���� ���� ū ������ ũ�ٸ�
				if (!visited[next_Pos.first][next_Pos.second] &&
					field[next_Pos.first][next_Pos.second] >= curr_max)
				{
					curr_max = field[next_Pos.first][next_Pos.second];
					next_Max = next_Pos;
				}
			}
		}

		// �����¿� 4������ ��� Ž�� �� ���� ū ���� ���� �������� �̵�
		//cout << "next_Max[" << i << "] = " << next_Max.first << ' ' << next_Max.second << endl;
		que.push(next_Max);
		tmp.emplace_back(next_Max);
		visited[next_Max.first][next_Max.second] = true;
		sum += field[next_Max.first][next_Max.second];
	}

	// �̹� Ž���� �湮�� ��ġ���� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < 4; i++)
	{
		visited[tmp[i].first][tmp[i].second] = false;
	}
	tmp.clear();

	return sum;
}

void dfs(int start_row, int start_col)
{

}

void B14500Solution()
{
	B14500Input();
	int max_value = 0;
	int tmp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cout << i << ' ' << j << endl;
			tmp = bfs(i, j);
			if (tmp > max_value)
				max_value = tmp;
		}
	}

	max_value = max(max_value, *max_element(answer.begin(), answer.end()));

	cout << max_value;
}

int main()
{
	B14500Solution();
	return 0;
}
*/