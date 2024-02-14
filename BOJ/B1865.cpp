/*
#include <iostream>
#include <vector>
#include <tuple>

const int INF = 1e9;

using namespace std;

vector<tuple<int, int, int>> field;
vector<string> answer;
int dist[501];
int N, M, W;

void B1865Input()
{
	cin >> N >> M >> W;

	int v1, v2, cost;
	// ���� �Է� (������ ����)
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> cost;
		field.emplace_back(make_tuple(v1, v2, cost));
		field.emplace_back(make_tuple(v2, v1, cost));
	}
	// ��Ȧ �Է� (������ �ִ�)
	for (int i = 0; i < W; i++)
	{
		cin >> v1 >> v2 >> cost;
		field.emplace_back(make_tuple(v1, v2, -cost));
	}
}

void bellman_ford(int start)
{
	dist[start] = 0;
	int size = field.size();

	// ������ ���� - 1(N - 1) ��ŭ �ݺ� -> ���� ����Ŭ ���� ����
	for (int i = 1; i <= N - 1; i++)
	{
		// ������ ����(M) ��ŭ �ݺ�
		for (int j = 0; j < size; j++)
		{
			int curr_start = get<0>(field[j]);
			int curr_end = get<1>(field[j]);
			int curr_dist = get<2>(field[j]);
			
			// �� ���������� �Ÿ�(���)�� ���Ѵ��̸� �н�. �ѹ��̶� ���� �����̸� ���Ѵ밡 �ƴҰ��̴�.
			// -> �ٷ� �Ʒ� ������ ���� ����ó���� �ȴ�. ������ �𸣰ڴ�.
			if (dist[curr_start] == INF)
				continue;
			// ���� ���������� �ּ� �Ÿ��� ã�Ҵٸ� �������ش�.
			if (dist[curr_end] > dist[curr_start] + curr_dist)
				dist[curr_end] = dist[curr_start] + curr_dist;
		}
	}

	// ���� ����Ŭ�� �����ϴ��� Ȯ���Ѵ�. -> N - 1��ŭ �ݺ��� ���ķ� �� �ݺ��ϸ� ���� ����Ŭ �߻�
	// -> �����Ѵٸ� ������ �ð��� �پ�� ä�� ������ �� �ֱ� �����̴�.
	for (int i = 0; i < size; i++)
	{
		int curr_start = get<0>(field[i]);
		int curr_end = get<1>(field[i]);
		int curr_dist = get<2>(field[i]);

		if (dist[curr_start] == INF)
			continue;
	
		// �ּ� �Ÿ��� ���ŵƴٸ�
		if (dist[curr_end] > dist[curr_start] + curr_dist)
		{
			// ���� ����Ŭ�� �����ϴ� ���̴�.
			answer.emplace_back("YES");
			return;
		}
	}
	
	answer.emplace_back("NO");
	return;
}

void B1865Solution()
{
	int T;
	cin >> T;
	while (T--)
	{
		// �Ÿ� ���� �ʱ�ȭ
		for (int i = 0; i < 501; i++)
		{
			dist[i] = INF;
		}

		// ���� ������ �Է����ش�.
		B1865Input();
		bellman_ford(get<0>(field[0]));

		// �ʱ�ȭ
		field.clear();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
	
	return;
}

int main()
{
	B1865Solution();
	return 0;
}
*/